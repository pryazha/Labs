using InputLibrary;

namespace OrganizationsLibrary;

public class Organization
{
    string name;
    string address;

    string Name
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

    string Address
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

    public Organization(string name, string address)
    {
        Name = name;
        Address = address;
    }

    public Organization() => RandomInit();

    public virtual void Show()
    {
        Console.WriteLine($"Название организации: {Name}\n" +
                          $"Адрес организации: {Address}");
    }

    public virtual void Init()
    {
        Name = Input.StringInput("Введите название организации: ");
        Address = Input.StringInput("Введите адресс организации: ");
    }

    public virtual void RandomInit()
    {
        Random rnd = new Random();
        Name = "Организация №" + rnd.Next(1, 100);
        Address = "Адрес №" + rnd.Next(1, 100);
    }

    public override bool Equals(object? obj) 
    {
        var item = obj as Organization;
        if (item == null)
            return false;
        return Name == item.Name && Address == item.Address;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(Name, Address);
    }
}
