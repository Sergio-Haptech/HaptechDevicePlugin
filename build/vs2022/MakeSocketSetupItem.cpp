#include "SocketSetupHelper.h"
#include "MakeSocketSetupItem.h"


int RunAtComponentOnStart() {

	SocketSetupHelper* mySocketSetupHelper;

	mySocketSetupHelper = new SocketSetupHelper();
	
	mySocketSetupHelper->WinSockSetup();

	return (mySocketSetupHelper->SocketSetupNoArguments());
}