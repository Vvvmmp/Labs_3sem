using System;

namespace lab8
{
    public delegate void Upgrade();
    public delegate void Work(string message);
    public abstract class User
    {
        public event Upgrade LvlUp;
        public event Work IsWorking;

        protected string Version { get; set; } = "1.0";
        protected bool IsRunning { get; set; } = false;

        public void UpgradeUser()
        {
            Console.WriteLine("Подготовка к обновлению...");
            LvlUp?.Invoke();
        }

        public void WorkUser(string message)
        {
            Console.WriteLine("Проверка работы...");
            IsWorking?.Invoke(message);
        }
        public abstract void UpgradePO();
        public abstract void WorkPo(string message);
    }

    public class MobileApplication : User
    {
        private string name;
        public MobileApplication(String name) 
        {
            this.name = name;
            LvlUp += () => UpgradePO();
            IsWorking += (msg) => WorkPo(msg);
        }
       public override void UpgradePO()
        {
            Version = "2.0";
            Console.WriteLine($"обновлено ПО на мобильном приложении {name} до версии {Version}");
        }
        public override void WorkPo(string message) 
        {
            IsRunning = true;
            Console.WriteLine($"Мобильное приложение {name}, Статус работы:  {(IsRunning ? "Работает" : "Не работает")}, выполняет: {message}");
        }
    }

    public class PcApplication : User
    {
        private String name;

        public PcApplication(String name)
        {
            this.name = name;

            LvlUp += () => UpgradePO();
            IsWorking += (msg) => WorkPo(msg);
        }
        public override void UpgradePO()
        {
            Version = "2.0";
            Console.WriteLine($"Обновлено ПО на ПК приложении {name} до версии {Version}");
        }

        public override void WorkPo(string message)
        {
            IsRunning = true;
            Console.WriteLine($"ПК приложение {name}, Статус работы: {(IsRunning ? "Работает" : "Не работает")},  выполняет: {message}");
        }
    }

    public class Ide : User
    {
        private string name;

        public Ide(string name)
        {
            this.name = name;

            LvlUp += () => UpgradePO();
            IsWorking += (msg) => WorkPo(msg);
        }

        public override void UpgradePO()
        {
            Version= "2.0";
            Console.WriteLine($"Обновлено ПО на IDE {name} до версии {Version}");
        }

        public override void WorkPo(string message)
        {
            IsRunning = true;
            Console.WriteLine($"IDE {name}, Статус работы: {(IsRunning ? "Работает" : "Не работает")}, выполняет: {message}");
        }
    }
}
