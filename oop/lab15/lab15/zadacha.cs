using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lab15
{
    internal class zadacha
    {
        static void Supplier(string productName, int delay, BlockingCollection<string> warehouse)
        {
            for (int i = 0; i < 3; i++)
            {
                Thread.Sleep(delay);        
                warehouse.Add(productName); 
                Console.WriteLine($"поставщик добавил: {productName}");
                PrintWarehouse(warehouse);
            }
        }
        static void Customer(int customerId, BlockingCollection<string> warehouse)
        {
            while (!warehouse.IsCompleted)
            {
                string product;
                if (warehouse.TryTake(out product, TimeSpan.FromMilliseconds(500))) 
                {
                    Console.WriteLine($"Покупатель {customerId} купил: {product}");
                }
                else
                {
                    Console.WriteLine($"Покупатель {customerId} не нашел товар и ушел");
                }
            }
        }

        static void PrintWarehouse(BlockingCollection<string> warehouse)
        {
            Console.WriteLine("Товары на складе: " + string.Join(", ", warehouse));
        }
        public static void number6() 
        {
            BlockingCollection<string> warehouse = new BlockingCollection<string>();

            List<Task> suppliers = new List<Task>
        {
            Task.Run(() => Supplier("Товар A", 2000, warehouse)),
            Task.Run(() => Supplier("Товар B", 1500, warehouse)),
            Task.Run(() => Supplier("Товар C", 1000, warehouse)),
            Task.Run(() => Supplier("Товар D", 3000, warehouse)),
            Task.Run(() => Supplier("Товар E", 2500, warehouse))
        };
            List<Task> customers = new List<Task>();
            for (int i = 1; i <= 10; i++)
            {
                int customerId = i; 
                customers.Add(Task.Run(() => Customer(customerId, warehouse)));
            }

            Task.WaitAll(suppliers.ToArray());
            warehouse.CompleteAdding();

            Task.WaitAll(customers.ToArray());

            Console.WriteLine("Все покупатели завершили покупки.");
        }
    }
}
