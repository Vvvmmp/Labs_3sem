using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;

namespace lab7
{
    public class CollectionType<T> : IRepository<T>
    {
        private List<T> items = new List<T>();

        public CollectionType() 
        {
        }

        public void Add(T item) //where T : class
        {
            try
            {
                if (item == null && default(T) == null)
                {
                    throw new ArgumentNullException(nameof(item), "Предмет не может быть равным null.");
                }
                items.Add(item);
            }
            catch (ArgumentNullException ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine("Добавление выполнено.");
            }
        }

        public bool Remove(T item)
        {
            try
            {
                return items.Remove(item);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
                return false;
            }
            finally
            {
                Console.WriteLine("Удаление выполнено.");
            }
        }

        public T View(int index)
        {
            try
            {
                if (index < 0 || index >= items.Count)
                {
                    throw new IndexOutOfRangeException("Выход за предел.");
                }
                return items[index];
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.Message);
                return default; 
            }
            finally
            {
                Console.WriteLine("Просмотр выполнен.");
            }
        }

        public T Find(Func<T, bool> predicate)
        {
            try
            {
                foreach (var item in items)
                {
                    if (predicate(item))
                    {
                        return item;
                    }
                }
                return default;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
                return default;
            }
            finally
            {
                Console.WriteLine("Поиск выполнен.");
            }
        }
    
        public void SaveToFile(string filePath)
        {
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach(var item in items)
                {
                    writer.WriteLine(item.ToString());
                }
            }
            Console.WriteLine("Сохранено в: " + filePath);
        }
        public void LoadFromFile(string filePath)
        {
            if (!File.Exists(filePath))
            {
                Console.WriteLine("Файл не найден: " + filePath);
                return;
            }
            using (StreamReader reader = new StreamReader(filePath))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    if (typeof(T) == typeof(string))
                    {
                        Add((T)(object)line);
                    }
                    else
                    {
                        if (typeof(T) == typeof(int))
                        {
                            if (int.TryParse(line, out int result))
                            {
                                Add((T)(object)result);
                            }
                        }
                        else if (typeof(T) == typeof(double))
                        {
                            if (double.TryParse(line, out double result))
                            {
                                Add((T)(object)result);
                            }
                        }
                    }
                }
            }
            Console.WriteLine("Данные загружены из файла: " + filePath);
        }
     }
}