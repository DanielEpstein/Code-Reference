using System;
using System.Collections.Generic;

namespace ConsoleApplication6
{
	interface IItem
	{
		string Name { get; }
	}

	interface IMovable
	{
		void Move();
	}

	interface IBuyable
	{
		decimal Price { get; }
		void Buy();
	}

	class Car : IItem, IMovable, IBuyable
	{
		public decimal Price { get; private set; }
		public string Name { get; private set; }

		public Car(string name, decimal price)
		{
			Price = price;
			Name = name;
		}
		
		public void Buy()
		{
			Console.WriteLine("You bought a car for {0}",
				Price);
		}

		public void Move()
		{
			Console.WriteLine("VROOOOOOOM");
		}
	}

	class Chair : IItem, IMovable
	{
		public string Name { get; private set; }
		
		public Chair (string name)
		{
			Name = name;
		}
	
		public void Move()
		{
			Console.WriteLine("Moving the {0} chair!", Name);
		}
	}
	
	class Giraffe : IItem
	{
		public string Name { get; private set; }
		
		public Giraffe(string name)
		{
			Name = name;
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			var items = new List<IItem>();
			items.Add(new Car("Stuff", 32.45m));
			items.Add(new Chair("Awesome"));
			items.Add(new Car("And", 23.4526m));
			items.Add(new Car("Things", 32.432423m));
			items.Add(new Chair("Comfy"));
			items.Add(new Giraffe("STUFF"));



			while (true)
			{
				var chosenItem = ChooseItem(items);

				var movable = chosenItem as IMovable;
				var buyable = chosenItem as IBuyable;

				Console.Write("What do you want to do: ");
				var input = Console.ReadLine();

				if (movable != null && input == "move")
				{
					movable.Move();
				}
				else if (buyable != null && input == "buy")
				{
					buyable.Buy();
				}
				else
				{
					Console.WriteLine("Invalid Choice!");
				}

				Console.WriteLine("Press any key to continue");
				Console.ReadKey();
			}
		}

		static IItem ChooseItem(List<IItem> items)
		{
			while (true)
			{
				Console.WriteLine("-------------------------------");


				var index = 1;
				foreach (IItem item in items)
				{
					Console.Write("[{0}] - {1} ", index, item.Name);

					IBuyable buyable = item as IBuyable;
					if (buyable != null)
					{
						Console.Write("- costs {0}", buyable.Price);
					}

					if (item is IMovable)
					{
						Console.Write("- can move");
					}

					Console.WriteLine();

					index++;
				}

				Console.Write("Choose item: ");
				var itemIndex = int.Parse(Console.ReadLine());
				
				if (itemIndex <= 0 || itemIndex > items.Count)
				{
					Console.WriteLine("You are dumb");
					continue;
				}

				return items[itemIndex - 1];
			}
		}
	}
}
