#include "ListOfDevices.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

bool ListOfDevices::CheckIfAlreadyInTheList(string address) {

	BorrowList.lock();
	if (this->DeviceDictionary.find(address) != this->DeviceDictionary.end())
	{
		BorrowList.unlock();
		return true;
	}
	else
	{
		BorrowList.unlock();
		return false;
	}
}

void ListOfDevices::CheckForUnresponsiveDevices() {
	BorrowList.lock();
	if (DeviceDictionary.empty()) {
	}
	else {
		for (auto itr = DeviceDictionary.begin(); itr != DeviceDictionary.end(); ++itr) {
			if (itr->second->checkIfUnresponsive()) {
				DeleteList.push_back(itr->first);
			}
		}
	}
	BorrowList.unlock();
}

void ListOfDevices::DeleteUnresponsiveDevices() {
	BorrowList.lock();
	if (DeleteList.empty()) {
	}
	else {
		for (string const& i : DeleteList) {
			cout << "Device: " << i << " has disconnected!" << endl;
			DeviceDictionary.erase(i);
		}
	}
	DeleteList.clear();
	BorrowList.unlock();
}