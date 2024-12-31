
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    
    internal class Program
    {
        public class Point : IComparable
        {
            public int x, y, z;
            public Point(int x, int y, int z)
            {
                this.x = x;
                this.y = y;
                this.z = z;
            }
            public int minusX(int x)
            {
                return this.x - x;
            }
            public int plusX(int x)
            {
                return this.x + x;
            }
            public int minusY(int y)
            {
                return this.y - y;
            }
            public int plusY(int y)
            {
                return this.y + y;
            }
            public int minusZ(int z)
            {
                return this.z - z;
            }
            public int plusZ(int z)
            {
                return this.z + z;
            }

            public int CompareTo(object obj)
            {
                if(obj is  Point p)
                {
                    this.x -= p.x;
                    this.y -= p.y;
                    this.z -= p.z;
                    if((this.x > 0 && this.y > 0) || (this.z > 0 && this.y > 0) || (this.x > 0 && this.z > 0))
                    return 1;
                    else return 0;
                }
                else throw new NotImplementedException("не Point");
            }
        }
        static void Main(string[] args)
        {

            int str1 = int.Parse(Console.ReadLine());
            int str2 = int.Parse(Console.ReadLine());
            string result = (str1 + str2).ToString();
            Console.WriteLine(result);

            string[,] arrayStr = { { "abc", "dax", "dasd" }, { "abc", "dasdas", "dsa" }, { "abc", "abc", "abc" } };
            int counter = 0;
            foreach (string i in arrayStr)
            {
                counter += i.Length;
            }
            Console.WriteLine(counter);

            Point point1 = new Point(1, 1, 3);
            Point point2 = new Point(1, 1, 1);

            if(point1.CompareTo(point2) == 1)
            {
                Console.WriteLine("point1 больше");
            }
            else if(point2.CompareTo(point1) == 1) 
            {
                Console.WriteLine("point2 больше"); 
            }
            else { Console.WriteLine("=="); }

            Console.ReadLine();
        }
        
    }
    
}
