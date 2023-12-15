﻿using InputLibrary;

namespace OrganizationsLibrary;

public class Organization
{
    string name;
    string address;
    int employeesCount;

    public string Name
    {
        get => name;
        set
        {
            if (value == "")
                Console.WriteLine("Название не может быть пустым.");
            else
                name = value;
        }
    }

    public string Address
    {
        get => address;
        set
        {
            if (value == "")
                Console.WriteLine("Адрес не может быть пустым.");
            else
                address = value;
        }
    }

    public int EmployeesCount
    {
        get => employeesCount;
        set
        {
            if (value < 0)
                Console.WriteLine("Количество работников не может быть отрицательным.");
            else
                employeesCount = value;
        }
    }

    public Organization(string name, string address, int employeesCount)
    {
        Name = name;
        Address = address;
        EmployeesCount = employeesCount;
    }

    public Organization() => RandomInit();

    public virtual void Show()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}\n" +
                          $"Количество сотрудников: {EmployeesCount}");
    }

    public void NotVirtualShow()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}\n" +
                          $"Количество сотрудников: {EmployeesCount}");
    }

    public virtual void Init()
    {
        Name = Input.StringInput("Введите название организации: ");
        Address = Input.StringInput("Введите адресс организации: ");
        EmployeesCount = Input.IntInput("Введите количество сотрудников: ");
    }

    public virtual void RandomInit()
    {
        Random rnd = new Random();
        Name = "Организация №" + rnd.Next(1, 100);
        Address = "Адрес №" + rnd.Next(1, 100);
        EmployeesCount = rnd.Next(10, 200);
    }

    public override bool Equals(object? obj) 
    {
        var item = obj as Organization;
        if (item == null)
            return false;
        return Name == item.Name &&
               Address == item.Address &&
               EmployeesCount == item.EmployeesCount;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(Name, Address, EmployeesCount);
    }
}
