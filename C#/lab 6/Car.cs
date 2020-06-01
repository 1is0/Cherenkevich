using System;
using System.Collections.Generic;
using System.Text;


namespace lab6
{
    class Car: Transport, IEquipment
    {
        public struct Information
        {
            public int price;
            public int mileage;
        }
        public Information Inf;

        public string privod { get; set; }
        public string tipeOfFuel { get; set; }
        public double Capacity { get; set; }
        public int HorsePower { get; set; }

        //Добавления в 6 лабораторной
        public override void RightOrLeftRudder()
        {
            Console.WriteLine("Car is left-hand drive");
        }
        public override void Equipment()
        {
            Console.WriteLine("The car has full kit");
        }
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
