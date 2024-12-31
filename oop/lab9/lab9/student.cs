using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab9
{
    public class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Group { get; set; }

        public Student(int id, string name, string group)
        {
            Id = id;
            Name = name;
            Group = group;
        }

        public override string ToString()
        {
            return $"ID: {Id}, Name: {Name}, Group: {Group} ";
        }

    }

    public class StudentQ<T> : IEnumerable<T>
    {
        public Queue<T> students = new Queue<T> ();

        public void AddStudent(T student)
        {
            students.Enqueue (student);
        }

        public T RemoveStudent()
        {
            if(students.Count == null) 
            {
                return default(T);
            }
            return students.Dequeue();
        }

        public T FindStudent(Predicate<T> id)
        {
            foreach (var student in students)
            {
                if( id(student))
                    return student;
            }
            return default(T);
        }

        public void PrintFullStudents()
        {
            if (students.Count == 0)
            {
                return;
            }
            foreach (var student in students)
            {
                Console.WriteLine(student);
            }
        }

        public void CopyTo<U>(ICollection<U> targetCollection, Func<T, U> transform)
        {
            foreach (var student in students)
            {
                targetCollection.Add(transform(student));
            }
        }
        public void RemoveN(int n)
        {
            for(int i = 0; i < n && students.Count>0; i++)
            {
                students.Dequeue();
            }
        }

        public IEnumerator<T> GetEnumerator()
        {
            return students.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }


    }

}
