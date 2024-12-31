using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LVKLog logger = new LVKLog();
            LVKDiskInfo diskInfo = new LVKDiskInfo(logger);

            string fullInfo = diskInfo.GetFullInfo();

            Console.WriteLine(fullInfo);
            Console.WriteLine(logger.ReadLogs());
            
            //Console.WriteLine("Поиск по слову 'C' ");
            //string[] searchResult = logger.SearchLogs("C");
            //foreach (string s in searchResult)
            //{
            //    Console.WriteLine(s);
            //}

            LVKFileInfo file1 = new LVKFileInfo(logger, @"C:\labi\3sem\oop\lab12\lab12\bin\Debug\file1.txt");
            string fullInfo1 = file1.GetFullInfo();
            Console.WriteLine(fullInfo1);

            LVKDirInfo dir1 = new LVKDirInfo(logger, @"C:\labi\3sem\oop\lab12\lab12\bin");
            string fullInfo2 = dir1.GetFullInfo();
            Console.WriteLine(fullInfo2);

            var log = new LVKLog("log.txt");
            var fileManager = new LVKFileManager(log, @"C:\labi\3sem\oop\lab12");

            string userPath = @"C:\labi\3sem\oop";
            string extension = ".txt";

            string result = fileManager.GetFullInfo(userPath, extension);
            Console.WriteLine(result);

            DateTime startTime = new DateTime(2024, 11, 29, 0, 0, 0);  
            DateTime endTime = new DateTime(2024, 12, 29, 0, 0, 0);
            string[] results = logger.SearchByTime(startTime, endTime);
            Console.WriteLine($"Поиск от {startTime} до {endTime}: ");
            foreach (var logs in results)
            {
                Console.WriteLine(logs);
            }


            Console.WriteLine($"Найдено записей: {results.Length}");
        }
    }
}
