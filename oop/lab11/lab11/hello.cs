using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11
{
    public class Hello : IEnumerable<string>
    {
        public int counter = 1;


        public Hello()
        {
            Console.WriteLine("1");
        }


        public void Hello1(string s, string s1)
        {
            Console.WriteLine(s);
            Console.WriteLine(s1);
        }

        private Hello(string s, object a)
        {
            Console.WriteLine("1");
        }
        public Hello(string s)
        {
            Console.WriteLine(s);
        }
        public void hello()
        {
            Console.WriteLine("Hello");
        }

        public IEnumerator<string> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }

}
