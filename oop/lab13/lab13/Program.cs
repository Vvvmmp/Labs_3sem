using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using Newtonsoft.Json;
using System.Xml.Serialization;
using System.Xml;
using System.Xml.Linq;

namespace SportsInventory
{
    public interface IDisplayable
    {
        void DisplayInfo();
        void ShowDetails();
    }

    [Serializable] 
    public abstract partial class Equipment
    {
        public string Name { get; set; }
        public string Description { get; set; }
        public double Price { get; set; }

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

    [Serializable] 
    public class Ball : Equipment, IDisplayable
    {
        
        public string Materials { get; set; }

        public Ball() : base("", "", 0.0) { }

        public Ball(string name, string description, double price, string material)
            : base(name, description, price)
        {
            Materials = material;
        }

        public override void DisplayInfo()
        {
            base.DisplayInfo();
            Console.WriteLine($"Materials: {Materials}");
        }

        public override void ShowDetails()
        {
            Console.WriteLine($"Ball Details: Name: {Name}, Material: {Materials}");
        }
    }

    public interface ISerializer
    {
        void Serialize(string filePath, List<Ball> balls);
        List<Ball> Deserialize(string filePath);
    }

    public class JsonSerializer : ISerializer
    {
        public void Serialize(string filePath, List<Ball> balls)
        {
            string jsonString = JsonConvert.SerializeObject(balls, Newtonsoft.Json.Formatting.Indented);
            File.WriteAllText(filePath, jsonString);
        }

        public List<Ball> Deserialize(string filePath)
        {
            string jsonString = File.ReadAllText(filePath);
            return JsonConvert.DeserializeObject<List<Ball>>(jsonString);
        }
    }

    public class XmlSerializer : ISerializer
    {
        public void Serialize(string filePath, List<Ball> balls)
        {
            System.Xml.Serialization.XmlSerializer serializer = new System.Xml.Serialization.XmlSerializer(typeof(List<Ball>));
            using (FileStream fs = new FileStream(filePath, FileMode.Create))
            {
                serializer.Serialize(fs, balls);
            }
        }

        public List<Ball> Deserialize(string filePath)
        {
            System.Xml.Serialization.XmlSerializer serializer = new System.Xml.Serialization.XmlSerializer(typeof(List<Ball>));
            using (FileStream fs = new FileStream(filePath, FileMode.Open))
            {
                return (List<Ball>)serializer.Deserialize(fs);
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            List<Ball> balls = new List<Ball>
            {
                new Ball("Мяч 1", "описание 1", 11.11, "плюш"),
                new Ball("Мяч 2", "описание 2", 22.22, "кожа"),
                new Ball("Мяч 3", "описание 3", 33.33, "синтетика")
            };

            ISerializer jsonSerializer = new JsonSerializer(); 

            string jsonFilePath = "balls.json"; 
            jsonSerializer.Serialize(jsonFilePath, balls);
            Console.WriteLine("Объекты сериализованы в JSON файл.");

            List<Ball> deserializedBalls = jsonSerializer.Deserialize(jsonFilePath);
            Console.WriteLine("Объекты десериализованы из JSON файла:");
            foreach (var ball in deserializedBalls)
            {
                ball.DisplayInfo();
            }

            ISerializer xmlSerializer = new XmlSerializer();

            string xmlFilePath = "balls1.xml";
            xmlSerializer.Serialize(xmlFilePath, balls);
            Console.WriteLine("Объекты сериализованы в XML файл.");

            List<Ball> deserializedBallsXml = xmlSerializer.Deserialize(xmlFilePath);
            Console.WriteLine("Объекты десериализованы из XML файла:");
            foreach (var ball in deserializedBallsXml)
            {
                ball.DisplayInfo();
            }



            XmlDocument doc = new XmlDocument();
            doc.Load("balls1.xml");


            XmlNodeList titles = doc.SelectNodes("/ArrayOfBall/Ball/Name");
            foreach (XmlNode title in titles)
            {
                Console.WriteLine(title.InnerText);
            }

            XmlNodeList expensiveBalls = doc.SelectNodes("/ArrayOfBall/Ball[Price > 20]");
            foreach (XmlNode ball in expensiveBalls)
            {
                Console.WriteLine(ball["Name"].InnerText);
            }

            XDocument ballsDocument = new XDocument(
                new XElement("Balls",
                    new XElement("Ball",
                        new XElement("Name", "Мяч 1"),
                        new XElement("Description", "описание 1"),
                        new XElement("Price", 11.11),
                        new XElement("Materials", "плюш")),
                    new XElement("Ball",
                        new XElement("Name", "Мяч 2"),
                        new XElement("Description", "описание 2"),
                        new XElement("Price", 22.22),
                        new XElement("Materials", "кожа")),
                    new XElement("Ball",
                        new XElement("Name", "Мяч 3"),
                        new XElement("Description", "описание 3"),
                        new XElement("Price", 33.33),
                        new XElement("Materials", "синтетика"))
                )
            );
            ballsDocument.Save("balls1.xml");
            Console.WriteLine("Создан XML-документ: balls1.xml");
            var allBalls = from ball in ballsDocument.Descendants("Ball")
                           select new
                           {
                               Name = ball.Element("Name")?.Value,
                               Description = ball.Element("Description")?.Value,
                               Price = (double)ball.Element("Price"),
                               Materials = ball.Element("Materials")?.Value
                           };

            Console.WriteLine("Все мячи:");
            foreach (var b in allBalls)
            {
                Console.WriteLine($"Name: {b.Name}, Price: {b.Price}");
            }
        }
    }
}