using InputLibrary;
using OrganizationsLibrary;

namespace lab_10
{
    public class Program
    {
        static void Main()
        {
            String[] menu = new String[] { "Часть 1. Создание иерархии классов.", "Часть 2. Динамическая идентификация типов.", "Часть 3. Абстрактные классы и интерфейсы." };

            int choose;
            do {
                PrintMenu(menu);
                do {
                    choose = Input.IntInput("> ");
                    if (choose < 0 || choose > menu.Length)
                        Console.WriteLine("Такого выбора не существует");
                } while (choose < 0 || choose > menu.Length);
                switch (choose) {
                    case 1:
                        Task1();
                        break;
                    case 2:
                        Task2();
                        break;
                    case 3:
                        Task3();
                        break;
                }
            } while (choose != 0);
        }

        static void PrintMenu(String[] menu) {
            if (menu.Length == 0) {
                Console.WriteLine("В меню не может не сущестовать вариантов для выбора");
                return;
            }
            for (int i = 0; i < menu.Length; i++)
                Console.WriteLine($"{i + 1}. {menu[i]}");
            Console.WriteLine("0. Выход");
        }

        static void Task1()
        {
            String[] menu = { "Создать массив случайных организаций.", "Вывести массив с помощью не виртуальных функций.",
                              "Вывести массив с помощью виртуальных функций.", "Подсчитать количество объектов типа Library" };
            int choose;
            Organization[] arr = new Organization[0];
            do {
                PrintMenu(menu);
                choose = Input.IntInput("> ");
                switch (choose)
                {
                    case 1:
                        int size;
                        do {
                            size = Input.IntInput("Введите размер массива\n> ");
                            if (size <= 0)
                                Console.WriteLine("Размер массива не может быть меньше или равен 0!");
                        } while (size <= 0);
                        arr = CreateRandomArray(size);
                        break;
                    case 2:
                        PrintArrNotVirtual(arr);
                        break;
                    case 3:
                        PrintArrVirtual(arr);
                        break;
                    case 4:
                        int count = 0;
                        foreach (var item in arr)
                            if (item is Library)
                                count++;
                        Console.WriteLine("В массиве " + count + " объектов типа Library");
                        break;
                    default:
                        Console.WriteLine("Такого выбора не существует");
                        break;
                }
            } while (choose != 0);
        }

        static void Task2()
        {
            String[] menu = { "Создать массив случайных организаций.", "Вывести организацию с наибольшим количеством сотрудников.",
                              "Вывести организацию с наименьшим количеством сотрудников.", "Вывести суммарное количество книг в библиотеках." };
            int choose;
            Organization[] arr = new Organization[0];
            do {
                PrintMenu(menu);
                choose = Input.IntInput("> ");
                switch (choose)
                {
                    case 1:
                        int size;
                        do {
                            size = Input.IntInput("Введите размер массива\n> ");
                            if (size <= 0)
                                Console.WriteLine("Размер массива не может быть равен 0!");
                        } while (size <= 0);
                        arr = CreateRandomArray(size);
                        PrintArrVirtual(arr);
                        break;
                    case 2:
                        Console.WriteLine($"Организация с наибольшим количеством сотрудников:");
                        var max = MaxEmployeesOrg(arr);
                        if (max != null)
                            max.Show();
                        break;
                    case 3:
                        Console.WriteLine($"Организация с наименьшим количеством сотрудников:");
                        var min = MinEmployeesOrg(arr);
                        if (min != null)
                            min.Show();
                        break;
                    case 4:
                        Console.WriteLine($"Суммарное количество книг в библиотеках: {GetBooksCount(arr)}");
                        break;
                    default:
                        Console.WriteLine("Такого выбора не существует");
                        break;
                }
            } while (choose != 0);
        }

        static void Task3()
        {
            String[] menu = { "Создать массив случайных организаций.", "Отсортировать массив.",
                              "Отсортировать массив по количеству сотрудников.", "Поиск по количеству сотрудников.",
                              "Создать массив элементов типа IInit.", "Показать разницу между клонированием и поверхностным копированием объектов." };
            int choose;
            Organization[] arr = new Organization[0];
            do {
                PrintMenu(menu);
                choose = Input.IntInput("> ");
                switch (choose)
                {
                    case 1:
                        int size;
                        do {
                            size = Input.IntInput("Введите размер массива\n> ");
                            if (size <= 0)
                                Console.WriteLine("Размер массива не может быть равен 0!");
                        } while (size <= 0);
                        arr = CreateRandomArray(size);
                        PrintArrVirtual(arr);
                        break;
                    case 2:
                        Console.WriteLine("Отсортированный массив:");
                        Array.Sort(arr);
                        PrintArrVirtual(arr);
                        break;
                    case 3:
                        Console.WriteLine("\nСортировка по количеству сотрудников:");
                        Array.Sort(arr, new SortByEmployeesCount());
                        PrintArrVirtual(arr);
                        break;
                    case 4:
                        int employeesCount;
                        employeesCount = Input.IntInput("Введите количество сотрудников\n> ");
                        var result = BinarySearchByEmployeesCount(arr, employeesCount);
                        if (result != null)
                            result.Show();
                        break;
                    case 5:
                        DisplayIInit();
                        break;
                    case 6:
                        DisplayDiffCopy();
                        break;
                    default:
                        Console.WriteLine("Такого выбора не существует");
                        break;
                }
            } while (choose != 0);
        }

