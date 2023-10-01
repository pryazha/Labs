using System;

namespace Lab_1
{
    class Input
    {
        public static int IntInput()
        {
            int number;
            bool isConvert;
            string buf;
            do {
                buf = Console.ReadLine();
                isConvert = int.TryParse(buf, out number);
                if (!isConvert)
                {
                    Console.Write("Неверный тип данных, введите новое значение: ");
                }
            } while (!isConvert);
            return number;
        }

        public static double DoubleInput()
        {
            double number;
            bool isConvert;
            string buf;
            do {
                buf = Console.ReadLine();
                isConvert = double.TryParse(buf, out number);
                if (!isConvert)
                {
                    Console.Write("Неверный тип данных, введите новое значение: ");
                }
            } while (!isConvert);
            return number;
        }

        public static float FloatInput()
        {
            float number;
            bool isConvert;
            string buf;
            do {
                buf = Console.ReadLine();
                isConvert = float.TryParse(buf, out number);
                if (!isConvert)
                {
                    Console.Write("Неверный тип данных, введите новое значение: ");
                }
            } while (!isConvert);
            return number;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            CompleteFirstTask();
            CompleteSecondTask();
            CompleteThirdTask();
        }

        public static void CompleteFirstTask()
        {
            int n, m;
            double x;

            Console.WriteLine("Задача 1:");
            Console.Write("Введите n: ");
            n = Input.IntInput();
            Console.Write("Введите m: ");
            m = Input.IntInput();
            Console.Write("Введите x: ");
            x = Input.DoubleInput();
            
            while (x <= 0 && x >= -1)
            {
                Console.Write("x не может быть в диапазоне от -1 до 0, введите новое значение: ");
                x = Input.DoubleInput();
            }

            double fourExprResult = 5 * Math.Pow(x, 3) * Math.Pow(1/Math.Pow(x, 2) + 1/Math.Pow(x, 3), (double)1/5);

            Console.WriteLine($"\n1) n = {n}, m = {m}, n++*--m = {n++ * --m}");
            Console.WriteLine($"2) n = {n}, m = {m}, n--<m++ = {n-- < m++}");
            Console.WriteLine($"3) n = {n}, m = {m}, --n>--m = {--n > --m}");
            Console.WriteLine($"4) 5x^3(1/x^2 + 1/x^3)^1/5 = {fourExprResult}");
        }

        public static void CompleteSecondTask()
        {
            double x1, y1;
            Console.Write("\nЗадача 2:\nВведите координату x: ");
            x1 = Input.DoubleInput();
            Console.Write("Введите координату y: ");
            y1 = Input.DoubleInput();
            bool inFirstTriangle = y1 - x1 - 5 <= 0 && y1 >= 0 && x1 <= 0;
            bool inSecondTriangle = y1 - x1 + 7 >= 0 && x1 >= 0 && y1 <= 0;
            bool inThirdTriangle = y1 + x1 - 5 <= 0 && y1 >= 0 && x1 >= 0;
            bool result = inFirstTriangle || inSecondTriangle || inThirdTriangle;
            Console.WriteLine(result);
        }

        public static void CompleteThirdTask()
        {
            float a = 1000f, b = 0.0001f;
            float floatTemp1 = (float)Math.Pow(a - b, 2);
            float floatTemp2 = (float)Math.Pow(a, 2) - 2 * a * b;
            float floatTemp3 = (float)Math.Pow(b, 2);
            float floatResult = (floatTemp1 - floatTemp2) / floatTemp3;
            Console.WriteLine("\nЗадача 3:\n((a-b)^2 - (a^2 + 2ab)) / b^2\na = 1000, b = 0.0001");
            Console.WriteLine($"Float: {floatResult}");

            double doubleA = 1000, doubleB = 0.0001;
            double doubleTemp1 = Math.Pow(doubleA - doubleB, 2);
            double doubleTemp2 = Math.Pow(doubleA, 2) - 2 * doubleA * doubleB;
            double doubleTemp3 = Math.Pow(doubleB, 2);
            double doubleResult = (doubleTemp1 - doubleTemp2) / doubleTemp3;
            Console.WriteLine($"Double: {doubleResult}\n");
        }
    }
}

