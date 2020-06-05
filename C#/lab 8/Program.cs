using System;
using System.ComponentModel.DataAnnotations;

namespace lab8
{
    class Program
    {
        public static void SetParameters(Model Obj)
        {
            Console.WriteLine("Enter Mark: ");
            Obj.Mark = Console.ReadLine();

            Console.WriteLine("Enter year of release: ");
            Obj.Year = ValidateYear();

            Console.WriteLine("Enter weight in kg: ");
            Obj.Weight = CheckDouble();

            Obj.SetVin();

            Console.WriteLine("Enter color(1-Blue, 2-White, 3-Red, 4-Green, 5-Orange, 6-Black, 7-Grey, 8-Yellow)");
            Obj.cl = (Color)ValidateColor();

            Console.WriteLine("Enter horse power");
            Obj.HorsePower = CheckInt();
        }


        public static int ValidateColor()
        {
            int result;
            while (!int.TryParse(Console.ReadLine(), out result) || result < 1 || result > 8)
            {
                Console.Write("Incorrect input, please try again: ");
            }

            return result;
        }


        public static int CheckInt()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a) || a <= 0)
            {
                Console.Write("Incorrect input, please try again: ");
            }

            return a;
        }


        public static double CheckDouble()
        {
            double b;
            while (!double.TryParse(Console.ReadLine(), out b) || b <= 0)
            {
                Console.Write("Incorrect input, please try again: ");
            }

            return b;
        }



        public static int ValidateYear()
        {
            int god;
            while (!int.TryParse(Console.ReadLine(), out god) || god > 2020 || god < 0)
            {
                Console.WriteLine("Incorect year of release, please try again: ");
            }
            return god;
        }


        public static void SetArray(Model[] list)
        {
            for (int i = 0; i < list.Length; i++)
            {
                list[i] = new Model();
                SetParameters(list[i]);
                Console.WriteLine();
            }

            Console.WriteLine("List of cars: ");
            for (int i = 0; i < list.Length; i++)
            {
                Console.WriteLine(list[i]);
            }
        }

        public static void DisplayInfo(string mes)
        {
            Console.WriteLine("Event: " + mes);
        }


        static void Main(string[] args)
        {
            Model first = new Model();
            Console.WriteLine("Information about default car");
            //Обработка исключительной ситуации 
            try
            {
                Console.WriteLine(first);
            }
            catch(Exception ex)
            {
                Console.WriteLine("\nException testing: " + ex.Message + "\n");
            }
            Console.WriteLine("\n");


            //Добавление в 8 лабораторной
            first.Add += DisplayInfo;
            first.CarAdd();


            Console.WriteLine("Tipe information about new car");
            Model[] list = new Model[2];
            SetArray(list);
            Console.WriteLine();
            for (int j = 0; j < list.Length; j++)
            {
                //Обработчик в виде анонимного метода
                Console.WriteLine("Event tested: ");
                list[j].Add += delegate (string mes)
                  {
                      Console.WriteLine("Anonim expression: " + mes);
                  };

                //Обработчик в виде люмбда-выражения
                list[j].Add += mes => Console.WriteLine("Lambda expression: " + mes);
                Console.WriteLine();

                list[j].HorsesOnKg(list[j].HorsePower);
                list[j].SetVin();
            }

            Console.WriteLine("Sorted by year of release: ");
            Array.Sort(list);
            foreach (Model s in list)
            {
                Console.WriteLine(s);
                Console.WriteLine();
            }
            Console.WriteLine();
            IEquipment action1 = new Model();
            Car action2 = new Car();
            Console.WriteLine();
            action1.Equipment();
            action2.Equipment();

            action1.RightOrLeftRudder();
            action2.RightOrLeftRudder();

            Console.WriteLine();


            Console.ReadKey();

        }

    }
}