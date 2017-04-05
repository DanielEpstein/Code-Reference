using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
	class Student
	{
		private string _name;
		public Student(string name)
		{
			_name = name;
		}

		public void Display()
		{
			Console.WriteLine("Name: {0}", _name);
		}
	}

	class Course
	{
		private List<Student> _students;

		private string _name;

		public Course(string name)
		{
			_name = name;
			_students = new List<Student>();
		}

		public void AddStudent(Student student)
		{
			_students.Add(student);
		}

		public void Display()
		{
			Console.WriteLine("Course: {0}", _name);

			foreach (Student student in _students)
			{
				student.Display();
			}
		}
	}

	class Program
	{
		static void Main()
		{
			Student nelson = new Student("nelson");

			Student gavin = new Student("gavin");

			Student jason = new Student("jason");

			Course introToCs = new Course("Intro to C#");

			Course introToCpp = new Course("Intro to C++");

			introToCs.AddStudent(nelson);
			introToCs.AddStudent(gavin);
			introToCs.AddStudent(jason);

			introToCpp.AddStudent(nelson);
			introToCpp.Display();
			introToCs.Display();

			Console.ReadKey();
		}
	}
}
