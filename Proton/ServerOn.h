#pragma once

#include "ICommand.h"
#include "TCPServer.h"

namespace Module2
{
	class ServerOn : public ICommand
	{
		TCPServer* m_server;
	public:
		ServerOn(TCPServer* server) :
			m_server(server)
		{
		}

		void Execute() override
		{
			m_server->TurnServerOn();
		}
		void Undo() override
		{
			m_server->TurnServerOff();
		}
		void Redo() override
		{
			m_server->TurnServerOn();
		}
	};
}