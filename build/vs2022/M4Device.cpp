#include "M4Device.h"

using namespace std;
using namespace chrono;

M4Device::M4Device(char HexAddress[]) {

	//M4 Specific attributes
	RemedialMalfunction = false;
	ImmediateMalfunction = false;
	ChargingHandlePulled = false;
	BatteryError = false;

	LockedBack = false;
	Chambered = false;
	OnAuto = false;
	OnSemi = false;
	BoltCatch = false;
	MagRelease = false;

	PowerStageTempWarning = false;
	Hammer = false;
	RandomJams = false;
	AccelerometerEnabled = false;

}


void M4Device::ParseState(char packet[]) {

	RemedialMalfunction = ((0x01 << 6) & packet[10]) > 0;
	ImmediateMalfunction = ((0x01 << 5) & packet[10]) > 0;
	PowerButton = ((0x01 << 3) & packet[10]) > 0;
	ChargingHandlePulled = ((0x01 << 2) & packet[10]) > 0;
	DummyRound = ((0x01 << 1) & packet[10]) > 0;
	BatteryError = (0x01 & packet[10]) > 0;

	LockedBack = ((0x01 << 7) & packet[11]) > 0;
	Chambered = ((0x01 << 6) & packet[11]) > 0;
	UsingMainBattery = ((0x01 << 5) & packet[11]) > 0;
	OnAuto = ((0x01 << 4) & packet[11]) > 0;
	OnSemi = ((0x01 << 3) & packet[11]) > 0;
	BoltCatch = ((0x01 << 2) & packet[11]) > 0;
	MagRelease = ((0x01 << 1) & packet[11]) > 0;
	Trigger = (packet[11] & 0x01) > 0;

	BoltPosition = (int)static_cast<unsigned char>(packet[12]);

	CurrentAmmo = (int)static_cast<unsigned char>(packet[13]);

	PowerStageTempWarning = ((0x01 << 7) & packet[14]) > 0;
	MotorTemperature = (packet[14] & 0x7f);

	LaserEnabled = ((0x01 << 7) & packet[15]) > 0;
	LaserDuration = (packet[15] & 0x7f);

	Safety = ((0x01 << 4) & packet[16]) > 0;
	Hammer = ((0x01 << 3) & packet[16]) > 0;
	RandomJams = ((0x01 << 2) & packet[16]) > 0;
	QuietMode = ((0x01 << 1) & packet[16]) > 0;
	AccelerometerEnabled = (packet[16] & 0x01) > 0;

	MaxAmmo = (int)static_cast<unsigned char>(packet[17]);

	TriggerPosition = (int)static_cast<unsigned char>(packet[18]);

	MainBatteryPercentage = packet[19];

	BackupBatteryPercentage = packet[20];
}

int M4Device::GetFireMode() {
	if (OnSemi == true) {
		return 0;
	}
	else {
		return 1;
	}
}