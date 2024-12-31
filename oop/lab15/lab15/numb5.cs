using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab15
{
    partial class threeTasks
    {
        public static void parallel() {
            int[] results = new int[100000];
            Stopwatch stopwatch1 = new Stopwatch();
            stopwatch1.Start();
            Parallel.For(0, 100000, i =>
            {
                results[i] = CalculateCube(i);
            });
            stopwatch1.Stop();
            Console.WriteLine($"\nВычисления завершены. Время с parallel: {stopwatch1.ElapsedMilliseconds}\n");

            stopwatch1.Restart();
            for (int i = 0; i < results.Length; i++)
            {
                results[i] = CalculateCube(i);
            }
            stopwatch1.Stop();
            Console.WriteLine($"\nВычисления завершены. Время без parallel: {stopwatch1.ElapsedMilliseconds}\n");

            stopwatch1.Restart();
            List<int> numbers = new List<int>();
            Parallel.ForEach(numbers, number =>
            {
                int square = CalculateSquare(number);                                     
            });
            stopwatch1.Stop();
            Console.WriteLine($"\nВычисления завершены(foreach). Время с parallel: {stopwatch1.ElapsedMilliseconds}\n");

            stopwatch1.Restart();
            foreach (int i in numbers)
            {
                int square = CalculateSquare(i);
            }
            stopwatch1.Stop();
            Console.WriteLine($"\nВычисления завершены(foreach). Время без parallel: {stopwatch1.ElapsedMilliseconds}\n");
        }
    }
}
