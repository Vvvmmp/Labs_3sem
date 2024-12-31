
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{

    internal class Program
    {
        public abstract class Something
        {
            public abstract void ItsOK();
        }
        public interface IGood
        {
            void Fine();
        }

        public class Case : Something, IGood
        {
            public void Fine()
            {
                Console.WriteLine("ITS FINE CASE");
            }

            public override void ItsOK()
            {
                Console.WriteLine("ITS OK CASE");
            }
        }

        public class Computer : IComparable<Computer>
        {
            public static readonly string name = "IBM";
            public static int countComp = 0;
            private int sum = 0;

            public Computer(int sum)
            {
                this.sum = sum;
                countComp++;
            }

            public int CompareTo(Computer other)
            {
                return this.sum.CompareTo(other.sum);
            }
        }
        enum en1
        {
            Январь,
            Февраль,
            Март,
            Апрель,
            Май,
            Июнь,
            Июль,
            Август,
            Сентябрь,
            Октябрь,
            Ноябрь,
            Декабрь
        }

        static void Main(string[] args)
        {
            foreach (var item in Enum.GetValues(typeof(en1)))
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
            Console.Clear();

            string arr = "123.456.789";

            string[] result = arr.Split('.');

            foreach (var item in result)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
            Console.Clear();


            Computer computer1 = new Computer(300);
            Computer computer2 = new Computer(300);

            switch (computer1.CompareTo(computer2))
            {
                case 1: Console.WriteLine("c1 > c2"); break;
                case 0: Console.WriteLine("c1 == c2"); break;
                case -1: Console.WriteLine("c1 < c2"); break;
            }
            Console.ReadLine();
            Console.Clear();

            Case @case = new Case();

            @case.Fine();
            @case.ItsOK();

            Console.ReadLine();
            Console.Clear();
        }
    }
}
