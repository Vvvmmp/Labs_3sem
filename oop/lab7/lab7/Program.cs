using System;
using System.Collections.Generic;

namespace lab7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            CollectionType<int> intCollection = new CollectionType<int>();
            intCollection.Add(1);
            intCollection.Add(2);
            intCollection.Add(3);
            intCollection.SaveToFile("intCollection.txt");

            CollectionType<int> loadedIntCollection = new CollectionType<int>();
            loadedIntCollection.LoadFromFile("intCollection.txt");
            Console.WriteLine("Просмотр int на индексе 1: " + loadedIntCollection.View(1));

            CollectionType<double> doubleCollection = new CollectionType<double>();
            doubleCollection.Add(1.1);
            doubleCollection.Add(2.2);
            doubleCollection.Add(3.3);
            Console.WriteLine("Просмотр double на индексе 0: " + doubleCollection.View(0));

            CollectionType<string> stringCollection = new CollectionType<string>();
            stringCollection.Add("Hello");
            stringCollection.Add("World");
            Console.WriteLine("Просмотр строки на индексе 0: " + stringCollection.View(0));
            var foundItem = stringCollection.Find(item => item.StartsWith("H"));
            Console.WriteLine("Поиск слова, начинающегося с 'H': " + foundItem);

            var inventory = new Inventory(10);

            CollectionType<Ball> ballCollection = new CollectionType<Ball>();
            var basketball = new BasketBall("Nike", 29.99);
            var tennisBall = new Tennis("Wilson", 19.99);

            ballCollection.Add(basketball);
            ballCollection.Add(tennisBall);

            inventory.AddEquipment(basketball);
            inventory.AddEquipment(tennisBall);

            inventory.DisplayInventory();

            ballCollection.SaveToFile("balls.txt");

            CollectionType<Ball> loadedBallCollection = new CollectionType<Ball>();
            loadedBallCollection.LoadFromFile("balls.txt");
            Console.WriteLine("Просмотр мяча на индексе 0: " + loadedBallCollection.View(0));











            //List firstList = new List();
            //firstList.Append(1);
            //firstList.Append(2);
            //firstList.Append(3);
            //
            //List secondList = new List();
            //secondList.Append(4);
            //secondList.Append(5);
            //
            //Console.WriteLine("Содержимое первого списка:");
            //firstList.PrintList();
            //
            //Console.WriteLine("Содержимое второго списка:");
            //secondList.PrintList();
            //
            //List combinedList = firstList + secondList;
            //Console.WriteLine("Объединённый список:");
            //combinedList.PrintList();
            //
            //List inverseList = !firstList;
            //Console.WriteLine("Перевёрнутый список:");
            //inverseList.PrintList();
            //
            //Console.WriteLine("Cумма элементов 1 списка: " + IntExtensions.Sum(firstList));
            //Console.WriteLine("Усечённый список до 4:");
            //combinedList.Truncate(4).PrintList();
            //
            //Production product = new Production(15, "abc");
            //Console.WriteLine($"ID: {product.ID}, Name: {product.Name}");
            //
            //Developer dev = new Developer(10, "8-1", "Лужецкий В.К");
            //Console.WriteLine($"ID: {dev.ID}, Name: {dev.Name}, FIO: {dev.FIO}");
            //
            //Console.WriteLine($"Сумма элементов: {IntExtensions.Sum(combinedList)}");
            //Console.WriteLine($"Разница между максимальным и минимальным значениями: {StatisticOperation.differenceBetweenMaxAndMin(combinedList)}");
            //Console.WriteLine($"Количество элементов в списке: {StatisticOperation.CountElements(combinedList)}");
            //
            //string ex5 = "abcdefghijklmno";
            //Console.WriteLine($"Усечённая строка: {StringExtensions.Truncate(ex5, 5)}");
            //Console.WriteLine($"Количество элементов: {StringExtensions.CountEl(ex5)}");
        }
    }
}