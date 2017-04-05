using System;
using System.Collections.Generic;

namespace ConsoleApplication5
{
	abstract class Item
	{
		public abstract void Display();
		public abstract void Use();

		public void Blegh()
		{
			Console.WriteLine("I am a item action thing");
		}
	}

	class Chair : Item
	{
		private string _model;

		public Chair(string model)
		{
			_model = model;
		}
		public override void Display()
		{
			Console.WriteLine("Chair, model: {0}", _model);
		}

		public override void Use()
		{
			Console.WriteLine("You sat down!");
		}
	}

	class Potion : Item
	{
		private string _type;

		public Potion(string type)
		{
			_type = type;
		}
		public override void Display()
		{
			Console.WriteLine("Potion, model: {0}", _type);
		}

		public override void Use()
		{
			Console.WriteLine("You drank the potion!");
		}
	}

	class Gun : Item
	{
		private string _type;

		public Gun(string type)
		{
			_type = type;
		}
		public override void Display()
		{
			Console.WriteLine("Gun, model: {0}", _type);
		}

		public override void Use()
		{
			Console.WriteLine("BANG!");
		}
		public void Shoot()
		{
			Console.WriteLine("BOOM!");
		}
	}

	class AK47 : Gun
	{
		public AK47() : base("AK-47")
		{

		}
		public override void Display()
		{
			Console.WriteLine("Whoa!");
		}
	}
	
	class Program
	{
		static void Main(string[] args)
		{
			List<Item> inventory = new List<Item>();
			inventory.Add(new Chair("Wooden Chair"));
			inventory.Add(new Gun("AR-15"));
			inventory.Add(new Potion("Heath"));

			foreach (Item item in inventory)
			{
				// item.Use();

				item.Blegh();
				// Gun gun = item as Gun;
				// if (gun != null)
				// {
				// 	gun.Shoot();
				// }
			}

			Console.ReadKey();
		}
	}
}
