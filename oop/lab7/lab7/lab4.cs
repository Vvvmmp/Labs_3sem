using lab7;
using System;
using System.Collections.Generic;
using System.IO;

public interface IDisplayable
{
    void DisplayInfo();
    void ShowDetails();
}

public abstract partial class Equipment
{
    public string Name { get; }
    public string Description { get; }
    public double Price { get; }

    public Equipment(string name, string description, double price)
    {
        Name = name;
        Description = description;
        Price = price;
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

public class Printer
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
        if (equipmentList.Count < maxItems)
        {
            equipmentList.Add(equipment);
        }
        else
        {
            Console.WriteLine("Максимальное количество элементов достигнуто.");
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
