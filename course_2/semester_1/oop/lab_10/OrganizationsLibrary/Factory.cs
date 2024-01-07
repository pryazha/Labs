using InputLibrary;

namespace OrganizationsLibrary;

public class Factory : Organization, IInit, IComparable, ICloneable
{
    int createdProducts;

    public int CreatedProducts
    {
        get {
            return createdProducts;
        }
        set {
            if (value < 0) {
                Console.WriteLine("Количество судов не может быть меньше нуля");
            } else
            {
                createdProducts = value;
            }
        }
    }
    
    public Factory(string name, string address, int employeesCount, int createdProducts)
        : base(name, address, employeesCount)
    {
        CreatedProducts = createdProducts;
    }

    public Factory() => RandomInit();

    public override void Show()
    {
        base.Show();
        Console.WriteLine($"Количество созданных товаров: {CreatedProducts}");
    }

    public void NotVirtualShow()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}\n" +
                          $"Количество сотрудников: {EmployeesCount}\n" +
                          $"Количество созданных товаров: {CreatedProducts}");
    }

    public override void Init()
    {
        base.Init();
        CreatedProducts = Input.IntInput("Введите количество производимых товаров: ");
    }

    public override void RandomInit()
    {
        base.RandomInit();
        Random rnd = new Random();
        Name = "Завод №" + rnd.Next(1, 100);
        CreatedProducts = rnd.Next(1, 100);
    }

    public override Factory ShallowCopy()
    {
        return (Factory)this.MemberwiseClone();
    }

    public override object Clone()
    {
        return new Factory(Name, Address, EmployeesCount, CreatedProducts);
    }
}
