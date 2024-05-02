using InputLibrary;
using MyCollection;
using OrganizationsLibrary;

namespace MainProgram;

public class Program
{
    public static void Main()
    {
        string[] menu = {
            "Создать хеш-таблицу.",
            "Вывести хеш-таблицу.",
            "Добавить элемент.",
            "Удалить элемент.",
            "Найти элемент",
            "Вывод с помощью foreach",
        };

        var hst = new MyGenericHashtable<int, Organization>(1);
        int choice;
        do
        {
            PrintMenu(menu);
            choice = Input.IntInput("> ");
            switch(choice)
            {
                case 1:
                    int size = Input.IntInput("Введите размер: ");
                    hst = CreateRandomHst(size);
                    break;

                case 2:
                    hst.Print();
                    break;

                case 3:
                {
                    int key = Input.IntInput("Введите ключ: ");
                    Organization org = new Organization();
                    org.Init();
                    if (hst.Add(key, org))
                    {
                        Console.WriteLine("Элемент успешно добавлен.");
                    }
                    else
                    {
                        Console.WriteLine("Не удалось добавить элемент.");
                    }
                } break;

                case 4:
                {
                    int key = Input.IntInput("Введите ключ: ");
                    if (hst.Remove(key))
                    {
                        Console.WriteLine("Элемент успешно удален.");
                    }
                    else
                    {
                        Console.WriteLine("Не удалось удалить элемент.");
                    }
                } break;

                case 5:
                {
                    int key = Input.IntInput("Введите ключ: ");
                    if (hst[key] != null)
                    {
                        Console.WriteLine(hst[key] + "\n");
                    }
                } break;

                case 6:
                {
                    foreach (var item in hst)
                        Console.WriteLine(item);
                } break;

                case 0:
                    break;
                default:
                    Console.WriteLine("Такого выбора не существует.");
                    break;
            }
            Console.WriteLine();
        } while (choice != 0);
    }

    static void PrintMenu(string[] menu)
    {
        for (int i = 0; i < menu.Length; ++i)
            Console.WriteLine($"{i + 1}. {menu[i]}");
        Console.WriteLine("0. Выход");
    }

    static MyGenericHashtable<int, Organization> CreateRandomHst(int size)
    {
        var result = new MyGenericHashtable<int, Organization>(size);
        for (int i = 0; i < size; i++)
        {
            var rnd = new Random();
            int item = rnd.Next(1, 6);
            switch (item)
            {
                case 1:
                    result.Add(i, new Organization());
                    break;
                case 2:
                    result.Add(i, new InsuranceCompany());
                    break;
                case 3:
                    result.Add(i, new ShipbuildingCompany());
                    break;
                case 4:
                    result.Add(i, new Factory());
                    break;
                case 5:
                    result.Add(i, new Library());
                    break;
            }
        }
        return result;
    }
}
