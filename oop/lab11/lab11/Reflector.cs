using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;

namespace lab11
{
    static class Reflector
    {
        public static void ReflectClass(string className, string fileName)
        {
            Type type = Type.GetType(className);
            if(type == null )
            {
                Console.WriteLine($"Класс {className} не найден");
                return;
            }
            string AssemblyName = type.Assembly.FullName;
            string output = $"1.a  Имя класса: {className}, Имя сборки: {AssemblyName}.\n";
            File.WriteAllText(fileName, output);
            Console.WriteLine($"Информация о классе записана в {fileName}");
        }
        public static void StaticConstructors(string className, string fileName)
        {
            Type type = Type.GetType(className);
            if (type == null)
            {
                Console.WriteLine($"Класс {className} не найден");
                return;
            }

            ConstructorInfo[] constructors = type.GetConstructors(BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic);
            bool ClassHaveStaticConstr = constructors.Length > 0
                ;
            string output = $"1.b  Имя класса: {className}, Наличие статистич. констр.: {ClassHaveStaticConstr}.\n";
            File.AppendAllText(fileName, output);
            Console.WriteLine($"Информация о классе записана в {fileName}");
        }
        public static IEnumerable<string> GetFullPublicMethods(string className)
        {
            Type type = Type.GetType(className);
            if (type == null)
            {
                Console.WriteLine($"Класс {className} не найден");
                return Enumerable.Empty<string>();
            }

            var methods = type.GetMethods(BindingFlags.Public | BindingFlags.Instance | BindingFlags.Static);

            return methods.Select(method =>
            {
                string returnType = method.ReturnType.Name;
                string methodName = method.Name;
                var parameters = method.GetParameters();

                string parameterList = string.Join(", ", parameters.Select(p => $"{p.ParameterType.Name} {p.Name}"));

                return $"{returnType} {methodName}({parameterList})";
            });
        }
        public static void MethodsToFile (string className, string fileName)
        {
            var publicMethods = GetFullPublicMethods(className);

            string methodsOutput = string.Join(", ", publicMethods);
            string output = $"1.c  Имя класса: {className}, Публичные методы: {{{methodsOutput}}}.\n";

            File.AppendAllText (fileName, output); 
            Console.WriteLine($"Информация о классе записана в {fileName}");
        }
        public static void GetFields(string className, string fileName)
        {
            Type type = Type.GetType(className);
            if (type == null)
            {
                Console.WriteLine($"Класс {className} не найден");
                return;
            }
            string output = $"1.d  Имя класса: {className}:.\n";
            File.AppendAllText(fileName, output);

            foreach (FieldInfo i in type.GetFields(BindingFlags.Instance | BindingFlags.Static | BindingFlags.NonPublic | BindingFlags.Public))
            {
                File.AppendAllText(fileName, (i.Name + " "));
            }

            Console.WriteLine($"Информация о классе записана в {fileName}");
        }
        public static void GetInterfaces(string className, string fileName)
        {
            Type type = Type.GetType(className);
            if (type == null)
            {
                Console.WriteLine($"Класс {className} не найден");
                return;
            }
            string output = $"\n1.e  Имя класса: {className}:.\n";
            File.AppendAllText(fileName, output);

            foreach (Type i in type.GetInterfaces())
            {
                File.AppendAllText(fileName, (i.Name + " "));
            }

            Console.WriteLine($"Информация о классе записана в {fileName}");
        }
        public static void GetMethodsByType(string className, string fileName, Type paramType)
        {
            Type type = Type.GetType(className);
            if (type == null)
            {
                Console.WriteLine($"Класс {className} не найден");
                return;
            }

            var methods = type.GetMethods(BindingFlags.Public | BindingFlags.Instance | BindingFlags.Static);


            var filteredMethods = methods.Where(method =>
            method.GetParameters().Any(param => param.ParameterType == paramType));
            string output = $"Имя класса: {className}\n1.f  Методы, содержащие параметр типа {paramType.Name}:\n";

            foreach(var method in filteredMethods)
            {
                string parameters = string.Join(", ", method.GetParameters()
                .Select(p => $"{p.ParameterType.Name} {p.Name}"));
                output += $"{method.ReturnType.Name} {method.Name}.\t";
            }


            File.AppendAllText(fileName, output);
            Console.WriteLine($"Информация о классе записана в {fileName}");
        }
        public static void Invoke(object obj, string fileName)
        {
            string[] fullInfo = File.ReadAllLines(fileName);
            Type type = Type.GetType(fullInfo[0]);
            MethodInfo method = type.GetMethod(fullInfo[1]);
            string[] param = new string[fullInfo.Length -2];
            param[0] = fullInfo[2];
            param[1] = fullInfo[3];

            method.Invoke(obj, param);
        }
        public static T Create<T>() where T : class
        {
            Type type = typeof(T);
            ConstructorInfo constructor = type.GetConstructors(BindingFlags.Public | BindingFlags.Instance).FirstOrDefault();

            return (T)constructor.Invoke(null);
        }
    }
}
