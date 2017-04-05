using System;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication6
{
	class Program
	{
		static void Main()
		{
			// FileInfo
			// DirectoryInfo
			// Directory
			// File

			var users = new List<string>();
			users.Add("Nelson");
			users.Add("Whoa");
			users.Add("Hey");

			foreach (var user in users)
			{
				for (var i = 0; i < 5; i++)
				{
					Directory.CreateDirectory(string.Format("{0}/Week {1}", user, i));
				}
			}

			if (!Directory.Exists("Test"))
			{
				Directory.CreateDirectory("Test");
			}

			// File.Move("test.txt", "test2.txt");

			var directoryInfo = new DirectoryInfo("c:\\");
			Console.WriteLine("Files:");
			foreach (FileInfo info in directoryInfo.GetFiles())
			{
				Console.WriteLine("{0} - {1}", info.Name, info.Length);	
			}
			Console.WriteLine("\nDirectories:");
			foreach (DirectoryInfo info in directoryInfo.GetDirectories())
			{
				Console.WriteLine("{0}", info.Name);	
			}

			Console.ReadKey();
		}
	}
}
