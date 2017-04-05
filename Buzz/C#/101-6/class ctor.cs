using System;

class Program
{
    static void Main()
    {
        Car car1 = new Car("Ford", "Blue", 4, 1982);
        Car car2 = new Car("Holden", "Red", 4, 1983);

        car1.Display();
        car2.Display();

        Console.WriteLine("End of Program...");
        Console.ReadKey();
    }
}

class Car
{
    private string _name;
    private int _year;
    private int _doors;
    private string _colour;

    public string Name { get { return _name; } }
    public int Year { get { return _year; } }
    public int Doors { get { return _doors; } }
    public string Colour { get { return _colour; } }

    public Car(string name, string colour, int doors, int year)
    {
        _name = name;
        _colour = colour;
        _doors = doors;
        _year = year;
    }

    public void Display()
    {
        Console.WriteLine("Name: {0} Colour: {1} Doors: {2} Year: {3}", Name, Colour, Doors, Year);
    }
}

