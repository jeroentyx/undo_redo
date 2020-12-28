#pragma once
#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_

#include <stack>
#include <memory>
#include "ICommand.h"

namespace Module2
{
	typedef std::stack<std::shared_ptr<ICommand>> m_commandStack;

	class CommandManager
	{
		m_commandStack m_UndoStack;
		m_commandStack m_RedoStack;

	public:
		CommandManager();
		~CommandManager();

		void Undo();
		void Redo();
		void ServerCommand(std::shared_ptr<ICommand> command);

	private:
		void ProcessCommand(std::shared_ptr<ICommand> command);
	};

}

#endif // 
