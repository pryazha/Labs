using InputLibrary;

namespace OrganizationsLibrary;

public class InsuranceCompany : Organization, IInit, IComparable, ICloneable
{
    string InsuranceType { get; set; }
    
    public InsuranceCompany(string name, string address, int employeesCount, string insuranceType)
        : base(name, address, employeesCount)
    {
        InsuranceType = insuranceType;
    }

    public InsuranceCompany() => RandomInit();

    public override void Show()
    {
        base.Show();
        Console.WriteLine($"Тип страхования: {InsuranceType}");
    }

    public void NotVirtualShow()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}\n" +
                          $"Количество сотрудников: {EmployeesCount}\n" +
                          $"Тип страхования: {InsuranceType}");
    }

    public override void Init()
    {
        base.Init();
        InsuranceType = Input.StringInput("Введите тип страхования: ");
    }

    public override void RandomInit()
    {
        base.RandomInit();
        Random rnd = new Random();
        InsuranceType = "Тип страхования №" + rnd.Next(1, 100);
    }

    public override InsuranceCompany ShallowCopy()
    {
        return (InsuranceCompany)this.MemberwiseClone();
    }

    public override object Clone()
    {
        return new InsuranceCompany(Name, Address, EmployeesCount, InsuranceType);
    }
}
