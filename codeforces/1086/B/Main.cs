using System;
using System.Globalization;

class MainClass
{
	static int n, s;
	public static void Main(string[] args)
	{
		string[] ln = Console.ReadLine().Split(' ');
		n = Int32.Parse(ln[0]);
		s = Int32.Parse(ln[1]);
		int[] degs = new int[n];
		for(int i = 0; i < n-1; i++)
		{
			string[] line = Console.ReadLine().Split(' ');
			int a = Int32.Parse(line[0]);
			int b = Int32.Parse(line[1]);
			a--;
			b--;
			degs[a]++;
			degs[b]++;
		}
		int l = 0;
		for(int i = 0; i < n; i++)
		{
			if(degs[i] == 1)
				l++;
		}
		double num = 2.0 * s;
		double den = 1.0 * l;
		NumberFormatInfo nfi = new NumberFormatInfo();
		nfi.NumberDecimalDigits = 18;
		Console.WriteLine((num/den).ToString("N", nfi).Replace(",", ""));
	}
}

