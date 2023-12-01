using System;

namespace lab_5
{
    public class Input
    {
        public static int IntInput(string message)
        {
            int number;
            bool isConvert;
            string buf;
            do
            {
                Console.Write(message);
                buf = Console.ReadLine();
                isConvert = int.TryParse(buf, out number);
                if (!isConvert)
                {
                    Console.WriteLine("Неверный формат данных");
                }
            } while (!isConvert);
            return number;
        }
    }

    class Menu
    {
        public static string GetMainMenu()
        {
            return "\n1. Работа с одномерными массивами\n" +
                "2. Работа с двумерными массивами\n" +
                "3. Работа с рваными массивами\n" +
                "4. Выход\n> ";
        }

        public static string GetFirstTaskMenu()
        {
            return "\n1. Создать массив\n" +
                "2. Напечатать массив\n" +
                "3. Удалить элемент с заданным номером\n" +
                "4. Назад\n> ";
        }
        
        public static string GetSecondTaskMenu()
        {
            return "\n1. Создать массив\n" +
                "2. Напечатать массив\n" +
                "3. Добавить строки после каждой четной строки матрицы\n" +
                "4. Назад\n> ";
        }

        public static string GetThirdTaskMenu()
        {
            return "\n1. Создать массив\n" +
                "2. Напечатать массив\n" +
                "3. Добавить строку в конец массива\n" +
                "4. Назад\n> ";
        }

        public static string GetCreatingArrayMenu()
        {
            return "\n1. Ввести значения вручную\n" +
                "2. Заполнить случайными числами\n> ";
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
                choose = CheckSelection(choose, 1, 4);
                int secondChoose;
                switch (choose)
                {
                    case 1:
                        int[] arr = new int[0];
                        do
                        {
                            secondChoose = Input.IntInput(Menu.GetFirstTaskMenu());
                            secondChoose = CheckSelection(secondChoose, 1, 4);
                            switch (secondChoose)
                            {
                                case 1:
                                    arr = CreateOneDimArray();
                                    PrintArray(arr);
                                    break;

                                case 2:
                                    PrintArray(arr);
                                    break;

                                case 3:
                                    if (arr.Length == 0)
                                    {
                                        Console.WriteLine("Размер массива равен 0!");
                                    }
                                    else
                                    {
                                        int pos = Input.IntInput("Введите номер удаляемого элемента\n> ");
                                        arr = DeleteWithPos(arr, pos);
                                        PrintArray(arr);
                                    }
                                    break;
                            }
                        } while (secondChoose != 4);
                        break;

                    case 2:
                        int[,] twoDimArr = new int[0, 0];
                        do
                        {
                            secondChoose = Input.IntInput(Menu.GetSecondTaskMenu());
                            secondChoose = CheckSelection(secondChoose, 1, 4);
                            switch (secondChoose)
                            {
                                case 1:
                                    twoDimArr = CreateTwoDimArray();
                                    PrintArray(twoDimArr);
                                    break;

                                case 2:
                                    PrintArray(twoDimArr);
                                    break;

                                case 3:
                                    if (twoDimArr.GetLength(0) == 0)
                                    {
                                        Console.WriteLine("Размер массива равен 0!");
                                    }
                                    else
                                    {
                                        twoDimArr = InsertRows(twoDimArr);
                                        PrintArray(twoDimArr);
                                    }
                                    break;
                            }
                        } while (secondChoose != 4);
                        break;

                    case 3:
                        int[][] tornArr = new int[0][];
                        do
                        {
                            secondChoose = Input.IntInput(Menu.GetThirdTaskMenu());
                            secondChoose = CheckSelection(secondChoose, 1, 4);
                            switch (secondChoose)
                            {
                                case 1:
                                    tornArr = CreateTornArray();
                                    PrintArray(tornArr);
                                    break;

                                case 2:
                                    PrintArray(tornArr);
                                    break;

                                case 3:
                                    if (tornArr.GetLength(0) == 0)
                                    {
                                        Console.WriteLine("Размер массива равен 0!");
                                    }
                                    else
                                    {
                                        int columns = Input.IntInput("Введите количество столбцов\n> ");
                                        columns = CheckSelection(columns, 1, 100);
                                        tornArr = AddRowAtEnd(tornArr, columns);
                                        PrintArray(tornArr);
                                    }
                                    break;
                            }
                        } while (secondChoose != 4);
                        break;
                }
            } while (choose != 4);
        }

