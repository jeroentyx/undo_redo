#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_

namespace Module2
{
	struct ICommand
	{
		virtual void Execute() = 0;
		virtual void Undo() = 0;
		virtual void Redo() = 0;
		virtual ~ICommand() = default;
	};
}

#endif

