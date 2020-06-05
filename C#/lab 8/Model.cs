using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace lab8
{
    enum Color
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
    class Model : Car,IEquipment,IComparable
    {
        public string Rudder { get; set; }
        public string Kit { get; set; } 
        public Color cl { get; set; }
        public Model():base()
        {
            Mark = "Renault"; 
            yearOfRelease = 2010;
            TipeOfTransport = "Earth";
            Weight = 1100;
            Capacity = 1.5;
            Rudder = "left";
            Kit = "full";
            HorsePower = 120; 
            this.cl = cl;
            tipeOfFuel = "Dizel";
            Inf.price = 1200;
            Inf.mileage = 60000;
        }
        int IComparable.CompareTo(object obj)
        {
            if (this.Year>((Model)obj).yearOfRelease)
            {
                return 1;
            }
            if (this.Year < ((Model)obj).yearOfRelease)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

        public override void RightOrLeftRudder()
        {
            Console.WriteLine("Car is {0}-hand drive", Rudder);
        }
        public override void Equipment()
        {
            Console.WriteLine($"The car has{Kit} kit");
        }

        public override string ToString()
        {
            return base.ToString() + "Mark: " + Mark + "; " + "Tipe of fuel: " + tipeOfFuel + ";\n";
        }

        //Добавление в 8 лабораторной
        public delegate void Message(string mes);
        public event Message Add;
        
        public void CarAdd()
        {
            Add?.Invoke("New car adding");
        }

    }
}
