using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var studentQueue = new StudentQ<Student>();

            studentQueue.AddStudent(new Student(1, "Андрей", "8-ПИ"));
            studentQueue.AddStudent(new Student(2, "Илья", "5-ЦД"));
            studentQueue.AddStudent(new Student(3, "Иван", "8-ПИ"));
            
            studentQueue.PrintFullStudents();

            studentQueue.RemoveN(2);
            studentQueue.PrintFullStudents();

            studentQueue.AddStudent(new Student(4, "Дима", "1-ИСИТ"));
            studentQueue.AddStudent(new Student(5, "Николай", "2-ИСИТ"));

            Console.WriteLine("\nПоиск студента с ID = 4: ");
            var foundStudent = studentQueue.FindStudent(s => s.Id == 4);
            Console.WriteLine(foundStudent != null ? foundStudent.ToString() : "Студент не найден");

            Console.WriteLine("\nУдаление студента из очереди: ");
            var removedStudent = studentQueue.RemoveStudent();
            Console.WriteLine(removedStudent != null ? $"Удален: {removedStudent}" : "Удаление невозможно");

            var dictionary = new Dictionary<int, string>();
            studentQueue.CopyTo(dictionary, s => new KeyValuePair<int,string>(s.Id, s.Name));

            foreach (var dict in dictionary)
            {
                Console.WriteLine($"Ключ: {dict.Key}, Значение: {dict.Value}");
            }

            var findInDict = 4;

            foreach (var dict in dictionary)
            {
                if(findInDict == dict.Key)
                {
                    Console.WriteLine(dict.Value);
                }
            }

            Console.Write("\n\n\n");

            ObservableCollection<Student> st= new ObservableCollection<Student>();

            st.CollectionChanged += st_Changed;

            st.Add(new Student(1, "Андрей", "8-ПИ"));
            st.Add(new Student(2, "Илья", "5-ЦД"));

            st.RemoveAt(1);
        }
        public static void st_Changed(object a, NotifyCollectionChangedEventArgs e)
        {   
            switch (e.Action)
            {
                case NotifyCollectionChangedAction.Add:
                    Console.WriteLine("Элемент добавлен:");
                    foreach (Student newStudent in e.NewItems)
                    {
                        Console.WriteLine($"  {newStudent}");
                    }
                    break;

                case NotifyCollectionChangedAction.Remove:
                    Console.WriteLine("Элемент удалён:");
                    foreach (Student oldStudent in e.OldItems)
                    {
                        Console.WriteLine($"  {oldStudent}");
                    }
                    break;
            }
        }
    }
}
