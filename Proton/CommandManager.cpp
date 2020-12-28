#include "CommandManager.h"

namespace Module2
{
	CommandManager::CommandManager()
	{
		//Empty
	}
	CommandManager::~CommandManager()
	{
	}

	void CommandManager::Undo()
	{
		if (m_UndoStack.size() <= 0)
		{
			return;
		}

		m_UndoStack.top()->Undo();
		m_RedoStack.push(m_UndoStack.top());
		m_UndoStack.pop();
	}
	void CommandManager::Redo()
	{
		if (m_RedoStack.size() <= 0)
		{
			return;
		}

		m_RedoStack.top()->Redo();
		m_UndoStack.push(m_RedoStack.top());
		m_RedoStack.pop();
	}

	void CommandManager::ServerCommand(std::shared_ptr<ICommand> command)
	{
		ProcessCommand(command);
	}

	void CommandManager::ProcessCommand(std::shared_ptr<ICommand> command)
	{
		
		command->Execute();
		m_UndoStack.push(command);
	}
}