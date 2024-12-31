using lab6;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;

namespace SportsInventory
{
    public interface IDisplayable
    {
        void DisplayInfo();
        void ShowDetails();
    }

    public abstract partial class Equipment
    {


        public Equipment(string name, string description, double price)
        {
            Name = name;
            Description = description;
            Price = price;
            if (price <= 0)
                throw new CustomException.PriceLessThanZero();
            if (string.IsNullOrWhiteSpace(name))
                throw new CustomException.EquipmentEqualsZero();

        }
        
        public virtual void DisplayInfo()
        {
            Console.WriteLine($"Name: {Name}, Description: {Description}, Price: {Price:C}");
        }

        public abstract void ShowDetails();

        public override string ToString()
        {
            return $"Equipment Type: {GetType().Name}, Name: {Name}, Description: {Description}, Price: {Price:C}";
        }
    }

    public class Ball : Equipment, IDisplayable
    {
        public string Materials { get; set; }

        public Ball(string name, string description, double price, string material)
            : base(name, description, price)
        {
            Materials = material;
            if (material == null)
            {
                throw new CustomException.MaterialsEqualsNull();
            }
        }
         void IDisplayable.DisplayInfo()
        {
            base.DisplayInfo();
            Console.WriteLine("через интерфейс");
        }
        public override void DisplayInfo()
        {
            base.DisplayInfo();
            Console.WriteLine($"Materials: {Materials}");
        }
         void IDisplayable.ShowDetails()
        {
            Console.WriteLine("через интерфейс");
        }
        public override void ShowDetails()
        {
            Console.WriteLine($"Ball Details: Name: {Name}, Material: {Materials}");
        }

        public override string ToString()
        {
            return $"Ball Type: {GetType().Name}, Name: {Name}, Material: {Materials}, Price: {Price:C}";
        }
    }

    public class BasketBall : Ball
    {
        public BasketBall(string brand, double price) : base("Basketball", brand, price, "Synthetic") { }

        public override string ToString()
        {
            return $"BasketBall Type: {GetType().Name}, Name: {Name}, Brand: {Description}, Price: {Price:C}";
        }
    }

    public class Tennis : Ball
    {
        public Tennis(string brand, double price) : base("Tennis Ball", brand, price, "Felt") { }

        public override void ShowDetails()
        {
            Console.WriteLine($"Tennis Ball Details: Name: {Name}, Material: {Materials}");
        }

        public override string ToString()
        {
            return $"Tennis Type: {GetType().Name}, Name: {Name}, Brand: {Description}, Price: {Price:C}";
        }
    }

    public class Bench : Equipment, IDisplayable
    {
        public Bench(string name, string brand, double price) : base(name, brand, price) { }

        public override void ShowDetails()
        {
            Console.WriteLine($"Bench Details: Name: {Name}, Brand: {Description}, Price: {Price:C}");
        }

        public override string ToString()
        {
            return $"Bench Type: {GetType().Name}, Name: {Name}, Brand: {Description}, Price: {Price:C}";
        }
    }

    public class Bars : Equipment, IDisplayable
    {
        public Bars(string name, string brand, double price) : base(name, brand, price) { }

        public override void ShowDetails()
        {
            Console.WriteLine($"Bars Details: Name: {Name}, Brand: {Description}, Price: {Price:C}");
        }

        public override string ToString()
        {
            return $"Bars Type: {GetType().Name}, Name: {Name}, Brand: {Description}, Price: {Price:C}";
        }
    }

    public class Mats : Equipment, IDisplayable
    {
        public Mats(string name, string brand, double price) : base(name, brand, price) { }

        public override void ShowDetails()
        {
            Console.WriteLine($"Mats Details: Name: {Name}, Brand: {Description}, Price: {Price:C}");
        }

        public override string ToString()
        {
            return $"Mats Type: {GetType().Name}, Name: {Name}, Brand: {Description}, Price: {Price:C}";
        }
    }

    public sealed class Printer
    {
        public void IAmPrinting(IDisplayable someObj)
        {
            Console.WriteLine(someObj.ToString());
        }
    }

    public class Inventory : IDisplayable
    {
        public List<IDisplayable> equipmentList = new List<IDisplayable>();
        private int maxItems;
        public Inventory(int maxItems)
        {
            this.maxItems = maxItems;
        }
        public void AddEquipment(IDisplayable equipment)
        {
            equipmentList.Add(equipment);
            if (equipment == null)
            {
                throw new CustomException.EquipmentEqualsZero();
            }
        }
        void IDisplayable.DisplayInfo()
        { 
            Console.WriteLine("через интерфейс");
        }
        void IDisplayable.ShowDetails()
        {
            Console.WriteLine("через интерфейс");
        }

        public void DisplayInventory()
        {
            Printer printer = new Printer();
            foreach (var equipmentItem in equipmentList)
            {
                printer.IAmPrinting(equipmentItem);
            }
        }

        
    }

    public enum EquipmentType
    {
        Ball,
        Bench,
        Bars,
        Mats
    }

    public struct Budget
    {
        public double TotalAmount;
        public double RemainingAmount;
    
        public Budget(double total)
        {
            TotalAmount = total;
            RemainingAmount = total;
        }
    }

    public class Gym
    {
        private List<Equipment> equipmentList = new List<Equipment>();
      
