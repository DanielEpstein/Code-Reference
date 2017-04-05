using System;

class Program
{
    static void Main()
    {
        try
        {
            bool exit = false;
            while (!exit)
            {
                int selection = MainMenu();
                switch (selection)
                {
                    case 0: exit = true; break;
                    case 1: AddScreen(); break;
                    case 2: SubtractScreen(); break;
                    case 3: MultiplyScreen(); break;
                    case 4: DevideScreen(); break;
                    case 9: ThrowException(); break; // ahah
                }
            }
        }
        catch (Exception exception)
        {
            Console.WriteLine();
            Console.WriteLine("Do you want to report this bug?");
            Console.WriteLine("-------------------------------------------------------------------------------");
            Console.WriteLine(exception.ToString());
            Console.WriteLine("-------------------------------------------------------------------------------");
            Console.Write("Do you want to report this bug?");
            Console.ReadKey();
        }
    }

    static void ThrowException()
    {
        int.Parse("Crash");
    }

    static int MainMenu()
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine();
            Console.WriteLine(" 1 - Add");
            Console.WriteLine(" 2 - Subtract");
            Console.WriteLine(" 3 - Multiply");
            Console.WriteLine(" 4 - Devide");
            Console.WriteLine(" 9 - Crash the program");
            Console.WriteLine(" 0 - Exit");
            Console.WriteLine();

            string stringinput = InputPrompt("Please make a selection 0-4");

            if (stringinput == "9" || ValidSelection(stringinput, 0, 4))
            {
                return int.Parse(stringinput);
            }
        }
    }

    static bool ValidSelection(string first, int second, int third)
    {
        int myint;
        if (IsItAnInt(first))
        {
            myint = int.Parse(first);
            if (InRange(myint, second, third))
            {
                return true;
            }
            else
            {
                GiveError();
                return false;
            }
        }
        else
        {
            GiveError();
            return false;
        }
    }

    static bool IsItAnInt(string stringinput)
    {
        int bleh;
        return int.TryParse(stringinput, out bleh);
    }

    static bool IsItADouble(string stringinput)
    {
        double bleh;
        return double.TryParse(stringinput, out bleh);
    }

    static bool InRange(int first, int seocnd, int third)
    {
        if (first >= seocnd && first <= third)
        {
            return true;
        }
        return false;
    }

    static double[] GetTwoNumbers()
    {
        double[] twoNumbers = new double[2];
        while (true)
        {
            string stringinput = InputPrompt("Please enter FIRST number?");
            if (IsItADouble(stringinput))
            {
                twoNumbers[0] = double.Parse(stringinput);
                break;
            }
            else
            {
                GiveError();
            }
        }

        while (true)
        {
            string stringinput = InputPrompt("Please enter SECOND number?");
            if (IsItADouble(stringinput))
            {
                twoNumbers[1] = double.Parse(stringinput);
                break;
            }
            else
            {
                GiveError();
            }
        }
        return twoNumbers;
    }

    static void AddScreen()
    {
        Console.Clear();
        DisplayMenuHeading("ADD");
        Console.WriteLine(" ANSWER: " + Add(GetTwoNumbers()));
        Pause();
    }
    static void SubtractScreen()
    {
        Console.Clear();
        DisplayMenuHeading("SUBTRACT");
        Console.WriteLine(" ANSWER: " + Subtract(GetTwoNumbers()));
        Pause();
    }
    static void MultiplyScreen()
    {
        Console.Clear();
        DisplayMenuHeading("MULTIPLY");
        Console.WriteLine(" ANSWER: " + Multiply(GetTwoNumbers()));
        Pause();
    }
    static void DevideScreen()
    {
        Console.Clear();
        DisplayMenuHeading("DEVIDE");
        Console.WriteLine(" ANSWER: " + Devide(GetTwoNumbers()));
        Pause();
    }

    static void DisplayMenuHeading(string heading)
    {
        Console.WriteLine(" " + heading);
        Console.WriteLine(" -----------------------------------------");
    }

    static double Add(double[] inputarray)
    {
        return inputarray[0] + inputarray[1];
    }
    static double Subtract(double[] inputarray)
    {
        return inputarray[0] - inputarray[1];
    }
    static double Multiply(double[] inputarray)
    {
        return inputarray[0] * inputarray[1];
    }
    static double Devide(double[] inputarray)
    {
        return inputarray[0] / inputarray[1];
    }

    static string InputPrompt(string prompttext)
    {
        Console.WriteLine(" " + prompttext);
        Console.Write(" >");
        return Console.ReadLine();
    }

    static void GiveError()
    {
        Console.Write(" Invaild input, please try again...");
        Console.ReadKey();
        Console.WriteLine();
    }

    static void Pause()
    {
        Console.Write(" Press any key to continue...");
        Console.ReadKey();
        Console.WriteLine();
    }
}
