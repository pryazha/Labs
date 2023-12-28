using InputLibrary;
using OrganizationsLibrary;

namespace lab_10
{
    public class Program
    {
        static void Main()
        {
            String[] menu = new String[] { "Часть 1.", "Часть. 2", "Часть. 3" };

            Organization[] arr = CreateRandomArray(10);
            PrintArrNotVirtual(arr);
            PrintArrVirtual(arr);
            int count = 0;
            foreach (var item in arr)
                if (item is Library)
                    count++;
            Console.WriteLine("В массиве " + count + " объектов типа Library");

            Console.WriteLine("\nЧасть 2.");
            Console.WriteLine($"Организация с наибольшим количеством сотрудников:");
            var max = MaxEmployeesOrg(arr);
            if (max != null)
                max.Show();
            Console.WriteLine($"Организация с наименьшим количеством сотрудников:");
            var min = MinEmployeesOrg(arr);
            if (min != null)
                min.Show();
            Console.WriteLine($"Суммарное количество книг в библиотеках: {GetBooksCount(arr)}");
            Console.WriteLine("\nОтсортированный массив:");
            Array.Sort(arr);
            PrintArrVirtual(arr);

            Console.WriteLine("\nЧасть 3.");
            Console.WriteLine("\nСортировка по количеству сотрудников:");
            Array.Sort(arr, new SortByEmployeesCount());
            PrintArrVirtual(arr);

            int employeesCount;
            do
            {
                employeesCount = Input.IntInput("Введите количество сотрудников (0 - выйти)\n> ");
                if (count != 0)
                {
                    var result = BinarySearchByEmployeesCount(arr, employeesCount);
                    if (result != null)
                        result.Show();
                    else 
                        Console.WriteLine("Организации с таким количеством сотрудников не существует.");
                }
            } while (employeesCount != 0);

            DisplayIInit();
        }

        static void MainMenu(String[] menu) {
            for (int i = 0; i < menu.Length; i++)
                Console.WriteLine($"{i + 1} : {menu[i]}");
        }

        static void PrintArrVirtual(Organization[] organizations)
        {
            Console.WriteLine("Виртуальный метод:");
            foreach (var item in organizations)
            {
                item.Show();
                Console.WriteLine();
            }
        }

        static void PrintArrNotVirtual(Organization[] organizations)
        {
            Console.WriteLine("Не виртуальный метод: ");
            foreach (var item in organizations)
            {
                item.NotVirtualShow();
                Console.WriteLine();
            }
        }

        static Organization[] CreateRandomArray(int size)
        {
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
        static Organization? MaxEmployeesOrg(Organization[] organizations)
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
        static Organization? MinEmployeesOrg(Organization[] organizations)
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
        static int GetBooksCount(Organization[] organizations)
        {
            if (organizations is null || organizations.Length == 0)
            {
                Console.WriteLine("Массив организаций пуст.");
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

        static Organization? BinarySearchByEmployeesCount(Organization[] organizations, int target)
        {
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

            Console.WriteLine("\nМассив типа IInit: состоит из объектов Organization, InsuranceCompany, ShipbuildingCompany, Factory, Library, NonHierarhicalClass");

            int count = 1;
            foreach (var item in objects)
            {
                Console.WriteLine($"Создается объект под номером {count++}: {item.GetType()}");
                item.RandomInit();
                Console.WriteLine(item + "\n");
            }
        }

        static void DisplayDiffCopy()
        {
            var origOrg = CreateRandomArray(5);
            var copyOrg = (Organization) origOrg.Clone();

        }
    }
}
