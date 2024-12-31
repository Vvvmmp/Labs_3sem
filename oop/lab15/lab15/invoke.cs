using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lab15
{
    internal class invoke
    {
        static void Task1()
        {
            Console.WriteLine("Задача 1 начата.");
            Thread.Sleep(2000); 
            Console.WriteLine("Задача 1 завершена.");
        }

        static void Task2()
        {
            Console.WriteLine("Задача 2 начата.");
            Thread.Sleep(1500); 
            Console.WriteLine("Задача 2 завершена.");
        }

        static void Task3()
        {
            Console.WriteLine("Задача 3 начата.");
            Thread.Sleep(1000); 
            Console.WriteLine("Задача 3 завершена.");
        }
        public static void invokeMethod()
        {
            
            Parallel.Invoke(
            Task1,
            Task2,
            Task3
            );

            Console.WriteLine("Все задачи завершены.");
        }
    }
}
