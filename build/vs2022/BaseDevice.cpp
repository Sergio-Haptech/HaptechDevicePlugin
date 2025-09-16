#include "BaseDevice.h"

using namespace std;
using namespace chrono;

void BaseDevice::setLastPacketUpdateTime() {
	lastPacketTime = time_point_cast<milliseconds>(steady_clock::now());
}

string BaseDevice::toString() {
	return StringAddress;
}

bool BaseDevice::checkIfUnresponsive() {

	time_point<steady_clock, milliseconds> timeNow = time_point_cast<milliseconds>(steady_clock::now());

	duration<double, milli> elapsedTime = timeNow - lastPacketTime;

	if (elapsedTime.count() >= 5000) {
		return true;
	}
	else {
		return false;
	}
}

void BaseDevice::DeviceMaker(char MyHexAddress[]) {

	for (int i = 0; i < sizeof(MyHexAddress); i++)
	{
		this->HexAddress[i] = MyHexAddress[i];
	}

	stringstream ss;
	for (int i = 1; i < 9; i++) {
		ss << setw(2) << setfill('0') << hex << ((int)HexAddress[i] & 0xff);
	}
	string CompletedStringAddress = ss.str();

	this->StringAddress =CompletedStringAddress;

	lastPacketTime = time_point_cast<seconds>(steady_clock::now());
}

string BaseDevice::GetStringAddress() {
	return BaseDevice::StringAddress;
}

bool BaseDevice::GetSafetyInfo() {
	return BaseDevice::Safety;
}

int BaseDevice::GetAmmoCount() {
	return BaseDevice::CurrentAmmo;
}