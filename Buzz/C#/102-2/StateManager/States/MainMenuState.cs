using System;
using ConsoleApplication7.Abstract;
using ConsoleApplication7.Commands;

namespace ConsoleApplication7.States
{
	class MainMenuState : IState
	{
		private StateManager _manager;

		public MainMenuState(StateManager manager)
		{
			_manager = manager;
		}

		public void Render()
		{
			Console.WriteLine("[save] - save game");
			Console.WriteLine("[load] - load game");
			Console.WriteLine("[help] - show help");
		}

		public ICommand GetCommand()
		{
			var command = Console.ReadLine();
			if (command == "load")
			{
				return new SwitchStateCommand(_manager, new LoadState(_manager, this));
			}
			if (command == "save")
			{
				return new SwitchStateCommand(_manager, new SaveState(_manager, this));
			}
			if (command == "help")
			{
				return new HelpCommand();
			}

			return new InvalidCommand();
		}
	}
}