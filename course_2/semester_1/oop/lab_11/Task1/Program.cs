﻿using System.Collections;

using InputLibrary;
using OrganizationsLibrary;

namespace MainProgram;

class Program
{
    static void Main()
    {
        String[] menu = new String[] {
            "Добавить объект.",
            "Удалить объект.",
            "Вывести все объекты",
            "Вывести все объекты типа Library.",
            "Подсчитать количество объектов типа ShipbuildingCompany.",
            "Подсчитать количество сотрудников объектов типа Factory.",
            "Найти заданный элемент."
        };

        Hashtable hashtable = new Hashtable();

        int choose;
        String key;
        do
        {
            PrintMenu(menu);
            choose = Input.IntInput("> ");
            switch (choose)
            {
                case 1:
                    Organization org = new Organization();
                    key = Input.StringInput("Введите ключ: ");
                    if (hashtable.ContainsKey(key))
                    {
                        Console.WriteLine("Объект с таким ключом уже существует.\n");
                        break;
                    }

                    int orgChoose;
                    do
                    {
                        Console.WriteLine("1. Случайный объект.\n2. Создать объект вручную");
                        orgChoose = Input.IntInput("> ");
                        if (choose < 1 || choose > 2)
                            Console.WriteLine("Такого выбора не существует.");
                    } while (orgChoose < 1 || orgChoose > 2);

                    if (orgChoose == 1)
                        org = CreateRandomOrg();
                    else
                        org = CreateManualOrg();

                    hashtable.Add(key, org);
                    Console.WriteLine($"Объект {org} успешно добавлен.\n");
                    break;

                case 2:
                    DeleteItem(ref hashtable);
                    break;

                case 3:
                    PrintHashtable(hashtable);
                    break;

                case 4:
                    PrintHashtableLibraries(hashtable);
                    break; 

                case 5:
                    CountShipbuildCompanies(hashtable);
                    break;

                case 6:
                    CountEmployeesOfFactoriesHashtable(hashtable);
                    break;

                case 7:
                    if (hashtable.Count == 0)
                    {
                        Console.WriteLine("Хеш-таблица не содержит объектов.\n");
                        break;
                    }
                    Organization findingOrg = CreateManualOrg();
                    if (hashtable.ContainsValue(findingOrg))
                        Console.WriteLine("Хеш-таблица содержит заданную организацию.\n");
                    else
                        Console.WriteLine("Хеш-таблица не содержит заданной организации.\n");
                    break;

                default:
                    if (choose != 0)
                        Console.WriteLine("Такого выбора не существует.");
                    break;
            }
        } while (choose != 0);

        /*
        hashtable = new Hashtable();
        hashtable.Add("key", new Organization());
        hashtable.Add("another_key", new Organization());
        Console.WriteLine("Оригинальная хеш-таблица:");
        PrintHashtable(hashtable);

        Hashtable newHashtable = (Hashtable)hashtable.Clone();
        Console.WriteLine("Новая клонированная хеш-таблица:");
        PrintHashtable(newHashtable);

        Organization? item = (Organization?)newHashtable["key"];
        if (item != null)
            item.Name = "New organization name";

        Console.WriteLine("Старая хеш-таблица после изменения названия объекта с ключом \"key\" новой хеш-таблицы:");
        PrintHashtable(hashtable);
        Console.WriteLine("Новая хеш-таблица:");
        PrintHashtable(newHashtable);
        */
    }

    static Organization CreateRandomOrg() {
        var rnd = new Random();
        int item = rnd.Next(1, 6);
        Organization org = new Organization();;
        switch (item)
        {
            case 1:
                org = new Organization();
                break;
            case 2:
                org = new InsuranceCompany();
                break;
            case 3:
                org = new ShipbuildingCompany();
                break;
            case 4:
                org = new Factory();
                break;
            case 5:
                org = new Library();
                break;
        }
        return org;
    }

