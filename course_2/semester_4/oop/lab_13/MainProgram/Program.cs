using OrganizationsLibrary;

namespace MainProgram;

class Program
{
    static void Main()
    {
        var hs1 = new MyNewCollection<Organization>("first", 2);
        var hs2 = new MyNewCollection<Organization>("second", 2);
        Journal<Organization> jr1 = new Journal<Organization>();

        hs1.CollectionCountChanged +=
            new CollectionHandler<Organization>(jr1.CollectionCountChanged);
        hs1.CollectionReferenceChanged +=
            new CollectionHandler<Organization>(jr1.CollectionReferenceChanged);

        Journal<Organization> jr2 = new Journal<Organization>();
        hs1.CollectionReferenceChanged +=
            new CollectionHandler<Organization>(jr2.CollectionReferenceChanged);
        hs2.CollectionReferenceChanged +=
            new CollectionHandler<Organization>(jr2.CollectionReferenceChanged);

        var org = new Organization();
        var lib = new Library();
        hs1.Add(org);
        hs1.Add(lib);
        hs1.Remove(org.Name);
        hs1[lib.Name] = new Factory();
        Console.WriteLine(hs1.Name);
        hs1.Print();

        var ship_comp = new ShipbuildingCompany();
        hs2.Add(org);
        hs2.Add(ship_comp);
        hs2.Remove(org.Name);
        hs2[ship_comp.Name] = new Organization();
        Console.WriteLine("\n" + hs2.Name);
        hs2.Print();

        Console.WriteLine("Журнал 1:");
        jr1.Print();
        Console.WriteLine("Журнал 2:");
        jr2.Print();
    }
}
