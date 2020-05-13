using System;

namespace Zad8
{
        class MainProgramm
        {
            static void Main()
            {
                Functions func = new Functions();

                Console.WriteLine("Zadanie 8");

                while (!func.ValidateInfo())
                {
                    Console.WriteLine("Язык введен не в верном формате");
                }

                func.Translate();
            }

        }
    }