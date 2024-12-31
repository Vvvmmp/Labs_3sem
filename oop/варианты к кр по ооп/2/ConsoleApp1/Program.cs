
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{

    public class NotImplementedYet : Exception
    {
        public NotImplementedYet(string message) : base(message)
        {

        }
    }
    public interface IAgeable
    {
        int Age();
    }
    public class Book : Author
    {

        public string Genre { get; set; }
        public Book(string name, string birthday, string country, string genre) : base(name, birthday, country)
        {
            this.Genre = genre;
        }

        public override int Age()
        {
            throw (new NotImplementedYet("Исключение из book"));
        }
    }
    public class Author : IAgeable
    {
        public string Name { get; set; }
        public string Birthday { get; set; }
        public string Country { get; set; }

        public Author(string name, string birthday, string country)
        {
            this.Birthday = birthday;
            this.Country = country;
            this.Name = name;
        }

        public override bool Equals(object obj)
        {
            return (this.Name.Equals(((Author)obj).Name) && this.Birthday.Equals(((Author)obj).Birthday));
        }

        public virtual int Age()
        {
            DateTime a = DateTime.Now;
            int yearBirth = Convert.ToInt32((this.Birthday.Split('.'))[2]);

            return a.Year - yearBirth;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {

            string s;

            s = Console.ReadLine();

            string[] arr = s.Split(' ');

            Console.WriteLine(arr[1]);
            Console.ReadLine();

            int[,] matrix = { { 1, 2, 30 }, { 4, 5, 6 } };

            int max = int.MinValue;

            foreach (int i in matrix)
            {
                if (i > max)
                {
                    max = i;
                }
            }

            Console.WriteLine(max);
            Console.ReadLine();


            Author aut1 = new Author("Кирилл", "09.11.2005", "Беларусь");
            Author aut2 = new Author("Кирилл", "09.12.2005", "Германия");


            Console.WriteLine(aut1.Equals(aut2));



            Console.WriteLine(aut2.Age());






            Book b1 = new Book("кирилл", "12.01.2000", "Франция", "Ужастик");

            object[] arr1 = { aut1, aut2, b1 };


            try
            {
                b1.Age();
                aut2.Age();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.ReadLine();
        }
    }
}