        static void PrintArrVirtual(Organization[] organizations)
        {
            if (organizations.Length == 0) {
                Console.WriteLine("Размер массива не может быть равен 0!");
                return;
            }
            Console.WriteLine("Виртуальный метод:");
            foreach (var item in organizations)
            {
                item.Show();
                Console.WriteLine();
            }
        }

        static void PrintArrNotVirtual(Organization[] organizations)
        {
            if (organizations.Length == 0) {
                Console.WriteLine("Размер массива не может быть равен 0!");
                return;
            }
            Console.WriteLine("Не виртуальный метод: ");
            foreach (var item in organizations)
            {
                item.NotVirtualShow();
                Console.WriteLine();
            }
        }

        public static Organization[] CreateRandomArray(int size)
        {
            if (size <= 0) {
                Console.WriteLine("Размер массива не может быть меньше или равен 0!");
                return new Organization[0];
            }
            Organization[] organizations = new Organization[size];

            for (int i = 0; i < size; i++)
            {
                var rnd = new Random();
                int item = rnd.Next(1, 6);
                switch (item)
                {
                    case 1:
                        organizations[i] = new Organization();
                        break;
                    case 2:
                        organizations[i] = new InsuranceCompany();
                        break;
                    case 3:
                        organizations[i] = new ShipbuildingCompany();
                        break;
                    case 4:
                        organizations[i] = new Factory();
                        break;
                    case 5:
                        organizations[i] = new Library();
                        break;
                }
            }

            return organizations;
        }

        // Организация с наибольшим количеством сотрудников
        public static Organization? MaxEmployeesOrg(Organization[] organizations)
        {
            Organization? max = null;

            if (organizations is null || organizations.Length == 0)
            {
                Console.WriteLine("Массив организаций пуст.");
                return max;
            }

            foreach (var item in organizations)
            {
                if (max is null || item.EmployeesCount > max.EmployeesCount)
                    max = item;
            }

            return max;
        }

        // Организация с наименьшим количеством сотрудников
        public static Organization? MinEmployeesOrg(Organization[] organizations)
        {
            Organization? min = null;

            if (organizations is null || organizations.Length == 0)
            {
                Console.WriteLine("Массив организаций пуст.");
                return min;
            }

            foreach (var item in organizations)
            {
                if (min is null || item.EmployeesCount < min.EmployeesCount)
                    min = item;
            }

            return min;
        }

        // Суммарное количество книг во всех библиотеках
        public static int GetBooksCount(Organization[] organizations)
        {
            if (organizations is null || organizations.Length == 0)
            {
                Console.WriteLine("Массив организаций пуст.");
                return 0;
            }

            int booksCount = 0;
            foreach (var item in organizations)
            {
                if (item is Library)
                {
                    var temp = item as Library;
                    booksCount += temp.BooksCount;
                }
            }

            return booksCount;
        }

        public static Organization? BinarySearchByEmployeesCount(Organization[] organizations, int target)
        {
            if (organizations is null || organizations.Length == 0)
            {
                Console.WriteLine("Массив организаций пуст.");
                return null;
            }

            int left = 0;
            int right = organizations.Length - 1;

            while (left <= right)
            {
                int mid = (left + right) / 2;
                int diff = organizations[mid].EmployeesCount.CompareTo(target);

                if (diff == 0)
                    return organizations[mid];

                if (diff < 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            return null;
        }

        static void DisplayIInit()
        {
            IInit[] objects = new IInit[]
            {
                new Organization(),
                new InsuranceCompany(),
                new ShipbuildingCompany(),
                new Factory(),
                new Library(),
                new NotHierarchicalClass()
            };

            Console.WriteLine("1. RandomInit.\n2. Init.");
            int choose = Input.IntInput("> ");
            foreach (var item in objects) {
                if (choose == 1)
                    item.RandomInit();
                else
                {
                    Console.WriteLine($"Объект типа {item}:");
                    item.Init();
                    Console.WriteLine();
                }
            }

            Console.WriteLine("\nМассив типа IInit: состоит из объектов Organization, InsuranceCompany, ShipbuildingCompany, Factory, Library, NonHierarhicalClass");

            foreach (var item in objects)
            {
                item.Show();
                Console.WriteLine();
            }
        }

        static void DisplayDiffCopy()
        {
            var origOrg = new Organization();
            origOrg.manager = new Manager("Имя управляющего");

            Console.WriteLine("Оригинальный объект:");
            origOrg.ShowWithManager();

            var cloneOrg = (Organization)origOrg.Clone();
            Console.WriteLine("Глубокое копирование:");
            cloneOrg.ShowWithManager();

            Console.WriteLine("Поверхностное копирование:");
            var shallowCopyOrg = origOrg.ShallowCopy();
            shallowCopyOrg.ShowWithManager();

            origOrg.Name = "Новое имя оригинальной организации";
            shallowCopyOrg.manager.Name = "Новое имя управляющего";

            Console.WriteLine("\nОригинальный объект после изменения:");
            origOrg.ShowWithManager();

            Console.WriteLine("Глубокое копирование:");
            cloneOrg.ShowWithManager();

            Console.WriteLine("Поверхностное копирование:");
            shallowCopyOrg.ShowWithManager();
        }
    }
}
