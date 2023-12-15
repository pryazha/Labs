using OrganizationsLibrary;

namespace lab_10
{
    public class Program
    {
        static void Main()
        {
            Console.WriteLine("Часть 1.");

            Organization[] arr = CreateArray(10);
            PrintArrNotVirtual(arr);
            PrintArrVirtual(arr);
            int count = 0;
            foreach (var item in arr)
            {
                if (item is Library)
                    count++;
            }
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

        static Organization[] CreateArray(int size)
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
    }
}
