using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.Remoting.Lifetime;
using System.Text;
using System.Threading.Tasks;

namespace lab10
{
       
    partial class Driver
    {
        public string FullName { get; set; }
        public string numbDriver { get; set; }

        public Driver(string FIO, string number)
        {
            FullName = FIO;
            numbDriver = number;
        }
    }
    partial class Bus
        {
            public static int Counter;
            public string FullName { get; set; }
            public int NumberBus { get; set; }
            public int NumberWay { get; set; }
            public string Brand { get; set; }
            public int StartYear { get; }
            const int Mileage = 55555;
            public readonly int ID;
            public static Random random = new Random();
            public Bus()
            {

                FullName = "123";
            }
            public Bus(int numberWay, string brand)
            {
                if (numberWay <= 0)
                    throw new ArgumentException("Номер маршрута должен быть положительным.");

                NumberWay = numberWay;
                Brand = brand ?? throw new ArgumentNullException(nameof(brand), "Марка не может быть null.");
                ID = GenerateID();
                Counter++;
            }

            public Bus(int startYear)
            {
                if (startYear < 1900 || startYear > DateTime.Now.Year)
                    throw new ArgumentOutOfRangeException(nameof(startYear), "Год начала эксплуатации должен быть в пределах 1900 до текущего года.");

                StartYear = startYear;
                ID = GenerateID();
                Counter++;
            }

            public Bus(string FIO, string mark, int numBus, int numWay, int startYear)
            {
                if (string.IsNullOrWhiteSpace(FIO))
                    throw new ArgumentException("ФИО не может быть пустым.");

                if (numBus <= 0)
                    throw new ArgumentException("Номер автобуса должен быть положительным.");

                if (numWay <= 0)
                    throw new ArgumentException("Номер маршрута должен быть положительным.");

                if (string.IsNullOrWhiteSpace(mark))
                    throw new ArgumentException("Марка не может быть пустой.");

                if (startYear < 1900 || startYear > DateTime.Now.Year)
                    throw new ArgumentOutOfRangeException(nameof(startYear), "Год начала эксплуатации должен быть в пределах 1900 до текущего года.");

                FullName = FIO;
                NumberBus = numBus;
                NumberWay = numWay;
                Brand = mark;
                StartYear = startYear;
                ID = GenerateID();
                Counter++;
            }
            private Bus(string brand)
            {
                Brand = brand;
                ID = GenerateID();
                Counter++;
            }

            static Bus()
            {
                Counter = 0;
            }

            private int GenerateID()
            {
                return DateTime.Now.Millisecond + random.Next(1, 5000);
            }

            public void UpdateBusInfo(ref int newNumber, out string message)
            {
                NumberBus = newNumber;
                message = $"Новый номер автобуса: {NumberBus}.";
            }

            public override bool Equals(object obj)
            {
                if (obj is Bus otherBus)
                {
                    return this.ID == otherBus.ID;
                }
                return false;
            }

            public override int GetHashCode()
            {
                return ID.GetHashCode();
            }

            public override string ToString()
            {
                return $"Bus(ID: {ID}, FullName: {FullName}, NumberBus: {NumberBus}, " +
                       $"NumberWay: {NumberWay}, Brand: {Brand}, StartYear: {StartYear}, " +
                       $"Mileage: {Mileage})";
            }
            public static Bus CreateBusWithBrand(string brand)
            {
                return new Bus(brand);
            }
        }
    }

