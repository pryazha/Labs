using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;

using InputLibrary;
using OrganizationsLibrary;
using Lab11_libs;

namespace MainProgram;

class Program
{
    static void Main()
    {
        string[] menu = new string[] {
            "Создать объект типа TestCollections.",
            "Добавить заданный объект.",
            "Удалить заданный объект.",
            "Вывести элементы коллекций.",
            "Измерить время поиска элементов"
        };

        TestCollections test = new TestCollections(0);
        int choose;
        do
        {
            PrintMenu(menu);
            choose = Input.IntInput("> "); 
            switch (choose)
            {
                case 1:
                    int size;
                    do
                    {
                        size = Input.IntInput("Введите количество объектов: ");
                        if (size <= 0)
                            Console.WriteLine("Количество объектов не может быть меньше или равен 0.\n");
                    } while (size <= 0);
                    test = new TestCollections(size);
                    Console.WriteLine("TestCollections успешно создан.\n");
                    break;

                case 2:
                    AddItemTestCollections(test);
                    break;

                case 3:
                    DeleteItemTestCollections(test);
                    break;

                case 4:
                    PrintCollections(test);
                    break;

                case 5:
                    DisplayMeasurmentTime(test);
                    break;

                default:
                    if (choose != 0)
                        Console.WriteLine("Такого выбора не существует.\n");
                    break;
            }
        } while (choose != 0);
    }

    static void PrintMenu(string[] menu)
    {
        for (int i = 0; i < menu.Length; i++)
            Console.WriteLine($"{i + 1}. {menu[i]}");
        Console.WriteLine("0. Выход.");
    }

    static void AddItemTestCollections(TestCollections test)
    {
        if (test.Count == 0)
        {
            Console.WriteLine("TestCollections не содержит объектов.\n");
            return;
        }
        Library lib = new Library();
        lib.Init();
        bool isAdded = test.Add(lib);
        if (isAdded)
            Console.WriteLine("Объект успешно добавлен.\n");
        else
            Console.WriteLine("Объект не удалось добавить.\n");
    }

    static void DeleteItemTestCollections(TestCollections test)
    {
        if (test.Count == 0)
        {
            Console.WriteLine("TestCollections не содержит объектов.\n");
            return;
        }
        Library lib = new Library();
        lib.Init();
        bool isDeleted = test.Delete(lib);
        if (isDeleted)
            Console.WriteLine("Объект успешно удален.\n");
        else
            Console.WriteLine("Такой библиотеки не существует в TestCollections.\n");
    }

    static void PrintCollections(TestCollections test)
    {
        if (test.Count == 0)
        {
            Console.WriteLine("TestCollections не содержит объектов.\n");
            return;
        }

        foreach (string item in test.strStack)
        {
            Console.WriteLine(item + '\n');
        }
    }

