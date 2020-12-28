#pragma once
#include <iostream>

namespace Module2
{
	class TCPServer
	{
	public:
		void TurnServerOn()
		{
			std::cout << "Server is now On" << std::endl;
		}

		void TurnServerOff()
		{
			std::cout << "Server has Shutdown" << std::endl;
		}
	};
}