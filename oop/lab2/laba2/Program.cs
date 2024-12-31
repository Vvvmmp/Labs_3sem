using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba2
{

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
    }
        internal class Program
    {
        static void Main(string[] args)
        {
            Bus[] buses = new Bus[]
            {
                Bus.CreateBusWithBrand("mercedes"),
                new Bus("Пииии Чии Чук", "Volvo", 2214, 12, 1990),
                new Bus("Диань Шлу Ду", "lexus", 8632, 12, 1990),
                new Bus("Рудковский Глеб Викторович", "kopeyka", 1022, 91, 1950),
                new Bus("Мира Ива Ин", "BMW", 1111, 13, 2023)
            };
            var anonymousBus = new
            {
                FullName = "Фыв Фа Йу",
                Brand = "asd",
                NumberBus = 4,
                NumberWay = 91,
                StartYear = 2020
            };

            Console.WriteLine($"Анонимный автобус: FullName = {anonymousBus.FullName}, Brand = {anonymousBus.Brand}, " +
                             $"NumberBus = {anonymousBus.NumberBus}, NumberWay = {anonymousBus.NumberWay}, " +
                             $"StartYear = {anonymousBus.StartYear}");

            Console.WriteLine("Автобусы по номеру маршрута 12:");
            Bus[] routeBuses = GetBusesByRoute(buses, 12);
            PrintBuses(routeBuses);
            Console.WriteLine();

            Console.WriteLine("Автобусы, эксплуатируемые более 30 лет:");
            Bus[] oldBuses = GetBusesExceedingYears(buses, 30);
            PrintBuses(oldBuses);
        }
        static Bus[] GetBusesByRoute(Bus[] buses, int routeNumber)
        {
            Bus[] result = new Bus[buses.Length];
            int count = 0;

            for (int i = 0; i < buses.Length; i++)
            {
                if (buses[i].NumberWay == routeNumber)
                {
                    result[count] = buses[i];
                    count++;
                }
            }
            Array.Resize(ref result, count);
            return result;
        }
        static Bus[] GetBusesExceedingYears(Bus[] buses, int years)
        {
            Bus[] result = new Bus[buses.Length];
            int count = 0;
            int currentYear = 2024;

            for (int i = 0; i < buses.Length; i++)
            {
                if ((currentYear - buses[i].StartYear) > years)
                {
                    result[count] = buses[i];
                    count++;
                }
            }

            Array.Resize(ref result, count);
            return result;
        }

        static void PrintBuses(Bus[] buses)
        {
            if (buses.Length == 0)
            {
                Console.WriteLine("Нет автобусов, соответствующих критериям.");
                return;
            }

            foreach (var bus in buses)
            {
                Console.WriteLine(bus.ToString());
            }
        }
        

               
        }
    }


