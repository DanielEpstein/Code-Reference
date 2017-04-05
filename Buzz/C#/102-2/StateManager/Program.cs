using ConsoleApplication7.States;

namespace ConsoleApplication7
{
	class Program
	{
		static void Main()
		{
			var manager = new StateManager();
			manager.Run(new MainMenuState(manager));
		}
	}
}