        public static int[] DeleteWithPos(int[] arr, int pos)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return arr;
            }

            if (pos < 1 || pos > arr.Length)
            {
                Console.WriteLine("Неверный номер!");
                return arr;
            }

            int[] newArr = new int[arr.Length - 1];

            int j = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (i + 1 != pos)
                {
                    newArr[j] = arr[i];
                    j++;
                }
            }

            return newArr;
        }

        public static int[,] InsertRows(int[,] arr)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return arr;
            }

            int newRows = arr.GetLength(0) / 2 + arr.GetLength(0);
            int[,] newArr = new int[newRows, arr.GetLength(1)];

            int row = 0;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    newArr[row, j] = arr[i, j];
                }
                row++;

                if ((i + 1) % 2 == 0)
                {
                    for (int j = 0; j < arr.GetLength(1); j++)
                    {
                        newArr[row, j] = 1;
                    }
                    row++;
                }
            }

            return newArr;
        }

        public static int[][] AddRowAtEnd(int[][] arr, int columns)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return arr;
            }

            int[][] newArr = new int[arr.Length + 1][];
            Random rnd = new Random();

            for (int i = 0; i < arr.Length; i++)
            {
                newArr[i] = new int[arr[i].Length];
                for (int j = 0; j < arr[i].Length; j++)
                {
                    newArr[i][j] = arr[i][j];
                }
            }

            newArr[newArr.Length - 1] = new int[columns];
            for (int i = 0; i < columns; i++)
            {
                newArr[newArr.Length - 1][i] = rnd.Next(0, 20);
            }

            return newArr;
        }

        public static int CheckSelection(int number, int min, int max)
        {
            while (number < min || number > max)
                number = Input.IntInput("Неверное значение\n> ");
            return number;
        }

        public static void PrintArray(int[] arr)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return;
            }
            foreach (int i in arr)
                Console.Write(i + " ");
            Console.WriteLine();
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
                    Console.Write(arr[i, j] + " ");
                Console.WriteLine();
            }
        }

        public static void PrintArray(int[][] arr)
        {
            if (arr.Length == 0)
            {
                Console.WriteLine("Размер массива равен 0!");
                return;
            }
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr[i].Length; j++)
                {
                    Console.Write(arr[i][j] + " ");
                }
                Console.WriteLine();
            }
        }

        public static int[] CreateOneDimArray()
        {
            int choose = Input.IntInput(Menu.GetCreatingArrayMenu());
            choose = CheckSelection(choose, 1, 2);

            int size = Input.IntInput("Введите размер массива\n> ");
            size = CheckSelection(size, 1, 100);

            int[] newArr = new int[size];

            if (choose == 1)
            {
                Console.WriteLine("Введите элементы массива:");
                for (int i = 0; i < size; i++)
                    newArr[i] = Input.IntInput("");
            }
            if (choose == 2)
            {
                Random rnd = new Random();
                for (int i = 0; i < size; i++)
                    newArr[i] = rnd.Next(0, 20);
            }

            return newArr;
        }

        public static int[,] CreateTwoDimArray()
        {
            int choose = Input.IntInput(Menu.GetCreatingArrayMenu());
            choose = CheckSelection(choose, 1, 2);

            int rows = Input.IntInput("Введите количество строк\n> ");
            rows = CheckSelection(rows, 1, 100);

            int columns = Input.IntInput("Введите количество столбцов\n> ");
            columns = CheckSelection(columns, 1, 100);

            int[,] newArr = new int[rows, columns];

            if (choose == 1)
            {
                Console.WriteLine();
                for (int i = 0; i < rows; i++)
                {
                    Console.WriteLine($"Строка {i + 1}:");
                    for (int j = 0; j < columns; j++)
                    {
                        newArr[i, j] = Input.IntInput("");
                    }
                }
            }
            if (choose == 2)
            {
                Random rnd = new Random();
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        newArr[i, j] = rnd.Next(0, 20);
                    }
                }
            }

            return newArr;
        }
        
        public static int[][] CreateTornArray()
        {
            int choose = Input.IntInput(Menu.GetCreatingArrayMenu());
            choose = CheckSelection(choose, 1, 2);

            int rows = Input.IntInput("Введите количество строк\n> ");
            rows = CheckSelection(rows, 1, 100);

            int[][] newTornArr = new int[rows][];
            Random rnd = new Random();

            for (int i = 0; i < rows; i++)
            {
                int columns = Input.IntInput("Введите количество столбцов\n> ");
                columns = CheckSelection(columns, 1, 100);
                newTornArr[i] = new int[columns];
                for (int j = 0; j < columns; j++)
                {
                    if (choose == 1)
                    {
                        newTornArr[i][j] = Input.IntInput("");
                    }
                    else
                    {
                        newTornArr[i][j] = rnd.Next(0, 20);
                    }
                }
            }

            return newTornArr;
        }
    }
}
