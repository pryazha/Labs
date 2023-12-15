using InputLibrary;

namespace OrganizationsLibrary;

public class ShipbuildingCompany : Organization
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

    public ShipbuildingCompany() => RandomInit();

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
        Random rnd = new Random();
        base.RandomInit();
        ShipsCount = rnd.Next(1, 100);
    }
}
