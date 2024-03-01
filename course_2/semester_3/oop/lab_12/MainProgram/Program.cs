using InputLibrary;
using MyCollection;
using OrganizationsLibrary;

namespace MainProgram;

public class Program
{
    public static void Main()
    {
        /*
        string[] menu = {
            "Создать хеш-таблицу.",
            "Вывести хеш-таблицу.",
            "Добавить элемент.",
            "Удалить элемент.",
            "Найти элемент",
        };
        MyHashtable hstable = new MyHashtable();
        int choice;
        do
        {
            PrintMenu(menu);
            choice = Input.IntInput("> ");
            switch(choice)
            {
                case 1:
                    int size = Input.IntInput("Введите размер: ");
                    hstable = CreateRandomMyHashtable(size);
                    break;

                case 2:
                    hstable.Print();
                    break;

                case 3:
                {
                    if (hstable.size == 0)
                    {
                        Console.WriteLine("Хеш-таблица пуста.");
                        break;
                    }
                    int key = Input.IntInput("Введите ключ: ");
                    Organization value = new Organization();
                    value.Init();
                    if (hstable.Add(key, value))
                    {
                        Console.WriteLine("Элемент успешно добавлен.");
                    }
                } break;

                case 4:
                {
                    if (hstable.size == 0)
                    {
                        Console.WriteLine("Хеш-таблица пуста.");
                        break;
                    }
                    int key = Input.IntInput("Введите ключ: ");
                    hstable.Delete(key);
                } break;

                case 5:
                {
                    if (hstable.size == 0)
                    {
                        Console.WriteLine("Хеш-таблица пуста.");
                        break;
                    }
                    int key = Input.IntInput("Введите ключ: ");
                    hstable.Find(key);
                } break;

                case 0:
                    break;
                default:
                    Console.WriteLine("Такого выбора не существует.");
                    break;
            }
            Console.WriteLine();
        } while (choice != 0);
        */

        // TODO(pryazha): Now I just want to implement MyGenericHashtable, after that I can make a working menu.
        MyGenericHashtable<int, Organization> hst = new MyGenericHashtable<int, Organization>(1);
        hst.Add(0, new Library());
        Console.WriteLine("Hst:");
        hst.Print();
    }

    static void PrintMenu(string[] menu)
    {
        for (int i = 0; i < menu.Length; ++i)
            Console.WriteLine($"{i + 1}. {menu[i]}");
        Console.WriteLine("0. Выход");
    }

    static MyHashtable CreateRandomMyHashtable(int size)
    {
        MyHashtable result = new MyHashtable(size);
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
