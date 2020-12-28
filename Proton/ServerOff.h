#pragma once

#include "ICommand.h"
#include "TCPServer.h"

namespace Module2
{
	class ServerOff : public ICommand
	{
		TCPServer* m_server;
	public:
		ServerOff(TCPServer* server) :
			m_server(server)
		{
		}

		void Execute() override
		{
			m_server->TurnServerOff();
		}
		void Undo() override
		{
			m_server->TurnServerOn();
		}
		void Redo() override
		{
			m_server->TurnServerOff();
		}
	};
}