using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lab14
{
    partial class Program
    {
        static void FindPrimes(int n)
        {
            Console.WriteLine($"Поток {Thread.CurrentThread.Name} начался.");

            using (StreamWriter writer = new StreamWriter("primes.txt"))
            {
                for (int i = 0; i <= n; i++)
                {
                    if (isPrime(i))
                    {
                        Console.WriteLine(i);
                        writer.WriteLine(i);
                    }
                    Thread.Sleep(100);
                }
            }
            Console.WriteLine($"Поток {Thread.CurrentThread.Name} завершился.");
        }

        static bool isPrime(int n)
        {
            if (n < 2) return false;

            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }

        static readonly object lockObject = new object();
        static int currentNumber = 1; 
        static void PrintEvenNumbers(int n, StreamWriter writer)
        {
            while (true)
            {
               
                lock (lockObject)
                {
                    if (currentNumber > n) break;

                    if (currentNumber % 2 == 0)
                    {
                        Console.WriteLine($"[{Thread.CurrentThread.Name}] Четное: {currentNumber}");
                        writer.WriteLine($"Четное: {currentNumber}");
                        currentNumber++;
                    }
                }
                Thread.Sleep(50);
            }
        }

        static void PrintOddNumbers(int n, StreamWriter writer)
        {
            while (true)
            {
                lock (lockObject)
                {
                    if (currentNumber > n) break;

                    if (currentNumber % 2 != 0)
                    {
                        Console.WriteLine($"[{Thread.CurrentThread.Name}] Нечетное: {currentNumber}");
                        writer.WriteLine($"Нечетное: {currentNumber}");
                        currentNumber++;
                    }
                }
                Thread.Sleep(100);
            }
        }

        public static void printTimeToNewYear(object obj)
        {
            DateTime newYear = new DateTime(DateTime.Now.Year + 1, 1, 1);
            TimeSpan result = newYear - DateTime.Now;
            Console.WriteLine($"Осталось времени: {result.Days} дней {result.Hours}:{result.Minutes}:{result.Seconds}");
        }

    }
}

