using InputLibrary;

namespace OrganizationsLibrary;

public class Organization : IInit, IComparable, ICloneable
{
    public string Name { get; set; }
    public string Address { get; set; }
    int employeesCount;

    public Manager manager;

    public int EmployeesCount
    {
        get => employeesCount;
        set
        {
            if (value < 0) {
                Console.WriteLine("Количество работников не может быть отрицательным.");
                employeesCount = 0;
            }
            else
                employeesCount = value;
        }
    }

    public Organization(string name, string address, int employeesCount)
    {
        Name = name;
        Address = address;
        EmployeesCount = employeesCount;
        manager = new Manager("");
    }

    public Organization()
    {
        Random rnd = new Random();
        Name = "Организация №" + rnd.Next(1, 100);
        Address = "Адрес №" + rnd.Next(1, 100);
        EmployeesCount = rnd.Next(10, 200);
        manager = new Manager("");
    }

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
    
    public void ShowWithManager()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}\n" +
                          $"Количество сотрудников: {EmployeesCount}\n" +
                          $"Управляющий: {manager.Name}");
        Console.WriteLine();
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
        if (obj is null) return false;

        var item = obj as Organization;
        if (item == null)
            return false;

        return Name == item.Name &&
               Address == item.Address &&
               EmployeesCount == item.EmployeesCount;
    }

    public override int GetHashCode()
    {
        return employeesCount;
    }

    public int CompareTo(object? obj)
    {
        if (obj is null) return 1;
        Organization other = (Organization)obj;
        if (String.Compare(Name, other.Name) > 0) return 1;
        if (String.Compare(Name, other.Name) < 0) return -1;
        if (EmployeesCount > other.EmployeesCount) return 1;
        if (EmployeesCount < other.EmployeesCount) return -1;
        return 0;
    }

    public virtual Organization ShallowCopy()
    {
        return (Organization) this.MemberwiseClone();
    }

    public virtual object Clone()
    {
        var other =  new Organization(Name, Address, EmployeesCount);
        other.manager = new Manager(manager.Name);
        return other;
    }

    public override string ToString()
    {
        return $"Название организации: {Name}\n" +
               $"Адрес организации: {Address}\n" +
               $"Количество сотрудников: {EmployeesCount}\n";
    }
}

public class Manager
{
    public string Name;
    public Manager(string name) => Name = name;
}
