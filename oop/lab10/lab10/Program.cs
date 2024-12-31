using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace lab10
{
    internal class Program
    {
        static void Main(string[] args)
        {

            string[] months = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
            string[] summerMonths = { "june", "july", "august" };
            string[] winterMonths = { "january", "february", "december" };

            int n = 5;

            var result1 = months.Where(month => month.Length == n);
            foreach (var month in result1)
            {
                Console.WriteLine(month);
            }

            Console.Write("\n\n");

            var result2 = months.Where(month => summerMonths.Contains(month) || winterMonths.Contains(month));
            foreach (var month in result2)
            {
                Console.WriteLine(month);
            }

            Console.Write("\n\n");

            var result3 = months.OrderBy(month => month);
            foreach (var month in result3)
            {
                Console.WriteLine(month);
            }

            Console.Write("\n\n");

            var result4 = months.Where(month => month.Contains("u") && month.Length >= 4);
            foreach (var month in result4)
            {
                Console.WriteLine(month);
            }
            Console.Write("\n\n\n");

            List<Bus> buses = new List<Bus>{
               new Bus("Иван И А", "maz", 1, 1,2010),
               new Bus("Aван И А", "maz", 123, 1,2011),
               new Bus("Bван И А", "maz", 123, 2,2012),
               new Bus("Dван И А", "maz", 123, 3,2013),
               new Bus("Uван И А", "maz", 123, 4,2014),
               new Bus("Lван И А", "maz", 1, 5,2015),
               new Bus("Иван И А", "maz", 123, 9,2019),
               new Bus("Иван И А", "maz", 123, 6,2016),
               new Bus("Илья И И", "maz", 123, 7,2017),
               new Bus("Андрей А А", "maz", 123, 8,2018)
            };
            List<Driver> drivers = new List<Driver>
            {
                new Driver("Андрей А А", "+375291111111"),
                new Driver("Илья И И", "+375291111111")
            };
            Console.WriteLine("Автобусы, с номером маршрута 1: ");
            foreach (var bus in buses) 
            {
                if(bus.NumberWay == 1)
                Console.WriteLine(bus);            
            }

            Console.WriteLine("Автобусы, эксплуатирующиеся раньше 2015 года: ");
            foreach (var bus in buses)
            {
                if (bus.StartYear < 2015)
                    Console.WriteLine(bus);
            }
            
            Console.WriteLine("Максимальный год эксплуатации по автобусу: ");
            var maxYear = buses.Min(x => x.StartYear);
            Console.WriteLine(maxYear);
            
            Console.WriteLine("Минимальный год эксплуатации по автобусу(2шт): ");
            var minYear = buses.OrderBy(x => x.StartYear);
            int counter = 0;
            foreach(var bus in buses)
            {
                Console.WriteLine(bus);
                counter++;
                if(counter == 2)
                {
                    break;
                }
            }

            Console.WriteLine("Сортировка по номеру маршрута: ");
            var sorted = buses.OrderBy(x => x.NumberWay);
            foreach(var bus in sorted)
            {
                Console.WriteLine(bus);
            }

            Console.WriteLine("\n\n5 разных операторов: ");
            var five = buses.Where(bus => bus.StartYear > 2010).Select(bus => new { bus.FullName, bus.Brand, bus.NumberBus }).OrderBy(bus => bus.Brand).GroupBy(bus => bus.FullName).FirstOrDefault();
            foreach (var bus in five)
            {
                Console.WriteLine(bus);
            }

            var busAndDriverInfo = from bus in buses
                                   join driver in drivers
                                   on bus.FullName equals driver.FullName
                                   select new
                                   {
                                       bus.NumberBus,
                                       bus.Brand,
                                       bus.NumberWay,
                                       driver.FullName,
                                       driver.numbDriver
                                   };

            foreach (var info in busAndDriverInfo)
            {
                Console.WriteLine($"Bus Number: {info.NumberBus}, Brand: {info.Brand}, Way: {info.NumberWay}, Driver: {info.FullName}, numbDriver: {info.numbDriver}");
            }
        }
    }
}
