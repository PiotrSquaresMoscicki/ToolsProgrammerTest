#pragma once

#include <vector>

#include "Managers/ICommandsManager.hpp"
#include "Structures/Commands/BlankCommand.hpp"

namespace TPT
{
	enum class eCommandType
	{
		EXECUTE,
		UNDO,
		REDO
	};

	class CommandsManager : public ICommandsManager
	{
	public:
		CommandsManager();

		void AddCommand(std::unique_ptr<ICommand> cmd) override;

		void Undo() override;
		void Redo() override;

	private:
		bool InitialCommand = true;
		eCommandType LastCommandType = eCommandType::EXECUTE;
		size_t CommandIdx = 0;
		
		std::vector<std::unique_ptr<ICommand>> Commands;
	};
}