        public int MaxCapacity { get; private set; }
        public Gym(int maxCapacity)
        {
            MaxCapacity = maxCapacity;
            equipmentList = new List<Equipment>();
        }
        public void AddEquipment(Equipment equipment)
        {
            if (equipmentList.Count >= MaxCapacity)
            {
                throw new CustomException("Недостаточно места в спортзале для добавления оборудования.");
            }
            equipmentList.Add(equipment);
        }
        public void DisplayEquipment()
        {
            foreach (var equipment in equipmentList) 
            {
                Console.WriteLine(equipment.ToString());    
            }
        }
        public List<Equipment> GetEquipment()
        {
            return equipmentList;
        }

        public void SetEquipment(List<Equipment> equipment)
        {
            equipmentList = equipment;
        }

        public void SortByPrice()
        {
            equipmentList = equipmentList.OrderBy(e => ((Equipment)e).Price).ToList();
        }

        public List<Equipment> FilterByPrice(double minSum, double maxSum)
        {
            return equipmentList.Where(e => e.Price > minSum && e.Price < maxSum).ToList();
        }
    }

    public class GymController
    {
        private Gym gym;
        private Budget budget;

        public GymController(Gym gym, double totalBudget)
        {
            budget = new Budget(totalBudget);
            this.gym = gym;
        }

        public void AddEquipment(Equipment equipment)
        {
            Debug.Assert(equipment != null, "Оборудование не должно быть null.");
            try
            {
                if (equipment.Price <= 0)
                    throw new CustomException.PriceLessThanZero();
                
                    if (equipment.Price <= budget.RemainingAmount)
                {
                    gym.AddEquipment(equipment);
                    budget.RemainingAmount -= equipment.Price;
                    Console.WriteLine($"Добавлено: {equipment.Name}. Оставшийся бюджет: {budget.RemainingAmount:C}");
                }
                else
                {
                    throw new CustomException("Недостаточно бюджета для добавления этого оборудования.");
                }
            }
            catch (CustomException ex)
            {
                Console.WriteLine($"Ошибка в GymController: {ex.Message}");
                throw; 
            }
        }


        public void SortByPrice()
        {
            gym.SortByPrice();
        }

        public List<Equipment> FilterByPrice(double minSum, double maxSum)
        {
            return gym.FilterByPrice(minSum, maxSum);
        }

        public void DisplayEquipment()
        {
            gym.DisplayEquipment();
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Printer printer = new Printer();
            Gym gym = new Gym(5);
            GymController controller = new GymController(gym, 150);
            try {
                try
                {
                    var basketBall = new BasketBall("Basketball brand", 30);
                    var tennisBall = new Tennis("Tennis brand", 15);
                    var mats = new Mats("Mats", "Mats brand", 5.69);
                    var bars = new Bars("Bars", "Bars brand", 60.2);
                    var bench = new Bench("Bench", "Bench brand", 69.01);


                    controller.AddEquipment(basketBall);
                    controller.AddEquipment(tennisBall);
                    controller.AddEquipment(mats);
                    controller.AddEquipment(bars);
                    controller.AddEquipment(bench);
                }
                catch (CustomException e)
                {
                    Console.WriteLine($"ошибка в main: {e.Message}");
                    Console.WriteLine($"Тип ошибки: {e.GetType().Name}");
                    Console.WriteLine($"Время: {DateTime.Now}");
                    Console.WriteLine($"Трассировка стека: {e.StackTrace}");
                    throw;
                }
            }

            catch (ArgumentNullException e)
            {
                Console.WriteLine($"Ошибка: {e.Message}");
            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.WriteLine($"Ошибка: {e.Message}");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("Вызов finally.");
            }

            Console.WriteLine("\nТекущий инвентарь в спортзале:");
            controller.DisplayEquipment();

            double minSum = 10;
            double maxSum = 50;
            Console.WriteLine($"\nТовары в ценовом диапазоне от {minSum} до {maxSum}: ");
            var betweenMinAndMax = controller.FilterByPrice(minSum, maxSum);
            foreach (var item in betweenMinAndMax)
            {
                if (item is IDisplayable displayableItem)
                    printer.IAmPrinting(displayableItem);
            }
            controller.SortByPrice();
            Console.WriteLine("\nОтсортировано по цене: ");
            controller.DisplayEquipment();

        

            //Inventory inventory = new Inventory(4);
            //
            //inventory.AddEquipment(basketBall);
            //inventory.AddEquipment(tennisBall);
            //inventory.AddEquipment(mats);
            //inventory.AddEquipment(bars);
            //inventory.AddEquipment(bench);
            //
            //Console.WriteLine("Инвентарь:");
            //inventory.DisplayInventory();
            //((IDisplayable)inventory).DisplayInfo();
            //
            //IDisplayable[] items = new IDisplayable[]
            //{
            //    basketBall,
            //    tennisBall,
            //    mats,
            //    bars,
            //    bench
            //};
            //
            //Console.WriteLine("\nВывод всех позиций снаряжения:");
            //foreach (var item in items)
            //{
            //    printer.IAmPrinting(item);
            //}
            //
            //Console.WriteLine("\nПодробности об сняряжении:");
            //
            //
            //if (tennisBall is Ball)
            //{
            //    Console.WriteLine(true);
            //}
            //else
            //{
            //    Console.WriteLine(false);
            //}
            //
            //Ball ball = basketBall as Ball; 
            //if(ball != null)
            //{
            //    Console.WriteLine(true);
            //}
            //else
            //{
            //    Console.WriteLine(false);
            //}
            //
            //Equipment someEquipment = new Bars("Олимпийская перекладина", "Rog", 101);
            //someEquipment.ShowDetails();
        
        }
    }
}