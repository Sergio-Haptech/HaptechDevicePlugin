#pragma once

#include "BaseDevice.h"
#include <map>
#include <list>
#include <string>
#include <mutex>


class ListOfDevices {

public:

	std::map<std::string, std::shared_ptr<BaseDevice>> DeviceDictionary;
	std::list<std::string> DeleteList;
	bool CheckIfAlreadyInTheList(std::string address);
	void CheckForUnresponsiveDevices();
	void DeleteUnresponsiveDevices();
	std::mutex BorrowList;
};