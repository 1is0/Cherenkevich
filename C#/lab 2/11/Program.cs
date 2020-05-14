using System;

namespace Zad11
{
    class Program
    {
        public static void Insert(string str,char[]ch)
        {
            for (int i = 1; i < str.Length; i++)
            {
                if (ch[i] == ',' || ch[i] == '!' || ch[i] == '.' || ch[i] == ':' || ch[i] == ';' || ch[i] == '-' || ch[i] == '?')
                {
                    if (ch[i - 1] == ',' || ch[i - 1] == '!' || ch[i - 1] == '.' || ch[i - 1] == ':' || ch[i - 1] == ';' || ch[i - 1] == '-' || ch[i - 1] == '?' || ch[i - 1] == ' ')
                    {
                        continue;
                    }
                    char b = ch[i];
                    for (int j = i; j >= 0; j--)
                    {
                        if (j == 0)
                        {
                            Console.WriteLine("\nWarning: ");
                            Console.WriteLine("It’s impossible to put a punctuation mark at the beginning of a sentence.\n=============");
                            break;
                        }
                        if (ch[j] == ' ')
                        {
                            ch[j] = b;
                            break;
                        }
                    }
                }
            }
            
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Zadanie 11:");
            Console.WriteLine("Enter line");
            string str=Console.ReadLine();
            char[] ch = str.ToCharArray();
            Insert(str, ch);
            int i = 0;
            for (i = 0;i< str.Length;i++)
            {
                Console.Write(ch[i]);
            }
            Console.ReadKey();
        }
    }
}
