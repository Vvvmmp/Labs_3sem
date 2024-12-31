using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab7
{
    public interface IRepository<T>
    {
        void Add(T item);
        bool Remove(T item);
        T View(int index);
        T Find(Func<T, bool> predicate);
    }
}
