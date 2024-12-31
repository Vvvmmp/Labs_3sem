using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab15
{
    internal class async
    {
        public static async Task asyncMethod()
        {
            Console.WriteLine("запуск асинхронной операции");
            await PerformAsyncOperation();

            Console.WriteLine("асинхронная операция завершена");
        }

        static async Task PerformAsyncOperation()
        {
            await Task.Delay(3000); 
            Console.WriteLine("операция завершена");
        }
    }
}
