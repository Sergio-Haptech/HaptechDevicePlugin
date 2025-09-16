#pragma once

#include "BaseDevice.h"

class M4Device : public BaseDevice {

public:

	M4Device(char HexAddress[]);

	void ParseState(char packet[]) override;

	int GetFireMode() override;

	bool WillJamUnclearable;
	bool JammedUnclearable;
	bool JammedClearable;
	bool WillJamClearable;
	bool BatteryError;

	bool LockedBack;
	bool Chambered;
	bool OnAuto;
	bool OnSemi;
	bool BoltCatch;
	bool MagRelease;

	bool PowerStageTempWarning;
	bool Hammer;
	bool RandomJams;
	bool AccelerometerEnabled;

};
