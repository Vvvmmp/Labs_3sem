
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    internal class Program
    {

        public interface IMove
        {
            void Move();
        }

        public abstract class Transport
        {
            public abstract void Move();
        }

        public class Car : Transport, IMove
        {
            public override void Move()
            {
                Console.WriteLine("Вывод абстрактроного метода");
            }

            void IMove.Move()
            {
                Console.WriteLine("Вывод интерфейсного метода");
            }
        }

        public class Day
        {

            string[] strings = {
                "Понедельник",
                "Вторник",
                "Среда",
                "Четверг",
                "Пятница",
                "Суббота",
                "Воскресенье",
            };

            public string this[int index]
            {

                get => strings[index];
                set => strings[index] = value;
            }

            public override string ToString()
            {
                return string.Join(", ", strings);
            }


        }
        static void Main(string[] args)
        {
            string str1;
            string str2;

            str1 = Console.ReadLine();
            str2 = Console.ReadLine();

            Console.WriteLine(str1.Contains(str2));

            string[] str3 = { "hello", "hi", "wassyp", "ky" };

            var arr = str3.Reverse();

            foreach (string str4 in arr)
            {
                Console.WriteLine(str4);
            }


            try
            {
                Day day = new Day();

                Console.WriteLine(day[10]);
                Console.WriteLine(day.ToString());
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.Message);
            }

            Car car = new Car();

            car.Move();
            ((IMove)car).Move();

            Console.ReadLine();
        }
    }
}
