#include <iostream>
#include "AdminCommands.h"
#include "CommandManager.h"
#include "TCPServer.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

namespace Module2
{
	void CommandDesign()
	{
		//Construct a TCP Server
		TCPServer *server = new TCPServer();

		//Define all of the Server Commands
		std::shared_ptr<ICommand> c1(new ServerOn(server));
		std::shared_ptr<ICommand> c2(new ServerOff(server));

		//Construct the Command Manager Invoker
		CommandManager* serverManager = new CommandManager();
		
		//do stuff
		serverManager->ServerCommand(c1);
		serverManager->ServerCommand(c1);
		serverManager->ServerCommand(c2);

		serverManager->Undo();
		serverManager->Undo();
		serverManager->Redo();
		serverManager->Redo();

		delete serverManager;
		delete server;
	}
}

int main(int argv,char* args[])
{
	printf("Command Pattern\n");

	Module2::CommandDesign();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}