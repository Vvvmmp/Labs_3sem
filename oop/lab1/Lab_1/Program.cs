using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Lab_1
{
    internal class Program
    {
        static (int, int, int, string) test(int[] arrayTest, string strTest)
        {
            int maxEl = 0;
            int minEl = 11111;
            int sumEl = 0;
            string firstStrEl;
            for (int i = 0; i < arrayTest.Length; i++)
            {
                if (arrayTest[i] > maxEl)
                {
                    maxEl = arrayTest[i];
                }
                if (arrayTest[i] < minEl) { 
                    minEl = arrayTest[i]; 
                }
                sumEl += arrayTest[i];
            }
            firstStrEl = strTest.Substring(0, 1);
           
            var result = (maxEl, minEl, sumEl, firstStrEl);

            return result;
        }

        static void Main(string[] args)
        {
            bool type1 = false;
            Console.WriteLine(type1 ? "true" : "false");
            bool inputType1 = Convert.ToBoolean(Console.ReadLine());
          
            sbyte type2 = 127;
                                                                                 short type21 = type2; //неявное
                                                                                 int type22 = type21;
                                                                                 long type23 = type22;
                                                                                 decimal type24 = type23;
            Console.WriteLine(type2);
            sbyte inputType2 = Convert.ToSByte(Console.ReadLine());
          
            short type3 = 128;
            Console.WriteLine(type3);
            short inputType3 = Convert.ToInt16(Console.ReadLine());
          
            int type4 = 32768;
                                                                                byte type41 = (byte)type4;
                                                                                short type42 = (short)type4;
                                                                                uint type43 = (uint)type4;
                                                                                long type44 = (long)type4;
          
            Console.WriteLine(type4);
            int inputType4 = Convert.ToInt32(Console.ReadLine());
                                                                                object Boxing = type4; //из стека в кучу
                                                                                type4 = (int)Boxing;
            long type5 = 1;
            Console.WriteLine(type5);
            long inputType5 = Convert.ToInt64(Console.ReadLine());
                                                                                object Boxing2 = type5; 
                                                                                type5 = (long)Boxing2;
            byte type6 = 255;
            Console.WriteLine(type6);
            byte inputType6 = Convert.ToByte(Console.ReadLine());
                                                                                 var ex1d = 1;  // в int
                                                                                 var ex1d1 = new[] {1, 2, 3}; // в int[]
                                                                                 var ex1d2 = "sttttrrrr";   // в string
            ushort type7 = 5;
            Console.WriteLine(type7);
            ushort inputType7 = Convert.ToUInt16(Console.ReadLine());
                                                                                int? variableNull = null;   // = null
                                                                                variableNull = 125;         // = 125
            uint type8 = 1;
            Console.WriteLine(type8);
            uint inputType8 = Convert.ToUInt32(Console.ReadLine());
                                                                                var ex1f = 'c'; // var навсегда, а object можно менять
                                                                                // ex1f = "hello";
            ulong type9 = 255;
            Console.WriteLine(type9);
            ulong inputType9 = Convert.ToUInt64(Console.ReadLine());
          
            float type10 = 4.12F;
            Console.WriteLine(type10);
            float inputType10 = Convert.ToSingle(Console.ReadLine());
          
            double type11 = 12.5D;
            Console.WriteLine(type11);
            double inputType11 = Convert.ToDouble(Console.ReadLine());
          
            char type12 = 'a';
            Console.WriteLine(type12);
            char inputType12 = Convert.ToChar(Console.ReadLine());
          
            decimal type13 = 3.12M;
            Console.WriteLine(type13);
            decimal inputType13 = Convert.ToDecimal(Console.ReadLine());
          
            string type14 = "hello";
            Console.WriteLine(type14);
            string inputType14 = Convert.ToString(Console.ReadLine());
          
            object type15 = "15";
            Console.WriteLine(type15);
            object inputType15 = Convert.ToString(Console.ReadLine());
          
            string lit1 = "hi hi hi";
            string lit2 = "hi1";
            string lit3 = lit1 + lit2; // сцепление
            string[] litSplit = lit1.Split(' ');
            string insertLit = lit2.Insert(2, "XX"); // вставка с 2
            string removeLit = insertLit.Remove(3, 2); //удаление с 3, длинною в 2 символа
            lit2 = string.Copy(lit1);
            lit1 = lit2.Substring(2); // выделение подстроки
            bool result = (lit1 == lit2) ? true : false;
          
            string emptyStr = "";
            string nullStr = null;
            Console.WriteLine(string.IsNullOrEmpty(nullStr));
            string combined = emptyStr + nullStr; //пустая строка как результат
          
            StringBuilder strBld = new StringBuilder("Hell");
            strBld.Append("o");
            strBld.Insert(0, "hi ");
            strBld.Remove(0, 3);
          
            int[,] matrix = {
                {1, 2, 3, },
                {5, 6, 7, },
                {8, 9, 10 }
            };
          
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for(int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write(matrix[i, j] + ' ');
                }
                Console.WriteLine();
            }
           int[] array = { 1, 2, 3, 4 };
           array[2] = 5;
           for (int i = 0; i < array.Length; i++)
           {
               Console.WriteLine(array[i]);
           }
           Console.WriteLine(array.Length);
          

            float[][] stepArray = new float[3][];

            for (int i = 0;i < stepArray.Length; i++)
            {
                Console.WriteLine($"Кол-во элементов для подмассива {i+ 1}: ");
                int size = int.Parse(Console.ReadLine());
                stepArray[i] = new float[size];
                for(int j = 0;j < stepArray[i].Length; j++)
                {
                    Console.WriteLine($"Элемент {j+1}: ");
                    stepArray[i][j] = float.Parse(Console.ReadLine());
                  
                }
            }
            Console.WriteLine();
            for (int i = 0; i < stepArray.Length; i++)
            {
                for (int j = 0; j < stepArray[i].Length; j++)
                {
                    Console.Write(stepArray[i][j] + ' ');
                }
                Console.WriteLine() ;
            }

            var strVar = "123";
            var arrayVar = new int[] { 1, 2, 3, };

            var tuple = ( 1, "123", 'h', "312", 2);
            (int, string, char, string, int) tuple1 = (1, "123", '2', "123", 5);
            Console.WriteLine(tuple.Item1);
            Console.WriteLine(tuple.Item2);
            Console.WriteLine(tuple.Item3);
            Console.WriteLine(tuple.Item4);
            Console.WriteLine(tuple.Item5);
            
            var(firstItemTuple, _, _, _, _) = tuple; 
            if ( tuple == tuple1)
            {
                Console.WriteLine("кортежи равны");
            }
            else
            {
                Console.WriteLine("Кортежи не равны");
            }

            test(array, "hello");

            void CheckedOperation()
            {
                checked
                {
                    try
                    {

                        int maxValue = int.MaxValue;
                        int result0 = maxValue + 1;
                    }
                    catch (OverflowException)
                    {

                        Console.WriteLine("Checked: Переполнение.");
                    }
                }
            }


            void UncheckedOperation()
            {
                unchecked
                {
                    int maxValue = int.MaxValue;

                    int result0 = maxValue + 1;
                    Console.WriteLine($"Unchecked: Результат переполнения {result0}");
                }
            }


            CheckedOperation();
            UncheckedOperation();
        


        }
    }
}
