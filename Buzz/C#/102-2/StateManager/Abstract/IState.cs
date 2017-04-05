namespace ConsoleApplication7.Abstract
{
	interface IState
	{
		void Render();
		ICommand GetCommand();

	}
}