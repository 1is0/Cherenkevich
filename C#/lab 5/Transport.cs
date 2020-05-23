using System;
using System.Collections.Generic;
using System.Text;

namespace AutoShow
{
    abstract class Transport
    {
        protected int yearOfRelease;
        public static int vin;
        public string Mark { get; set; }
        public string TipeOfTransport { get; set;}
        public static double Weight { get; set; }
        public string[] options;
        public enum Color : byte
        {
            Blue,
            White,
            Red,
            Green,
            Orange,
            Black,
            Grey,
            Yellow,
        }
        public Color cl { get; set; }

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
            string info = "Year of release: " + yearOfRelease + "; " + "Color: " + cl + "; " + "Weight: " + Weight;
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
        public virtual void HorsesOnKg()
        {
            int horses = 120;
            double power = horses / Weight;
            Console.WriteLine("Horsespower on one kg: " + power);
        }
        public abstract void BodyTipe();
    }
}
