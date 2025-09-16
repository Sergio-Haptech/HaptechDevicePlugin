#include "SocketSetupHelper.h"
#include <iostream>
#include <thread>
#include <PacketListener.h>

using namespace std;
 
	
	SOCKET mySocket;
	sockaddr_in myServerAddress;


	int SocketSetupHelper::WinSockSetup() {

		WSADATA data;
		WORD version = MAKEWORD(2, 2);
		int WSOK = WSAStartup(version, &data);

		return WSOK;

	}


	int SocketSetupHelper::SocketSetup(SOCKET& MYUDPSocket, sockaddr_in& ServerAddress) {

		ServerAddress.sin_addr.s_addr = ADDR_ANY;

		ServerAddress.sin_family = AF_INET;

		u_short HaptechManagerDefaultPort = 64801;

		ServerAddress.sin_port = htons(HaptechManagerDefaultPort);

		MYUDPSocket = socket(AF_INET, SOCK_DGRAM, 0);

		if (bind(MYUDPSocket, (sockaddr*)&ServerAddress, sizeof(ServerAddress)) == SOCKET_ERROR) {
			return SOCKET_ERROR;
		}

		return 1;

	}

	int SocketSetupHelper::SocketSetupNoArguments() {

		u_short HaptechManagerDefaultPort = 64801;

		this->myServerAddress.sin_addr.s_addr = ADDR_ANY;

		this->myServerAddress.sin_family = AF_INET;

		this->myServerAddress.sin_port = htons(HaptechManagerDefaultPort);

		this->mySocket = socket(AF_INET, SOCK_DGRAM, 0);

		if (bind(mySocket, (sockaddr*)&(this->myServerAddress), sizeof(this->myServerAddress)) == SOCKET_ERROR) {
			return SOCKET_ERROR;
		}
		return 1;
	}