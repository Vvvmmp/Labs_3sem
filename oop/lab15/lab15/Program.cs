using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lab15
{
    internal class Program
    {
        static void reshetoEratosphena(int n, CancellationToken token)
        {
            if (n < 2) return;
            bool[] numbTrue = new bool[n+1];
            for (int i = 2; i <= n; i++)
            {
                numbTrue[i] = true;
            }

            for (int p = 2; p*p <= n; p++)
            {
                if (numbTrue[p])
                {
                    for (int i = p * p; i <= n; i += p) 
                        numbTrue[i] = false;
                }
            }
            
            Console.WriteLine($"Простые числа до {n}:\n");
            for (int i = 0; i < n; i++)
            {
                if (numbTrue[i]) Console.Write($"{i} ");
            }
            Console.WriteLine();
        }
        static void reshetoEratosphenaWithoutToken(int n)
        {
            if (n < 2) return;
            bool[] numbTrue = new bool[n + 1];
            for (int i = 2; i <= n; i++)
            {
                numbTrue[i] = true;
            }

            for (int p = 2; p * p <= n; p++)
            {
                if (numbTrue[p])
                {
                    for (int i = p * p; i <= n; i += p)
                        numbTrue[i] = false;
                }
            }

            Console.WriteLine($"Простые числа до {n}:\n");
            for (int i = 0; i < n; i++)
            {
                if (numbTrue[i]) Console.Write($"{i} ");
            }
            Console.WriteLine();
        }


        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            CancellationTokenSource token = new CancellationTokenSource();
            
            const int n = 1000;
            Task task = new Task(() => reshetoEratosphenaWithoutToken(n));
            Task taskWithToken = new Task(() => reshetoEratosphena(n, token.Token), token.Token);
            stopwatch.Start();
            task.Start();
            task.Wait();
            stopwatch.Stop();
            Console.WriteLine(task.Status);
            Console.WriteLine(task.IsCompleted ? true : false);
            Console.WriteLine(stopwatch.ElapsedTicks);

            stopwatch.Restart();
            taskWithToken.Start();
            token.Cancel();
            Console.WriteLine("Остановлена задача с помощью токена");
            Console.WriteLine($"Время выполнения с токеном: {stopwatch.ElapsedMilliseconds}");

            threeTasks.number2();
            threeTasks.parallel();

            invoke.invokeMethod();

            zadacha.number6();

            async.asyncMethod();

            Console.ReadLine(); 

        }
    }
}
