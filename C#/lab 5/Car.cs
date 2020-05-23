using System;
using System.Collections.Generic;
using System.Text;

namespace AutoShow
{
    class Car: Transport
    {
        public struct Information
        {
            public int price;
            public int mileage;
        }
        public Information Inf;

        public string privod { get; set; }
        public string tipeOfFuel { get; set; }
        public string Marc { get; set; }
        public double Capacity { get; set; }
        public int HorsePower { get; set; }

        public Car():base()
        {
            privod = "Back";
            tipeOfFuel = "Dizel";
        }

        public override string ToString()
        {
            return base.ToString() + "; " + "Privod: " + privod + "; ";
        }
        public override void BodyTipe()
        {
            Console.WriteLine("Body Tipe is sedan");
        }
    }
}
