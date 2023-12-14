using InputLibrary;

namespace OrganizationsLibrary;

public class InsuranceCompany : Organization
{
    string InsuranceType { get; set; }
    
    public InsuranceCompany(string name, string address, string insuranceType)
        : base(name, address)
    {
        InsuranceType = insuranceType;
    }

    public InsuranceCompany() => RandomInit();

    public override void Show()
    {
        base.Show();
        Console.WriteLine($"Тип страхования: {InsuranceType}");
    }

    public override void Init()
    {
        base.Init();
        InsuranceType = Input.StringInput("Введите тип страхования: ");
    }

    public override void RandomInit()
    {
        Random rnd = new Random();
        InsuranceType = "Тип страхования №" + rnd.Next(1, 100);
    }
}
