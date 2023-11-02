namespace lab_6
{
    class Input
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
                    Console.Write("Неверный формат данных, введите новое значение: ");
                }
            } while (!isConvert);
            return number;
        }
    }

    class Program
    {
        static void Main()
        {
            int choose;
            int[,] arr = new int[,] { };
            do
            {
                choose = Input.IntInput('\n' + GetMenu() + "> ");
                choose = CheckSelection(choose, 0, 2);
                if (choose == 1)
                {
                    arr = CreateTwoDimArray();
                    Console.WriteLine("Исходный массив:");
                    PrintArray(arr);
                }
                if (choose == 2)
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
                if (choose == 3)
                {
                    string str = Console.ReadLine();
                }
            } while (choose != 0);
        }

        static int FindLastMinColumn(int[,] arr)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return -1;
            }
            int min = arr[0, 0];
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

        static int[,] DeleteColumn(int[,] arr, int index)
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

        static string GetMenu()
        {
            return "1. Создать массив\n" +
                   "2. Удалить столбец\n" +
                   "3. \n" +
                   "0. Выход\n";
        }

        static int[,] CreateTwoDimArray()
        {
            Console.WriteLine("1. Ввести значения вручную");
            Console.WriteLine("2. Заполнить случайными числами");
            int choose = Input.IntInput("> ");
            choose = CheckSelection(choose, 1, 2);
            int rows = Input.IntInput("Введите количество строк: ");
            while (rows <= 0)
            {
                rows = Input.IntInput("Неверное количество строк, введите новое значение: ");
            }
            int columns = Input.IntInput("Введите количество столбцов: ");
            while (columns <= 0)
            {
                columns = Input.IntInput("Неверное количество столбцов, введите новое значение: ");
            }

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
                number = Input.IntInput("Такого выбора не существует, введите новое значение:\n> ");
            }
            return number;
        }

        static void PrintArray(int[,] arr)
        {
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
