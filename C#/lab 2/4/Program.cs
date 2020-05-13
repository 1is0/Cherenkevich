using System;
using System.Runtime.InteropServices;

namespace Zad4
{
    class Program
    {
        static int Func(int a, int b)
        {
            int i, proiz = 1;
            for (i = a; i <= b; i++)
                proiz = proiz * i;
            int rez = 0, st = 1;
            while(st<=proiz)
            {
                if (proiz % st == 0)
                    rez = st;
                st*=2;
            }
            return rez;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Zadanie 4\n");
            Console.WriteLine("Enter a:");
            string astr = Console.ReadLine();
            int a = Convert.ToInt32(astr);
            Console.WriteLine("\nEnter b:");
            string bstr = Console.ReadLine();
            int b = Convert.ToInt32(bstr);
            Console.WriteLine("Rezult is:");
            Console.Write(Func(a, b).ToString());

        }
    }
}
