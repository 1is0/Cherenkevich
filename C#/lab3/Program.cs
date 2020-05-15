using System;

namespace Zad5
{
    class NewClass
    {
        static void Main(string[] args)
        {
            //Работа со статическим элементом 
            Transport.vin = 132759;
            Transport machine = new Transport();
            Transport.ShowVin();
            //Перегрузка стандартного метода ToString
            Console.WriteLine(machine);
            //Использование метода
            Transport.HorsesOnKg();
            //Использование индексатора
            Transport car = new Transport(3);
            car[0] = "Luke";
            car[1] = "Steering wheel heating";
            car[2] = "LED optics";
            Console.WriteLine("Options: " + car[0] + ", " + car[1] + ", " + car[2] + ".");
            Console.ReadKey();
        }
    }
}
