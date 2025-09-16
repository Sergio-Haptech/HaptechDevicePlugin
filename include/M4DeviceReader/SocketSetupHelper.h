#pragma once

#include <WinSock2.h>

class SocketSetupHelper {

public:

	SOCKET mySocket;

	sockaddr_in myServerAddress;

	int WinSockSetup();

	int SocketSetup(SOCKET& MYUDPSocket, sockaddr_in& ServerAddress);

	int SocketSetupNoArguments();

};