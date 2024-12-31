using System;


namespace lab8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            User mobileApp = new MobileApplication("Мобильное приложение");
            User pcApp = new PcApplication("Пк приложение");
            User ide = new Ide("Среда разработки");

            mobileApp.UpgradeUser();
            mobileApp.WorkUser("Сборка проекта");

            pcApp.UpgradeUser();
            pcApp.WorkUser("Запуск приложения");

            ide.UpgradeUser();
            ide.WorkUser("Запуск отладки");

            Console.WriteLine();
            Console.WriteLine();

            StringProcessing processor = new StringProcessing();
            string origStr = "Hello hell he";
            string prefix = "hihi";
            string oldword = "hell";
            string word = "hill";

            Console.WriteLine(processor.ProcessString(origStr, prefix, oldword, word));
        }
    }
}
