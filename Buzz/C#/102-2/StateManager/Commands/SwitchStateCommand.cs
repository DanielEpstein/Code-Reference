using ConsoleApplication7.Abstract;

namespace ConsoleApplication7.Commands
{
	class SwitchStateCommand : ICommand
	{
		private StateManager _manager;
		private IState _newState;

		public SwitchStateCommand(StateManager manager, IState newState)
		{
			_manager = manager;
			_newState = newState;
		}

		public void Execute()
		{
			_manager.SwitchState(_newState);
		}
	}
}