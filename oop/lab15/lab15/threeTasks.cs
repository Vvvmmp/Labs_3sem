using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab15
{
    partial class threeTasks
    {
        static int CalculateSquare(int number)
        {
            return number * number;
        }
        static int CalculateCube(int number)
        {
            return number * number * number;
        }
        static int CalculateFactorial(int number)
        {
            int result = 1;
            for (int i = 1; i <= number; i++)
            {
                result *= i;
            }
            return result;
        }
        static int CombineResults(int square, int cube, int factorial)
        {
            return square + cube + factorial;
        }
        public static async void number2()
        {
            Task<int> task1 = Task.Run(() => CalculateSquare(5));
            Task<int> task2 = Task.Run(() => CalculateCube(3));
            Task<int> task3 = Task.Run(() => CalculateFactorial(4));

            int squareResult = await task1;
            int cubeResult = await task2;
            int factorialResult = await task3;

            Task<int> finalTask = Task.Run(() => CombineResults(squareResult, cubeResult, factorialResult));

            int finalResult = await finalTask;

            Console.WriteLine($"\nрезультат: {finalResult}");

            Task continuation = Task.WhenAll(task1, task2).ContinueWith(t =>
            {
                int squareRes = task1.Result;
                int cubeRes = task2.Result;
                Console.WriteLine($"\nКвадрат: {squareRes}, Куб: {cubeRes}");
                Console.WriteLine($"\nСумма результатов: {squareRes + cubeRes}");
            });

            int task1and2result = task1.GetAwaiter().GetResult() + task2.GetAwaiter().GetResult();
            Console.WriteLine($"Результат через getAwaiter: {task1and2result}");
        }
    }
}
