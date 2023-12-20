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
                Console.WriteLine("Число не может быть отрицательным.");
            else
                positiveNumber = value;
        }
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
