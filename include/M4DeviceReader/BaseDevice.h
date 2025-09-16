#pragma once

#include <string>
#include <iostream>
#include <chrono>

using namespace std;

class BaseDevice {

public:

	std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds> lastPacketTime;

	char HexAddress[20];

	string StringHexAddress;

	void setLastPacketUpdateTime();

	virtual void ParseState(char packet[]) = 0;

	virtual int GetFireMode() = 0;

	string toString();

	bool checkIfUnresponsive();

	string GetStringAddress();

	void DeviceMaker(char[]);

	bool GetSafetyInfo();

	int GetAmmoCount();

	bool UsingMainBattery{};
	bool PowerButton{};
	bool Trigger{};
	bool LaserEnabled{};
	bool QuietMode{};
	bool Safety{};
	bool MotorTempWarning{};

	int LaserDuration{};
	int MotorTemperature{};
	int BoltPosition{};
	int CurrentAmmo{};
	int MaxAmmo{};
	int TriggerPosition{};

	char BatteryVoltage{};
	char MainBatteryPercentage{};
	char BackupBatteryPercentage{};

	string StringAddress;
};