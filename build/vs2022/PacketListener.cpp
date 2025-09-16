#include <sstream>
#include <iomanip>
#include "PacketListener.h"
#include "PacketReader.h"

using namespace std;


void PacketListener(ListOfDevices& list, SOCKET& MyUDPSocket, sockaddr_in& ServerAddress) {

    int clientLength = sizeof(ServerAddress);

    //The values that dictate if a packet is a state or shot packet
    int statePacketNumber = 1;
    int shotPacketNumber = 83;
    int statusPacketNumber = 162;

    //The values that dictate the type of status packet
    int baseStationID = 96;
    int deviceStatus = 97;
    int deviceDisconnect = 98;

    //while (true) {

        //Make a buffer to hold UDP packets and fill it with 0's
    char buff[30];
    ZeroMemory(buff, 30);

    //use select() to catch when there is no longer any data to read
    fd_set rfd;
    FD_ZERO(&rfd);
    FD_SET(MyUDPSocket, &rfd);
    timeval p;
    p.tv_sec = 0;
    p.tv_usec = 5000;

    SOCKET recval = select(0, &rfd, NULL, NULL, &p);

    //if a value is returned for recval, then continue the program like normal
    if (recval) {
        int bytesin = recvfrom(MyUDPSocket, buff, 30, 0, (sockaddr*)&ServerAddress, &clientLength);

        //check to see if the packet was succesfully stored into the buffer
        if (bytesin == SOCKET_ERROR) {
            cout << "Error, recieving from client" << WSAGetLastError << endl;
        }

        //Take in first byte of packet to determine if packet received is state or packet
        int packetType = (int)buff[0];

        /*
        char zero = buff[0];
        cout << "Byte 0: " << bitset<8>(zero).to_string() << endl;

        char one = buff[1];
        cout << "Byte 1: " << bitset<8>(one).to_string() << endl;

        char two = buff[2];
        cout << "Byte 2: " << bitset<8>(two).to_string() << endl;

        char three = buff[3];
        cout << "Byte 3: " << bitset<8>(three).to_string() << endl;

        char four = buff[4];
        cout << "Byte 4: " << bitset<8>(four).to_string() << endl;

        char five = buff[5];
        cout << "Byte 5: " << bitset<8>(five).to_string() << endl;

        char six = buff[6];
        cout << "Byte 6: " << bitset<8>(six).to_string() << endl;

        char seven = buff[7];
        cout << "Byte 7: " << bitset<8>(seven).to_string() << endl;

        char eight = buff[8];
        cout << "Byte 8: " << bitset<8>(eight).to_string() << endl;

        char nine = buff[9];
        cout << "Byte 9: " << bitset<8>(nine).to_string() << endl;

        char ten = buff[10];
        cout << "Byte 10: " << bitset<8>(ten).to_string() << endl;

        char eleven = buff[11];
        cout << "Byte 11: " << bitset<8>(eleven).to_string() << endl;

        char twelve = buff[12];
        cout << "Byte 12: " << bitset<8>(twelve).to_string() << endl;

        char thirteen = buff[13];
        cout << "Byte 13: " << bitset<8>(thirteen).to_string() << endl;

        char fourteen = buff[14];
        cout << "Byte 14: " << bitset<8>(fourteen).to_string() << endl;

        char fifteen = buff[15];
        cout << "Byte 15: " << bitset<8>(fifteen).to_string() << endl;

        char sixteen = buff[16];
        cout << "Byte 16: " << bitset<8>(sixteen).to_string() << endl;

        char seventeen = buff[17];
        cout << "Byte 17: " << bitset<8>(seventeen).to_string() << endl;

        char eighteen = buff[18];
        cout << "Byte 18: " << bitset<8>(eighteen).to_string() << endl;

        char nineteen = buff[19];
        cout << "Byte 19: " << bitset<8>(nineteen).to_string() << endl;

        char twenty = buff[20];
        cout << "Byte 20: " << bitset<8>(twenty).to_string() << endl;
        */


        //Take in the array that contains the Hex Address and convert into a string
        stringstream ss;
        for (int i = 1; i < 9; i++) {
            ss << setw(2) << setfill('0') << hex << ((int)buff[i] & 0xff);
        }
        string StringAddress = ss.str();

        //If the packet is a state packet, then we check if the device sending it is already in our list of connected devices 
        if (packetType == statePacketNumber) {

            //Take in the 8 bytes of Hex Address into an array
            char CharAddress[8];
            ZeroMemory(CharAddress, 8);
            for (int i = 0; i < 8; i++) {
                CharAddress[i] = buff[i + 1];
            }

            StatePacket(list, StringAddress, CharAddress, buff);
        }

        //If the packet is a short packet, then the address of the device that sent the packet is printed, along with a short message about a shot being fired. Packet update time reset as well.
        else if (packetType == shotPacketNumber) {
            ShotPacket(list, StringAddress);
        }

        //If the packet is a status packet, then the appropriate action is taken based on the type of status packet received
        else if (packetType == statusPacketNumber) {

            int StatusPacketType = buff[1];

            if (StatusPacketType == baseStationID) {
                BaseStationID();
            }

            else if (StatusPacketType == deviceStatus) {
                DeviceStatus(StringAddress, int(buff[10]));
            }
            else if (StatusPacketType == deviceDisconnect) {
                DeviceDisconnect(StringAddress);
            }
        }

        //If some other packet is received, then a short message is printed
        else {
            cout << "Packet of unknown type has been received!" << endl;
        }

        //Check for Unresponsive Devices (devices that have not sent a packet for five or more seconds)
        list.CheckForUnresponsiveDevices();

        //Remove any Unrepsonsive devices from our list of registered devices
        list.DeleteUnresponsiveDevices();
        //}

    }

    
    else {
        //Check for Unresponsive Devices (devices that have not sent a packet for five or more seconds)
        list.CheckForUnresponsiveDevices();

        //Remove any Unrepsonsive devices from our list of registered devices
        list.DeleteUnresponsiveDevices();
        
    }
}