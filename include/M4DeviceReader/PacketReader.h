#pragma once
#include <string>
#include "ListOfDevices.h"

void StatePacket(ListOfDevices& list, std::string StringAddress, char CharAddress[8], char(&buffer)[30]);

void ShotPacket(ListOfDevices& list, std::string StringAddress);

void BaseStationID();

void DeviceStatus(std::string StringAddress, int BaseStation);

void DeviceDisconnect(std::string StringAddress);
