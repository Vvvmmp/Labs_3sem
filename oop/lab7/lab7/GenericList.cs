//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

//namespace lab7
//{
//    public class GenericList<T> : IRepository<T>
//    {
//        private List<T> items = new List<T>();

//        public void Add(T item)
//        {
//            items.Add(item);
//        }

//        public bool Remove(T item)
//        {
//            return items.Remove(item);
//        }

//        public T View(int index)
//        {
//            if (index < 0 || index >= items.Count)
//            {
//                throw new IndexOutOfRangeException("Выход за предел");
//            }
//            return items[index];
//        }
//    }
//}
