using System;
using ConsoleApplication7.Abstract;

namespace ConsoleApplication7.Commands
{
	class HelpCommand : ICommand
	{

		public void Execute()
		{
			Console.WriteLine("HELP!");
		}
	}
}