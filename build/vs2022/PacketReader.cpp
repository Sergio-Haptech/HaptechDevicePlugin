#include "PacketReader.h"
#include "M4Device.h"
#include "DeviceIdentifier.h"
//#include "M2Device.h"
//#include "M17Device.h"
//#include "M18Device.h"
//#include "M240Device.h"
//#include "M249Device.h"
//#include "Mk19Device.h"
#include "Gears.h"

using namespace std;

void StatePacket(ListOfDevices& list, string StringAddress, char CharAddress[8], char(&buffer)[30]) {

    extern bool SafetyEnabled;
    extern string CurrentDevice;
    extern int AmmoCount;
    extern int FireMode;

    shared_ptr<BaseDevice> LatestDevice;

    //If the device is already in our list of connected devices, then the attributes of the device are updated and the packet update time is reset
    if (list.CheckIfAlreadyInTheList(StringAddress)) {
        list.DeviceDictionary.at(StringAddress)->ParseState(buffer);
        list.DeviceDictionary.at(StringAddress)->setLastPacketUpdateTime();
    }
    // If the device is not already in our list of connected devices, then a new device object is made, its attributes defined, and its added to the the list.
    else {
        string DeviceType = FindDeviceType(buffer[9]);

        if (DeviceType == "M4") {
            LatestDevice = make_shared<M4Device>(CharAddress);
        }
    

        if (LatestDevice != NULL) {
            LatestDevice->ParseState(buffer);
            list.DeviceDictionary.insert(pair<string, shared_ptr<BaseDevice>>(StringAddress, LatestDevice));
            //cout << DeviceType << list.DeviceDictionary.at(StringAddress)->GetStringAddress() << " has connected!" << endl;
        }
    }

    if (list.CheckIfAlreadyInTheList(StringAddress)) {
        CurrentDevice = StringAddress;
        AmmoCount = list.DeviceDictionary.at(StringAddress)->GetAmmoCount();
        FireMode = list.DeviceDictionary.at(StringAddress)->GetFireMode();
        SafetyEnabled = list.DeviceDictionary.at(StringAddress)->GetSafetyInfo();
    }
}

void ShotPacket(ListOfDevices& list, string StringAddress) {

    if (list.CheckIfAlreadyInTheList(StringAddress)) {
        extern bool TimeToFire;

        string ShotMessage = "Device " + StringAddress + " has fired!";
        cout << ShotMessage << endl;
        list.DeviceDictionary.at(StringAddress)->setLastPacketUpdateTime();

        TimeToFire = true;
    }
    else {
        cout << "Unexpected shot from " << StringAddress << " received" << endl;
    }
}

void BaseStationID() {
}

void DeviceStatus(string StringAddress, int BaseStation) {
    cout << "Address " << StringAddress << " is paired to COM " << BaseStation;
}

void DeviceDisconnect(string StringAddress) {
    cout << "Disconnection Packet recieved for " << StringAddress << " !" << endl;
}