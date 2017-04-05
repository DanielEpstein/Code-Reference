using System;
using ConsoleApplication7.Abstract;

namespace ConsoleApplication7
{
	class InvalidCommand : ICommand
	{
		public void Execute()
		{
			Console.WriteLine("Invalid Command");
		}
	}
}