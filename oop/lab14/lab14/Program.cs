using System;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Threading;

namespace lab14
{
    partial class Program
    {
        static void Main(string[] args)
        {
            
            var allProcesses = Process.GetProcesses();
            //foreach (var process in allProcesses)
            //{
            //    try
            //    {
            //        Console.WriteLine($"{process.Id} {process.ProcessName} {process.BasePriority} {process.StartTime}");
            //        TimeSpan diff = DateTime.Now - process.StartTime;
            //        Console.WriteLine($" Использовался по времени:{diff}");
            //    }
            //    catch (Exception ex)
            //    {
            //        Console.WriteLine($"Ошибка при доступе к процессу {process.Id} ({process.ProcessName}): {ex.Message}\n");
            //    }
            //}

            AppDomain currD = AppDomain.CurrentDomain;
            Console.WriteLine($"Информация о текущем домене:");
            Console.WriteLine($"1. Имя: {currD.FriendlyName}");
            Console.WriteLine($"2. Детали конфигурации: {currD.SetupInformation.ConfigurationFile}");
            Console.WriteLine($"3. Все сборки, загруженные в домен:");

            foreach (Assembly asm in currD.GetAssemblies())
            {
                Console.WriteLine($"   - {asm.FullName}");
            }

            AppDomain newD = AppDomain.CreateDomain("new");
            Console.WriteLine($"Создан новый домен: {newD.FriendlyName}");
            //newD.Load($"System.Text.Json.dll");
            Console.WriteLine("Сборка успешно загружена в новый домен");
            AppDomain.Unload(newD);
            Console.WriteLine("Домен успешно выгружен");

            bool pauseThread = false;
            bool stopThread = false;
            Console.WriteLine("Введите n: ");
            if (int.TryParse(Console.ReadLine(), out int n) || n < 2)
            {
                Thread currThread = new Thread(() => FindPrimes(n))
                {
                    Name = "PrimeNumbersThread",
                    Priority = ThreadPriority.Normal
                };


                Console.WriteLine("\nДоступные команды:");
                Console.WriteLine("start  - Запуск потока");
                Console.WriteLine("pause  - Приостановка потока");
                Console.WriteLine("resume - Возобновление потока");
                Console.WriteLine("stop   - Завершение потока");
                Console.WriteLine("status - Статус потока");
                Console.WriteLine("exit   - Выход из программы\n");

                while (true)
                {
                    Console.WriteLine("Введите команду: ");
                    string command = Console.ReadLine().ToLower();

                    switch (command)
                    {
                        case "start":
                            if (currThread.ThreadState == System.Threading.ThreadState.Unstarted)
                            {
                                currThread.Start();
                                Console.WriteLine("Поток запущен");
                            }
                            else
                            {
                                Console.WriteLine("Поток уже запущен");
                            }
                            break;

                        case "pause":
                            pauseThread = true;
                            Console.WriteLine("Поток приостановлен");
                            break;

                        case "resume":
                            pauseThread = false;
                            Console.WriteLine("Поток запущен");
                            break;

                        case "stop":
                            stopThread = true;
                            Console.WriteLine("Поток завершен");
                            break;

                        case "status":
                            Console.WriteLine($"Имя: {currThread.Name}");
                            Console.WriteLine($"Статус: {currThread.ThreadState}");
                            break;

                        case "exit":
                            stopThread = true;
                            if (currThread.IsAlive)
                            {
                                currThread.Join();
                            }
                            Console.WriteLine("Программа завершена");
                            break;

                        default:
                            Console.WriteLine("Неизвестная команда");
                            break;
                    }
                    if (command == "exit")
                    {
                        break;
                    }
                }
            }
            

            using (StreamWriter writer = new StreamWriter("output.txt"))
            {
                Thread evenThread = new Thread(() => PrintEvenNumbers(n, writer))
                {
                    Name = "EvenThread",
                    Priority = ThreadPriority.Highest
                };

                Thread oddThread = new Thread(() => PrintOddNumbers(n, writer))
                {
                    Name = "OddThread",
                    Priority = ThreadPriority.Lowest
                };
                
                evenThread.Start();
                oddThread.Start();

                evenThread.Join();
                oddThread.Join();
            }

            Console.WriteLine("Работа потоков завершена. Результат записан в output.txt.");
            Timer timer1 = new Timer(printTimeToNewYear, null, 0, 1000);


            Console.ReadLine();
        }
    }
}
    
