using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace kr
{
    internal class Program
    {
        public interface IGood
        {
            void Fine();
        }

        abstract public class Something
        {
            public abstract void ItsOk();
        }
        public class Case : Something, IGood
        {
            public void Fine()
            {
                Console.WriteLine("Через Интерфейс");
            }
            public override void ItsOk()
            {
                Console.WriteLine("Через абстрактный класс");
            }
        }
        public class Computer : IComparable
        {
            static string name;
            public int ID;
            static readonly int price = 5;

            static Computer() {}
            public Computer(string name, int id)
            {
                this.ID = id;
            }

            public int CompareTo(object obj)
            {
                if(obj is  Computer comp)
                {
                    if (this.ID > comp.ID) return 1;
                    else if (this.ID < comp.ID) return 2;
                    else return 3;
                }
                else throw new NotImplementedException("не computer");
            }
        }
        static void Main(string[] args)
        {
           
            //.[] month = new Enum["Январь" = 1, "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"];


            //foreach (int i in month.get)
            //{
            //    Console.WriteLine(i);
            //}

            string str = "123.456.789";
            string[] result = str.Split('.');
            foreach(string s in result)
            {
                Console.WriteLine(s);
            }
            Computer comp1 = new Computer("Компьютер 1 ", 5);
            Computer comp2 = new Computer("Компьютер 2 ", 10);

            if (comp1.CompareTo(comp2) == 1)
            {
                Console.WriteLine("Компьютер1 > Компьютер2");
            }
            else if (comp1.CompareTo(comp2) == 2)
            {
                Console.WriteLine("Компьютер1 < Компьютер2");
            }
            else { Console.WriteLine("Они равны"); }

            Case case1 = new Case();
            case1.Fine();
            case1.ItsOk();




            Console.ReadLine();
        }

    }
}
