using System;

namespace AutoShow
{
    class Program
    {
        static void Main(string[] args)
        {
            Logan Log = new Logan(Car.Color.Grey, 3000,10000);
            Console.Write(Log);
            Log.HorsesOnKg();
        }
    }
}
