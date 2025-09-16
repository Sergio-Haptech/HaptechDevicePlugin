#include "DeviceIdentifier.h"

using namespace std;

string FindDeviceType(char DeviceID) {
	if (DeviceID == M4DeviceNumber) {
		return "M4";
	}
	/*
	else if (DeviceID == M249DeviceNumber) {
		return "M249";
	}
	else if (DeviceID == M240DeviceNumber) {
		return "M240";
	}
	else if (DeviceID == M2DeviceNumber) {
		return "M2";
	}
	else if (DeviceID == Mk19DeviceNumber) {
		return "Mk19";
	}
	else if (DeviceID == M17DeviceNumber) {
		return "M17";
	}
	else if (DeviceID == M18DeviceNumber) {
		return "M18";
	}
	*/
	else {
		return "not a recognized device";
	}
}