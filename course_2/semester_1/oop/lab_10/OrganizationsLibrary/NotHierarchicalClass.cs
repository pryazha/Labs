using InputLibrary;

namespace OrganizationsLibrary;

public class NotHierarchicalClass : IInit
{
    int positiveNumber;

    public int PositiveNumber
    {
        get => positiveNumber;
        set
        {
            if (value < 0)
            {
                Console.WriteLine("Число не может быть отрицательным.");
                positiveNumber = 0;
            }
            else
                positiveNumber = value;
        }
    }

    public void Show()
    {
        Console.WriteLine($"Положительное число: {positiveNumber}");
    }

    public void Init()
    {
        PositiveNumber = Input.IntInput("Введите положительное число: ");
    }

    public void RandomInit()
    {
        var rnd = new Random();
        PositiveNumber = rnd.Next(1, 100);
    }
}