    static void DisplayMeasurmentTime(TestCollections test)
    {
        if (test.Count == 0)
        {
            Console.WriteLine("TestCollections не содержит объектов.\n");
            return;
        }

        Organization[] stackArr = test.orgStack.ToArray();
        Console.WriteLine("Коллекция Stack<Organization>:");
        Console.WriteLine("Первый элемент: {0}", FindItemStack(test.orgStack, (Organization)stackArr[0].Clone()));
        Console.WriteLine("Центральный элемент: {0}", FindItemStack(test.orgStack, (Organization)stackArr[stackArr.Length / 2].Clone()));
        Console.WriteLine("Последний элемент: {0}", FindItemStack(test.orgStack, (Organization)stackArr[stackArr.Length - 1].Clone()));
        Console.WriteLine("Элемент, не входящий в коллекцию: {0}", FindItemStack(test.orgStack, new Organization()));
        Console.WriteLine();

        string[] strStackArr = test.strStack.ToArray();
        Console.WriteLine("Коллекция Stack<string>:");
        Console.WriteLine("Первый элемент: {0}", FindItemStack(test.strStack, (string)strStackArr[0].Clone()));
        Console.WriteLine("Центральный элемент: {0}", FindItemStack(test.strStack, (string)strStackArr[stackArr.Length / 2].Clone()));
        Console.WriteLine("Последний элемент: {0}", FindItemStack(test.strStack, (string)strStackArr[stackArr.Length - 1].Clone()));
        Console.WriteLine("Элемент, не входящий в коллекцию: {0}", FindItemStack(test.strStack, ""));
        Console.WriteLine();

        string[] strKeys = test.strDict.Keys.ToArray();
        Console.WriteLine("Коллекция Dictionary<string, Library>:");
        Console.WriteLine("Первый ключ: {0}", FindItemWithKeyDict(test.strDict, (string)strKeys[0].Clone()));
        Console.WriteLine("Центральный ключ: {0}", FindItemWithKeyDict(test.strDict, (string)strKeys[strKeys.Length / 2].Clone()));
        Console.WriteLine("Последний ключ: {0}", FindItemWithKeyDict(test.strDict, (string)strKeys[strKeys.Length - 1].Clone()));
        Console.WriteLine("Ключ, не входящий в коллекцию: {0}", FindItemWithKeyDict(test.strDict, ""));
        Console.WriteLine();

        Organization[] orgsKeys = test.orgDict.Keys.ToArray();
        Console.WriteLine("Коллекция Dictionary<Organization, Library>:");
        Console.WriteLine("Первый ключ: {0}", FindItemWithKeyDict(test.orgDict, (Organization)orgsKeys[0].Clone()));
        Console.WriteLine("Центральный ключ: {0}", FindItemWithKeyDict(test.orgDict, (Organization)orgsKeys[orgsKeys.Length / 2].Clone()));
        Console.WriteLine("Последний ключ: {0}", FindItemWithKeyDict(test.orgDict, (Organization)orgsKeys[orgsKeys.Length - 1].Clone()));
        Console.WriteLine("Ключ, не входящий в коллекцию: {0}", FindItemWithKeyDict(test.orgDict, new Organization()));
        Console.WriteLine();

        Organization[] orgValues = test.orgDict.Values.ToArray();
        Console.WriteLine("Коллекция Dictionary<Organization, Library>:");
        Console.WriteLine("Первый элемент: {0}", FindItemWithValueDict(test.orgDict, (Library)orgValues[0].Clone()));
        Console.WriteLine("Центральный элемент: {0}", FindItemWithValueDict(test.orgDict, (Library)orgValues[orgValues.Length / 2].Clone()));
        Console.WriteLine("Последний элемент: {0}",FindItemWithValueDict(test.orgDict, (Library)orgValues[orgValues.Length - 1].Clone())); 
        Console.WriteLine("Элемент, не входящий в коллекцию: {0}", FindItemWithKeyDict(test.orgDict, new Library()));
        Console.WriteLine();
    }

    static string FindItemStack<T>(Stack<T> stack, T target)
    {
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        bool isFound = stack.Contains(target);
        stopwatch.Stop();
        string found;
        if (isFound)
            found = "Найден. ";
        else
            found = "Не найден. ";
        return found + "Затраченное время (такты): " + stopwatch.ElapsedTicks.ToString();
    }

    static string FindItemWithKeyDict<K, T>(Dictionary<K, T> dict, K target) where K: notnull
    {
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        bool isFound = dict.ContainsKey(target);
        stopwatch.Stop();
        string found;
        if (isFound)
            found = "Найден. ";
        else
            found = "Не найден. ";
        return found + "Затраченное время (такты): " + stopwatch.ElapsedTicks.ToString();
    }

    static string FindItemWithValueDict<K, T>(Dictionary<K, T> dict, T target) where K: notnull
    {
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        bool isFound = dict.ContainsValue(target);
        stopwatch.Stop();
        string found;
        if (isFound)
            found = "Найден. ";
        else
            found = "Не найден. ";
        return found + "Затраченное время (такты): " + stopwatch.ElapsedTicks.ToString();
    }
}
