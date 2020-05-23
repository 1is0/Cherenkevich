using System;
using System.Collections.Generic;
using System.Text;

namespace AutoShow
{
    class Logan : Car
    {
        public Logan(Color cl,int price,int mileage)
        {
            Mark = "Renault";
            yearOfRelease = 2010;
            TipeOfTransport = "Earth";
            Weight = 1100;
            Capacity = 1.5;
            HorsePower = 120;
            this.cl = cl;
            tipeOfFuel = "Dizel";
            Inf.price = price;
            Inf.mileage = mileage;
        }
        public override string ToString()
        {
            return base.ToString() + "Mark: " + Mark + "; " + "Tipe of fuel: " + tipeOfFuel + ";\n";
        }
        public override void HorsesOnKg()
        {
            Console.WriteLine("Horsespower on kg: " + Weight / HorsePower);
        }
    }
}
