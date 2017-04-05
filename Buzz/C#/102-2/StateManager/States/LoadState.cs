using System;
using ConsoleApplication7.Abstract;
using ConsoleApplication7.Commands;

namespace ConsoleApplication7.States
{
	class LoadState : IState
	{
		private StateManager _manager;
		private IState _lastState;

		public LoadState(StateManager manager, IState LastState)
		{
			_manager = manager;
			_lastState = LastState;
		}

		public void Render()
		{
			Console.WriteLine("[back] - go back a screen");
		}

		public ICommand GetCommand()
		{
			var input = Console.ReadLine();
			if (input == "back")
			{
				return new SwitchStateCommand(_manager, _lastState);
			}
			return new InvalidCommand();
		}
	}
}