    static Organization CreateManualOrg()
    {
        int choose;
        do 
        {
            Console.WriteLine(
                "1. Organization.\n" +
                "2. InsuranceCompany.\n" +
                "3. ShipbuildingCompany.\n" +
                "4. Factory.\n" +
                "5. Library.");
            choose = Input.IntInput("> ");
            if (choose < 1 || choose > 5)
                Console.WriteLine("Такого выбора не существует.");
        } while (choose < 1 || choose > 5);

        Organization org = new Organization();
        switch (choose) 
        {
            case 1:
                org.Init();
                break;
            case 2:
                org = new InsuranceCompany();
                org.Init();
                break;
            case 3:
                org = new ShipbuildingCompany();
                org.Init();
                break;
            case 4:
                org = new Factory();
                org.Init();
                break;
            case 5:
                org = new Library();
                org.Init();
                break;
        }
        return org;
    }
    
    static void DeleteItem(ref Hashtable hashtable)
    {
        if (hashtable.Count == 0)
        {
            Console.WriteLine("Хеш-таблица не содержит объектов.\n");
            return;
        }
        String key = Input.StringInput("Введите ключ: ");
        if (hashtable.ContainsKey(key))
        {
            hashtable.Remove(key);
            Console.WriteLine("Объект удален.\n");
        }
        else
            Console.WriteLine("Объекта с таким ключем не существует.\n");
    }

    static void PrintMenu(String[] menu)
    {
        for (int i = 0; i < menu.Length; i++)
            Console.WriteLine($"{i + 1}. {menu[i]}");
        Console.WriteLine("0. Выход");
    }

    static void PrintHashtable(Hashtable hashtable)
    {
        if (hashtable.Count == 0)
        {
            Console.WriteLine("Хеш-таблица не содержит объектов.\n");
            return;
        }

        foreach (DictionaryEntry item in hashtable)
        {
            String key = (String)item.Key;
            Organization? org = (Organization?)item.Value;
            Console.WriteLine($"Key: {key}");
            if (org != null)
                org.Show();
            else
                Console.WriteLine("Организация пуста");
            Console.WriteLine();
        }
    }

    static void PrintHashtableLibraries(Hashtable hashtable)
    {
        if (hashtable.Count == 0)
        {
            Console.WriteLine("Хеш-таблица не содержит объектов.\n");
            return;
        }

        foreach (DictionaryEntry item in hashtable)
        {
            String key = (String) item.Key;
            Organization? org = (Organization?)item.Value;
            int count = 0;
            if (org != null)
            {
                if (org is Library)
                {
                    Console.WriteLine($"Key: {key}");
                    org.Show();
                    count++;
                }
            }
            if (count == 0)
                Console.WriteLine("Хеш-таблица не содержит объектов типа Library.");
            Console.WriteLine();
        }
    }

    static void CountShipbuildCompanies(Hashtable hashtable)
    {
        if (hashtable.Count == 0)
        {
            Console.WriteLine("Хеш-таблица не содержит объектов.\n");
            return;
        }

        int count = 0;
        foreach (var value in hashtable.Values)
        {
            if (value is ShipbuildingCompany)
                count++;
        }

        if (count == 0)
            Console.WriteLine("Хеш-таблица не содержит объектов типа ShipbuildingCompany.\n");
        else
            Console.WriteLine($"Количество объектов типа ShipbuildingCompany: {count}.\n");
    }

    static void CountEmployeesOfFactoriesHashtable(Hashtable hashtable)
    {
        if (hashtable.Count == 0)
        {
            Console.WriteLine("Хеш-таблица не содержит объектов.\n");
            return;
        }

        int employeesCount = 0;
        foreach (var value in hashtable.Values)
        {
            if (value is Factory)
            {
                Factory factory = (Factory) value;
                employeesCount += factory.EmployeesCount;
            }
        }

        if (employeesCount == 0)
            Console.WriteLine("Хеш-таблица не содержит объектов типа Factory.\n");
        else
            Console.WriteLine($"Количество всех сотрудников типа Factory: {employeesCount}\n");
    }

    static bool FindOrganizationInHashtable(Hashtable hashtable, Organization target)
    {
        foreach (var org in hashtable.Values)
        {
            if (org.Equals(target))
                return true;
        }
        return false;
    }
}