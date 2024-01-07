using InputLibrary;

namespace OrganizationsLibrary;

public class Library : Organization, IInit, IComparable, ICloneable
{
    int booksCount;

    public int BooksCount
    {
        get {
            return booksCount;
        }
        set {
            if (value < 0)
                Console.WriteLine("Количество книг не может быть отрицательным.");
            else
                booksCount = value;
        }
    }

    public Library(string name, string address, int employeesCount, int booksCount)
        : base(name, address, employeesCount)
    {
        BooksCount = booksCount;
    }

    public Library() => RandomInit();

    public override void Show()
    {
        base.Show();
        Console.WriteLine($"Количество книг: {BooksCount}");
    }

    public void NotVirtualShow()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}\n" +
                          $"Количество сотрудников: {EmployeesCount}\n" +
                          $"Количество книг: {BooksCount}");
    }

    public override void Init()
    {
        base.Init();
        BooksCount = Input.IntInput("Введите количество книг: ");
    }

    public override void RandomInit()
    {
        base.RandomInit();
        Random rnd = new Random();
        Name = "Библиотека №" + rnd.Next(1, 100);
        BooksCount = rnd.Next(500, 10000);
    }

    public override Library ShallowCopy()
    {
        return (Library)this.MemberwiseClone();
    }

    public override object Clone()
    {
        return new Library(Name, Address, EmployeesCount, BooksCount);
    }
}
