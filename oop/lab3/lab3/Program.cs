using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class Node
    {
        public int Data;
        public Node Next;

        public Node(int data)
        {
        Data = data;
        Next = null;
        }
    }
    public class List
    {
        public Node head;

        public List()
        {
            head = null;
        }
        public void Append(int data)
        {
            Node newNode = new Node(data);
            if (head == null) 
            {
                head = newNode;
                return;
            }

            Node lastNode = head; 
            while (lastNode.Next != null) 
            {
                lastNode = lastNode.Next;
            }
            lastNode.Next = newNode;
        }
        public void PrintList()
        {
            Node currentNode = head;
            while (currentNode != null)
            {
                Console.Write(currentNode.Data + " ");
                currentNode = currentNode.Next;
            }
            Console.WriteLine();
        }
        public static List operator !(List list)
        {
            List invertedList = new List();
            Node currentNode = list.head;

            while (currentNode != null)
            {
                Node newNode = new Node(currentNode.Data);
                newNode.Next = invertedList.head;
                invertedList.head = newNode;
                currentNode = currentNode.Next;
            }
            return invertedList;
        }
        public static List operator +(List list1, List list2)
        {
            List combinedList = new List(); 
            Node currentNode = list1.head;

            while (currentNode != null)
            {
                combinedList.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }

            currentNode = list2.head;
            while(currentNode != null)
            {
                combinedList.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }
            return combinedList;
        }
        public static bool operator ==(List left, List right)
        {
            Node nodeLeft = left.head;
            Node nodeRight = right.head;

            while (nodeLeft != null && nodeRight != null) 
            {
                if (nodeLeft.Data != nodeRight.Data)             
                    return false;

                nodeLeft = nodeLeft.Next;
                nodeRight = nodeRight.Next;               
            }

            return nodeLeft == null && nodeRight == null;
        }
        public static bool operator !=(List left, List right)
        {
            return !(left == right);
        }
        public static List operator <(List left, List right)
        {
            Node currentNode= right.head;

            while( currentNode != null )
            {
                left.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }
            return left;
        }
        public static List operator >(List left, List right) // для <
        {
            Node currentNode = left.head;

            while (currentNode != null)
            {
                right.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }
            return right;
        }

        public class Production
        {
            public int ID;
            public string Name;

            public Production(int id, string name)
            {
                ID = id;
                Name = name;
            }
            public Production Create(int id, string name)
            {
                return new Production(id, name);
            }
        }
        public class Developer
        {
            public int ID;
            public string Name;
            public string FIO;

            public Developer(int id, string name, string fio)
            {
                ID = id;
                Name = name;
                FIO = fio;
            }
            public Developer Create(int id, string name, string fio)
            {
                return new Developer(id, name, fio);
            }
        }
        public static class StatisticOperation
        {
            public static int differenceBetweenMaxAndMin(List list)
            {
                Node node = list.head;
                int max = int.MinValue;
                int min = int.MaxValue;

                while( node != null)
                {
                    if (node.Data < min)
                        min = node.Data;
                    if (node.Data > max)
                        max = node.Data;
                    node = node.Next;
                }

                return max - min;
            }
            public static int CountElements(List list)
            {
                Node currentNode = list.head;
                int count = 0;

                while (currentNode != null)
                {
                    count++;
                    currentNode = currentNode.Next;
                }

                return count;
            }
           
        }
    }
    public static class IntExtensions
    {
        public static int Sum(this List list)
        {
            int sum = 0;
            Node currentNode = list.head;

            while (currentNode != null)
            {
                sum += currentNode.Data;
                currentNode = currentNode.Next;
            }

            return sum;
        }

        public static List Truncate(this List list, int length)
        {
            List truncatedList = new List();
            Node currentNode = list.head;
            int count = 0;

            while (currentNode != null && count < length)
            {
                truncatedList.Append(currentNode.Data);
                currentNode = currentNode.Next;
                count++;
            }
            return truncatedList;
        }
    }
    public static class StringExtensions
    {
        public static string Truncate(this string str, int length)
        {
            if (string.IsNullOrEmpty(str) || length <= 0)
                return string.Empty;

            return str.Length <= length ? str : str.Substring(0, length);
        }
        public static int CountEl(this string str)
        {
            return string.IsNullOrEmpty(str) ? 0 : str.Length;
        }
    }



    internal class Program
    {
        static void Main(string[] args)
        {
            List firstList = new List();
            firstList.Append(1);
            firstList.Append(2);
            firstList.Append(3);

            List secondList = new List();
            secondList.Append(4);
            secondList.Append(5);

            Console.WriteLine("Содержимое первого списка:");
            firstList.PrintList();

            Console.WriteLine("Содержимое второго списка:");
            secondList.PrintList();

            List combinedList = firstList + secondList;
            Console.WriteLine("Объединённый список:");
            combinedList.PrintList();

            List inverseList = !firstList;
            Console.WriteLine("Перевёрнутый список:");
            inverseList.PrintList();

            Console.WriteLine("Cумма элементов 1 списка: " + IntExtensions.Sum(firstList));
            Console.WriteLine("Усечённый список до 4:");
            combinedList.Truncate(4).PrintList();

            List.Production product = new List.Production(15, "abc");           
            Console.WriteLine($"ID: {product.ID}, Name: {product.Name}");;

            List.Developer dev = new List.Developer(10, "8-1","Лужецкий В.К");
            Console.WriteLine($"ID: {dev.ID}, Name: {dev.Name}, FIO: {dev.FIO}");


            Console.WriteLine($"Сумма элементов: {IntExtensions.Sum(combinedList)}");
            Console.WriteLine($"Разница между максимальным и минимальным значениями: {List.StatisticOperation.differenceBetweenMaxAndMin(combinedList)}");
            Console.WriteLine($"Количество элементов в списке: {List.StatisticOperation.CountElements(combinedList)}");

            string ex5 = "abcdefghijklmno";
            Console.WriteLine($"Усечённая строка: {StringExtensions.Truncate(ex5, 5)}");
            Console.WriteLine($"Количество элементов: {StringExtensions.CountEl(ex5)}");

        }
    }
}
