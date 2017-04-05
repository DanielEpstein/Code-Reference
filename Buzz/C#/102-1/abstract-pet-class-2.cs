using System;
using System.Collections.Generic;


// Create an abstract Pet class that has abstract functionality (at least 3 methods). It must have a
// "string Name" read-only property that is filled by a paramater to the ctor. At least one of the
// methods must take in paramaters, and at least one of the methods must return a value instead of 
// printing things to the console.
// 
// Create four implementations of the Pet class that all appropriately implement the different methods.
// 
// Once the user is done entering in pets, allow the user to
// A) select a pet
// B) perform an operation
// 	- You will have to collect the arguments from the user requred to invoke a method that has paramaters.
// C) Repeat A-B until the user decides to quit

namespace HomeWork___abstract_pet_class
{
	class Program
	{
		abstract class Pet
		{
			public string Name { get; private set; }

			public Pet(string name)
			{
				Name = name;
			}

			public virtual string MoveLeft()
			{
				return string.Format("{0} moves Left.", Name);
			}
			public virtual string MoveBackwards()
			{
				return Name + " moves Backwards."; 
			}
			public virtual string MoveForward()
			{
				return Name + " moves forward.";
			}

			public virtual string MoveRight()
			{
				return Name + " moves right.";
			}

			public void DisplayName()
			{
				Console.WriteLine(Name);
			}
		}

		class Cat : Pet
		{
			public Cat(string name) : base(name)
			{
			}
			public override string MoveForward()
			{
				return Name + " the cat jumps forward.";
			}
		}

		class Dog : Pet
		{
			public Dog(string name) : base(name)
			{
			}

			public override string MoveForward()
			{
				return Name + " the dog jumps forward.";
			}
		}

		class Fish : Pet
		{
			public Fish(string name) : base(name)
			{
			}
			public override string MoveForward()
			{
				return Name + " the fish jumps forward.";
			}
		}

		class Bird : Pet
		{
			public Bird(string name) : base(name)
			{
			}
			public override string MoveForward()
			{
				return Name + " the bird jumps forward.";
			}
		}

		static class input
		{
			public static int GetInt(string promptquestion)
			{
				while (true)
				{
					Console.Write(promptquestion + Prompt());
					string input = Console.ReadLine();
					int vaildint;
					if (!int.TryParse(input, out vaildint))
					{
						Console.WriteLine(" Invalid Input, not an int");
					}
					else
					{
						return vaildint;
					}
				}
			}

			public static int GetInt(string promptquestion, int left, int right)
			{
				while (true)
				{
					Console.Write(promptquestion + Prompt());
					string input = Console.ReadLine();
					int vaildint;
					if (!int.TryParse(input, out vaildint))
					{
						Console.WriteLine(" Invalid Input, not an int");
					}
					else if (vaildint < left || vaildint > right)
					{
						Console.WriteLine(" Invalid Input, not range of {0}-{1}", left, right);
					}
					else
					{
						return vaildint;
					}
				}
			}

			public static string GetString(string promptquestion)
			{
				Console.Write(promptquestion + Prompt());
				return Console.ReadLine();
			}

			static string Prompt()
			{
				return "> ";
			}

		}

		public class Menu
		{
			List<int> MenuName = new List<int>();


			public Menu(List<string> MenuList)
			{


			}
		}



		static void Main()
		{
			List<Pet> Pets = new List<Pet>();
			int NumberOfPets = input.GetInt(" How many pets would you like?");

			for (int i = 0; i < NumberOfPets; i++)
			{
				Console.WriteLine(" 1 Cat");
				Console.WriteLine(" 2 Dog");
				Console.WriteLine(" 3 Bird");
				Console.WriteLine(" 4 Fish");

				switch (input.GetInt(" Please select a type 1-4", 1, 4))
				{
					case 1: Pets.Add(new Cat(input.GetString(" Please enter a Cat name"))); break;
					case 2: Pets.Add(new Dog(input.GetString(" Please enter a Dog name"))); break;
					case 3: Pets.Add(new Bird(input.GetString(" Please enter a Bird name"))); break;
					case 4: Pets.Add(new Fish(input.GetString(" Please enter a Fish name"))); break;
				}
			}

			int index = 1;
			foreach (Pet pet in Pets)
			{
				Console.WriteLine(string.Format(" {0} {1}", index, pet.Name));
				
				index++;
			}



			
			// 
			// foreach (Pet Pet in Pets)
			// {
			// 	Console.WriteLine(Pet.MoveForward());
			// 	Console.WriteLine(Pet.MoveBackwards());
			// 	Console.WriteLine(Pet.MoveLeft());
			// 	Console.WriteLine(Pet.MoveRight());
			// }

			Console.WriteLine();
			Console.WriteLine("End of Program");
			Console.ReadKey();
		}

	}
}
