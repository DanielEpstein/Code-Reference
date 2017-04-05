using System;
using System.Collections.Generic;

namespace ConsoleApplication5
{
	class GraphicCard
	{
		public virtual void Render()
		{

		}
	}

	class CPU
	{
		public int CountOfCores { get; private set; }

		public CPU(int countOfCores)
		{
			CountOfCores = countOfCores;
		}

		public virtual void Compute()
		{

		}
	}

	class Motherboard
	{
		public virtual void DoStuff()
		{

		}

	}

	class Computer
	{
		public GraphicCard GraphicsCard { get; private set; }
		public CPU CPU { get; private set; }
		public Motherboard Motherboard { get; private set; }

		public Computer(GraphicCard graphicCard, CPU cpu, Motherboard motherboard)
		{
			GraphicsCard = graphicCard;
			CPU = cpu;
			Motherboard = motherboard;
		}
		public void Run()
		{
			CPU.Compute();
			GraphicsCard.Render();
			Motherboard.DoStuff();
		}
	}

	class NVidia : GraphicCard
	{

		private string _series;
		public NVidia(string series)
		{
			_series = series;
		}

		public override void Render()
		{
			Console.WriteLine("Rending with series {0} (ps. better than ATI)", _series);
		}

	}

	class Intel : CPU
	{
		private string _series;

		public Intel(int cores, string series) : base(cores)
		{
			_series = series;
		}

		public override void Compute()
		{
			Console.WriteLine("Intel CPU: series {0} with {1} cores (ps. better than AMD)", CountOfCores, _series);
		}
	}

	 class Asus : Motherboard
	 {
		 private string _series;
		 private string _cpuSocket;

		 public Asus(string series, string cpuSocket)
		 {
			 _series = series;
			 _cpuSocket = cpuSocket;
		 }

		 public override void DoStuff()
		 {
			 Console.WriteLine("Doing stuff with asus mobo {0} with cpu socket {1} (ps. better than MSI)", _series, _cpuSocket);
		 }
	 }

	class Program
	{
		static void Main(string[] args)
		{
			Computer computer = new Computer(new NVidia("GTX 500"), new Intel(4, "i7"), new Asus("stuff", "LGA43432"));
			computer.Run();

			Console.ReadKey();

		}
	}
}
