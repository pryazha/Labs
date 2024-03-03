using InputLibrary;

namespace OrganizationsLibrary;

public class ShipbuildingCompany : Organization, IInit, IComparable, ICloneable
{
    int shipsCount;

    public int ShipsCount 
    {
        get {
            return shipsCount;
        }
        set {
            if (value < 0) {
                Console.WriteLine("Количество судов не может быть меньше нуля");
                shipsCount = 0;
            } else
            {
                shipsCount = value;
            }
        }
    }

    public ShipbuildingCompany(string name, string address, int employeesCount, int shipsCount) 
        : base(name, address, employeesCount)
    {
        ShipsCount = shipsCount;
    }

    public ShipbuildingCompany()
    {
        base.RandomInit();
        Random rnd = new Random();
        Name = "Судостроительная компания №" + rnd.Next(1, 100);
        ShipsCount = rnd.Next(1, 100);
    }

    public override void Show()
    {
        base.Show();
        Console.WriteLine($"Количество построенных судов: {ShipsCount}");
    }

    public void NotVirtualShow()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}\n" +
                          $"Количество сотрудников: {EmployeesCount}\n" +
                          $"Количество построенных судов: {ShipsCount}");
    }

    public override void Init()
    {
        base.Init();
        ShipsCount = Input.IntInput("Введите количество построенных судов: ");
    }

    public override void RandomInit()
    {
        base.RandomInit();
        Random rnd = new Random();
        Name = "Судостроительная компания №" + rnd.Next(1, 100);
        ShipsCount = rnd.Next(1, 100);
    }

    public override ShipbuildingCompany ShallowCopy()
    {
        return (ShipbuildingCompany)this.MemberwiseClone();
    }

    public override object Clone()
    {
        var shipComp = new ShipbuildingCompany(Name, Address, EmployeesCount, ShipsCount);
        shipComp.manager = new Manager(manager.Name);
        return shipComp;
    }

    public override string ToString()
    {
        return base.ToString() + $"\nКоличество построенных судов: {ShipsCount}";
    }
}
