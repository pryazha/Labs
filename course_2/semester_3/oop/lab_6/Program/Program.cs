using System.Text.RegularExpressions;

namespace lab_6
{
    public class Input
    {
        public static int IntInput(string message)
        {
            int number;
            bool isConvert;
            do
            {
                Console.Write(message);
                isConvert = int.TryParse(Console.ReadLine(), out number);
                if (!isConvert)
                {
                    Console.WriteLine("Неверный формат данных");
                }
            } while (!isConvert);
            return number;
        }
    }

    public class Menu
    {
        public static string GetMainMenu()
        {
            return "\n1. Первая задача\n" +
                "2. Вторая задача\n" +
                "0. Выход\n> ";
        }

        public static string GetFirstTaskMenu()
        {
            return "\n1. Создать массив\n" +
                "2. Удалить из массива последний столбец, в котором встречается элемент, совпадающий с минимальным элементом массива\n" +
                "0. Назад\n> ";
        }

        public static string GetSecondTaskMenu()
        {
            return "\n1. Ввести строку\n" +
                "2. Создать случайную строку\n" +
                "3. Вывести самый короткий идентификатор\n" +
                "0. Назад\n> ";
        }
    }

    public class Program
    {
        static void Main()
        {
            int choose;
            do
            {
                choose = Input.IntInput(Menu.GetMainMenu());
                choose = CheckSelection(choose, 0, 2);
                int secondChoose;
                if (choose == 1)
                {
                    int[,] arr = new int[,] { };
                    do
                    {
                        secondChoose = Input.IntInput(Menu.GetFirstTaskMenu());
                        secondChoose = CheckSelection(secondChoose, 0, 2);
                        if (secondChoose == 1)
                        {
                            arr = CreateTwoDimArray();
                            Console.WriteLine("Исходный массив:");
                            PrintArray(arr);
                        }
                        if (secondChoose == 2)
                        {
                            if (arr.Length == 0)
                            {
                                Console.WriteLine("Размер массива равен 0!");
                            }
                            else
                            {
                                int column = FindLastMinColumn(arr);
                                arr = DeleteColumn(arr, column);
                                PrintArray(arr);
                            }
                        }
                    } while (secondChoose != 0);
                }
                if (choose == 2)
                {
                    string str = "";
                    do
                    {
                        secondChoose = Input.IntInput(Menu.GetSecondTaskMenu());
                        secondChoose = CheckSelection(secondChoose, 0, 3);
                        if (secondChoose == 1)
                        {

                            Console.Write("Введите строку: ");
                            str = Console.ReadLine()??string.Empty;
                            if (str == "")
                            {
                                Console.WriteLine("Строка не может быть пустой, введите новую строку:");
                                str = Console.ReadLine()??string.Empty;
                            }
                        }
                        if (secondChoose == 2)
                        {
                            int length = Input.IntInput("Введите длину строки\n> ");
                            Random rnd = new Random();
                            str = GenerateRandomString(rnd, length);
                            Console.WriteLine(str);
                        }
                        if (secondChoose == 3)
                        {
                            Console.WriteLine(FindShortestId(str));
                        }
                    } while (secondChoose != 0);
                }
            } while (choose != 0);
        }

        public static string GenerateRandomString(Random rnd, int length)
        {
            if (length <= 0)
            {
                Console.WriteLine("Неверная длина строки");
                return "";
            }
            string legalCharacters = " _,.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            char[] letters = new char[length];
            for (int i = 0; i < length; i++)
            {
                letters[i] = legalCharacters[rnd.Next(0, legalCharacters.Length)];
            }
            return new string(letters);
        }

        public static string FindShortestId(string str)
        {
            if (str.Length == 0)
            {
                Console.WriteLine("Строка пустая!");
                return "";
            }

            string pattern = @"\b[a-zA-Z_][a-zA-Z0-9_]*\b";
            Regex regex = new Regex(pattern);
            MatchCollection matches = regex.Matches(str);

            if (matches.Count == 0)
            {
                Console.WriteLine("В строке нет идентификаторов");
                return "";
            }

            string shortestId = matches[0].Value;

            foreach (Match match in matches)
            {
                if (match.Value.Length < shortestId.Length)
                {
                    shortestId = match.Value;
                }
            }
            
            return shortestId;
        }

        public static int FindLastMinColumn(int[,] arr)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return -1;
            }

            int min = arr[0,0];
            int column = 0;

            for (int j = 0; j < arr.GetLength(1); j++)
            {
                for (int i = 0; i < arr.GetLength(0); i++)
                {
                    if (arr[i, j] <= min)
                    {
                        min = arr[i, j];
                        column = j;
                    }
                }
            }

            return column;
        }

        public static int[,] DeleteColumn(int[,] arr, int index)
        {
            if (index < 0 || index >= arr.GetLength(1))
            {
                Console.WriteLine("Некорректный номер столбца");
                return arr;
            }

            int[,] newArr = new int[arr.GetLength(0), arr.GetLength(1) - 1];
            int column = 0;

            for (int j = 0; j < arr.GetLength(1); j++)
            {
                int row = 0;
                for (int i = 0; i < arr.GetLength(0); i++)
                {
                    if (j != index)
                        newArr[row, column] = arr[i, j];
                    row++;
                }
                if (j != index)
                    column++;
            }

            return newArr;
        }

        static int[,] CreateTwoDimArray()
        {
            int choose = Input.IntInput("1. Ввести значения вручную\n2. Заполнить случайными числами\n> ");
            choose = CheckSelection(choose, 1, 2);

            int rows = Input.IntInput("Введите количество строк\n> ");
            rows = CheckSelection(rows, 1, 100);

            int columns = Input.IntInput("Введите количество столбцов\n> ");
            columns = CheckSelection(columns, 1, 100);

            int[,] newArr = new int[rows, columns];

            Random rnd = new Random();
            Console.WriteLine();
            for (int i = 0; i < rows; i++)
            {
                if (choose == 1)
                    Console.WriteLine($"Строка {i + 1}:");
                for (int j = 0; j < columns; j++)
                {
                    if (choose == 1)
                        newArr[i, j] = Input.IntInput("");
                    else
                        newArr[i, j] = rnd.Next(0, 20);
                }
            }

            return newArr;
        }

        static int CheckSelection(int number, int min, int max)
        {
            while (number < min || number > max)
            {
                number = Input.IntInput("Неверное значение\n> ");
            }
            return number;
        }

        public static void PrintArray(int[,] arr)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return;
            }
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    Console.Write(arr[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }
    }
}
