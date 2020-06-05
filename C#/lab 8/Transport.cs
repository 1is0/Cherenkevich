using System;
using System.Collections.Generic;
using System.Text;

namespace lab8
{
    abstract class Transport
    {
        protected int yearOfRelease;
        public static string vin;
        public string Mark { get; set; }
        public string TipeOfTransport { get; set;}
        public double Weight { get; set; }
        public string[] options;
        

        public virtual void RightOrLeftRudder() { }
        public abstract void Equipment();

        public  int Year
        {
            get
            {
                return yearOfRelease;
            }
            set
            {
                if(value<0)
                {
                    yearOfRelease=0;
                }
                else
                {
                    yearOfRelease = value;
                }
            }
        }
        public override string ToString()
        {
            string info = "Year of release: " + yearOfRelease + "; " + "Weight: " + Weight;
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
        public void HorsesOnKg(int horses)
        {
            double power = horses / Weight;
            Console.WriteLine("Horsespower on one kg: " + power);
        }
        public void SetVin()
        {
            vin = Guid.NewGuid().ToString();
        }
        public abstract void BodyTipe();
    }
}
