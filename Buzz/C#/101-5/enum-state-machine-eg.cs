using System;
using System.Collections.Generic;

enum State
{
    MainMenu,
    AddItem,
    DisplayItems,
    Exit
}


class Program
{
    static void Main()
    {
        State state = State.MainMenu;
        List<string> productNames = new List<string>();

        while (state != State.Exit)
        {
            switch (state)
            {
                case State.MainMenu: state = MainMenu(); break;
                case State.AddItem: state = AddItem(productNames); break;
                case State.DisplayItems: state = DisplayItems(productNames); break;
            }
        }
    }

    private static State AddItem(List<string> productNames)
    {
        productNames.Add(Console.ReadLine());
        return State.MainMenu;
    }
    private static State DisplayItems(List<string> productNames)
    {
        foreach (var product in productNames)
        {
            Console.WriteLine(product);
        }

        return State.MainMenu;
    }
    private static State MainMenu()
    {
        int choice = int.Parse(Console.ReadLine());

        if (choice == 1)
        {
            return State.AddItem;
        }

        if (choice == 2)
        {
            return State.Exit;
        }
        if (choice == 3)
        {
            return State.Exit;
        }
        return State.MainMenu;
    }
}

