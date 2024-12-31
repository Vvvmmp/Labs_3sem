using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Hello hello1 = new Hello();
            Reflector.ReflectClass("System.String", "output.txt");
            Reflector.StaticConstructors("System.String", "output.txt");
            Reflector.MethodsToFile("System.String", "output.txt");
            Reflector.GetFields("System.String", "output.txt");
            Reflector.GetInterfaces("System.String", "output.txt");
            Reflector.GetMethodsByType("System.String", "output.txt", typeof(int));

            //Reflector.ReflectClass("lab11.Hello", "output1.txt");
            Reflector.Invoke(hello1, "output1.txt");
           
            Hello hello2 = Reflector.Create<Hello>();
            Console.WriteLine($"{hello2}");
        }
    }
}
