using System;
using System.Collections.Generic;
using System.Text;

namespace Zad5
{
    class Transport
    {
        protected int yearOfRelease;
        public static int vin;
        public string Marc { get; set;}
        public string Color { get; set;}
        public string TipeOfTransport { get; set;}
        public static double Weight { get; set; }
        public string[] options;
        public static int Vin
        {
            get
            {
                return vin;
            }
            set
            {
                if(value<0)
                {
                    vin = -1 * value;
                }
                else
                {
                    vin = value;
                }
            }
        }
        public override string ToString()
        {
            string info = "Year of release: " + yearOfRelease + "; " + "Color: " + Color + "; " + "Weight: " + Weight + ".";
            return info;
        }
        public string this[int m]
        {
            get
            {
                return options[m];
            }
            set
            {
                options[m] = value;
            }
        }

        public Transport()
        {
            yearOfRelease = 2010;
            Color = "Red";
            TipeOfTransport = "Earth";
            Weight = 1900;
        }
        //Конструктор
        public Transport(int n)
        {
            options = new string[n];
        }
        public static void ShowVin()
        {
            Console.WriteLine("Vin: " + vin);
        }
        public static void HorsesOnKg()
        {
            int horses = 120;
            double power = horses / Weight;
            Console.WriteLine("Horsespower on one kg: " + power);
        }
    }
}
