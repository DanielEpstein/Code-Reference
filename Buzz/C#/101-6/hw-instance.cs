using System;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication13
{
	enum State
	{
		MainMenu,
		AddItem,
		RemoveItem,
		DisplayItems,
		Exit
	}

	class Program
	{
		static void Main()
		{
			List<string> productNames = new List<string>();
			List<string> productPrices = new List<string>();
			LoadProducts(productNames, productPrices);

			// state machine
			State state = State.MainMenu;
			while (state != State.Exit)
			{
				switch (state)
				{
					case State.MainMenu: state = MainMenu(); break;
					case State.DisplayItems: state = DisplayItems(productNames, productPrices); break;
					case State.AddItem: state = AddItem(productNames, productPrices); break;
					case State.RemoveItem: state = RemoveItem(productNames, productPrices); break;
				}
			}
			SaveProducts(productNames, productPrices);
		}

		private static void LoadProducts(List<string> productNames, List<string> productPrices)
		{
			try
			{
				// runs streamReader.Dispose() which closes the handles streamReader.Close()
				using (StreamReader streamReader = new StreamReader("inventory.txt"))
				{
					string line;
					bool odd = true;

					while ((line = streamReader.ReadLine()) != null)
					{
						if (odd == true)
						{
							productNames.Add(line);
							odd = false;
						}
						else
						{
							productPrices.Add(line);
							odd = true;
						}
					}
				}
			}

			catch (FileNotFoundException)
			{
				Console.WriteLine("inventory.txt not found, creating new");

				using (StreamWriter streamWriter = new StreamWriter("inventory.txt"))
				{

				}
			}
		}

		private static void SaveProducts(List<string> productNames, List<string> productPrices)
		{
			using (StreamWriter streamWriter = new StreamWriter("inventory.txt"))
			{
				for (int i = 0; i < productNames.Count; i++)
				{
					streamWriter.WriteLine(productNames[i]);
					streamWriter.WriteLine(productPrices[i]);
				}
				Console.WriteLine("saving products");
				Console.ReadKey();
			}
		}

		private static State AddItem(List<string> productNames, List<string> productPrices)
		{
			Console.Write("product name: ");
			productNames.Add(Console.ReadLine());
			Console.Write("product price: ");
			productPrices.Add(GetDouble().ToString());
			return State.MainMenu;
		}

		private static State RemoveItem(List<string> productNames, List<string> productPrices)
		{
			int index = productNames.IndexOf(Console.ReadLine());
			if (index > -1)
			{
				productPrices.RemoveAt(index);
				productNames.RemoveAt(index);
			}
			else
			{
				Console.WriteLine("product not found");
			}
			return State.MainMenu;
		}

		private static State DisplayItems(List<string> productNames, List<string> productPrices)
		{
			Console.WriteLine("------------------------------------------------");
			for (int i = 0; i < productNames.Count; i++)
			{
				Console.WriteLine(productNames[i] + " " + productPrices[i]);
			}
			Console.WriteLine("------------------------------------------------");
			return State.MainMenu;
		}

		private static State MainMenu()
		{
			Console.WriteLine(" 1 - Display Items");
			Console.WriteLine(" 2 - Add Item");
			Console.WriteLine(" 3 - Remove Item");
			Console.WriteLine(" 4 - Save and Exit");
			Console.Write(">");

			switch (GetIntRange(1, 4))
			{
				case 1: return State.DisplayItems;
				case 2: return State.AddItem;
				case 3: return State.RemoveItem;
				case 4: return State.Exit;
				default: return State.MainMenu;
			}
		}

		private static int GetIntRange(int left, int right)
		{

			int validint;
			bool validinput;

			while (true)
			{
				string input = Console.ReadLine();
				validinput = int.TryParse(input, out validint);
				if (!validinput || validint < left || validint > right)
				{
					Console.WriteLine("Invaild Input, Please enter a number between 1-4");
					Console.Write(">");
				}
				else
				{
					return validint;
				}
			}
		}

		private static double GetDouble()
		{
			double validdouble;
			bool validinput;
			while (true)
			{
				string input = Console.ReadLine();
				validinput = double.TryParse(input, out validdouble);
				if (!validinput)
				{
					Console.WriteLine("Invalid Input, Please enter a number");
				}
				else
				{
					return validdouble;
				}
			}
		}
	}
}
