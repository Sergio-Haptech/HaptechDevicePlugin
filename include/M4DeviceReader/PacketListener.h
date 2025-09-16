#pragma once
#include <winsock2.h>
#include "ListOfDevices.h"
#include <string>

void PacketListener(ListOfDevices& list, SOCKET& MyUDPSocket, sockaddr_in& ServerAddress);