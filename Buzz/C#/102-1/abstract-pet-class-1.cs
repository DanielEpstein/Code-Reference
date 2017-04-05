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
            // public abstract string Name { get; set; }
            public abstract void Use();
		}

		class Cat : Pet
		{
			public string Name { get; private set; }

			public Cat(string name)
                {
				Name = name;
			}
            public override void Use()
            {
                Console.WriteLine("Meow");
            }
		}

		class Dog : Pet
		{
			public  string Name { get; private set; }

			public Dog(string name)
			{
				Name = name;
			}
            public override void Use()
            {
                Console.WriteLine("Wooof");
            }
        }

		class Fish : Pet
		{
			public string Name { get; private set; }

			public Fish(string name)
			{
				Name = name;
			}
            public override void Use()
            {
                Console.WriteLine("Bloop");
            }
        }

		class Bird : Pet
		{
			public string Name { get; private set; }

			public Bird(string name)
			{
				Name = name;
			}
            public override void Use()
            {
                Console.WriteLine("Tweet");
            }
        }



		static void Main()
		{
			List<Pet> Pets = new List<Pet>();

			Pets.Add(new Cat("CAT 1"));
			Pets.Add(new Dog("DOG 1"));
			Pets.Add(new Bird("BIRD 1"));
			Pets.Add(new Fish("FISH 1"));

            

		}
	}
}
