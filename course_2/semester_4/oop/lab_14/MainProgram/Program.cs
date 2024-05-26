using OrganizationsLibrary;
using MyCollection;

namespace MainProgram;

class Program
{
    static void Main(string[] args)
    {
        var sortDict = new SortedDictionary<Organization, Queue<Library>>();
        FillSortDictionary(sortDict, 2, 3);

        Console.WriteLine("Sorted Dictionary elements:");
        foreach (var item in sortDict)
        {
            Console.WriteLine("Key:\n" + item.Key);
            Console.WriteLine("Queue elements:");
            foreach (var value in item.Value)
                Console.WriteLine(value);
            Console.WriteLine();
        }

        FirstQuery(sortDict);
        SecondQuery(sortDict);
        ThirdQuery(sortDict);
        FourthQuery(sortDict);
        FifthQuery(sortDict);

        var hs = new MyGenericHashtable<Organization>(5);
        FillHashtable(hs, 5);
        Console.WriteLine("Hashtable elements:");
        foreach (var item in hs) {
            Console.WriteLine(item.Value);
            Console.WriteLine();
        }

        FirstMethod(hs);
        SecondMethod(hs);
        ThirdMethod(hs);
    }

    static void FillQueue(Queue<Library> queue, int queueSize)
    {
        for (int i = 0; i < queueSize; ++i)
            queue.Enqueue(new Library());
    }

    static void FillSortDictionary(SortedDictionary<Organization, Queue<Library>> sortDict, int dictSize, int queueSize)
    {
        for (int i = 0; i < dictSize; ++i)
        {
            var newQueue = new Queue<Library>();
            FillQueue(newQueue, queueSize);
            sortDict.Add(new Organization(), newQueue);
        }
    }

    static void FillHashtable(MyGenericHashtable<Organization> hs, int size)
    {
        for (int i = 0; i < size; i++)
        {
            var rnd = new Random();
            int item = rnd.Next(1, 6);
            switch (item)
            {
                case 1:
                    hs.Add(new Organization());
                    break;
                case 2:
                    hs.Add(new InsuranceCompany());
                    break;
                case 3:
                    hs.Add(new ShipbuildingCompany());
                    break;
                case 4:
                    hs.Add(new Factory());
                    break;
                case 5:
                    hs.Add(new Library());
                    break;
            }
        }
    }

    static void FirstQuery(SortedDictionary<Organization, Queue<Library>> sortDict)
    {
        Console.WriteLine("Libraries sorted by name:");
        
        var sortedLibrariesLINQ = from queue in sortDict.Values
                                  from lib in queue
                                  orderby lib.Name select lib.Name;

        Console.WriteLine("LINQ:");
        foreach (var item in sortedLibrariesLINQ)
            Console.WriteLine(item);

        var sortedLibrariesMethods = sortDict.Values.SelectMany(q => q)
                                                    .Select(lib => lib)
                                                    .OrderBy(lib => lib.Name)
                                                    .Select(lib => lib.Name);

        Console.WriteLine("Extension Methods:");
        foreach (var item in sortedLibrariesMethods)
            Console.WriteLine(item);
        Console.WriteLine();
    }

    static void SecondQuery(SortedDictionary<Organization, Queue<Library>> sortDict)
    {
        Console.WriteLine("Libraries with more than 5000 books:");

        var librariesLINQ = (from queue in sortDict.Values
                             from lib in queue
                             where lib.BooksCount > 5000 select lib.Name).Count();

        Console.WriteLine("LINQ: " + librariesLINQ);

        var librariesMethods = (sortDict.Values.SelectMany(q => q)
                                               .Where(lib => lib.BooksCount > 5000)
                                               .Select(lib => lib.Name)).Count();

        Console.WriteLine("Extension Methods: " + librariesMethods);
        Console.WriteLine();
    }

    static void ThirdQuery(SortedDictionary<Organization, Queue<Library>> sortDict)
    {
        Console.WriteLine("Libraries union with < 20 and > 160 employees");

        var unionLibrariesLINQ = (from queue in sortDict.Values
                                  from lib in queue
                                  where lib.EmployeesCount < 20
                                  select lib)
                                  .Union(
                                  from queue in sortDict.Values
                                  from lib in queue
                                  where lib.EmployeesCount > 160
                                  select lib);

        Console.WriteLine("LINQ:");
        foreach (var item in unionLibrariesLINQ)
            Console.WriteLine("Название организации: " + item.Name +
                              "\nКоличество сотрудников: " + item.EmployeesCount);

        var unionLibrariesMethods = sortDict.Values.SelectMany(q => q)
                                                   .Where(lib => lib.EmployeesCount < 20)
                                                   .Select(lib => lib)
                                                   .Union(sortDict.Values.SelectMany(q => q)
                                                                         .Where(lib => lib.EmployeesCount > 160)
                                                                         .Select(lib => lib));

        Console.WriteLine("Extension Methods:");
        foreach (var item in unionLibrariesMethods)
            Console.WriteLine("Название организации: " + item.Name +
                              "\nКоличество сотрудников: " + item.EmployeesCount);
        Console.WriteLine();
    }

    static void FourthQuery(SortedDictionary<Organization, Queue<Library>> sortDict)
    {
        Console.WriteLine("Library with the most books:");

        var maxBooksLibLINQ = (from queue in sortDict.Values
                               from lib in queue
                               orderby lib.BooksCount descending
                               select lib).FirstOrDefault();

        Console.WriteLine("LINQ:\n" + maxBooksLibLINQ);

        var maxBooksLibMethods = sortDict.Values.SelectMany(q => q)
                                                .OrderByDescending(lib => lib.BooksCount)
                                                .FirstOrDefault();

        Console.WriteLine("Extension Methods:\n" + maxBooksLibMethods);
        Console.WriteLine();
    }

    static void FifthQuery(SortedDictionary<Organization, Queue<Library>> sortDict)
    {
        Console.WriteLine("Group by name:");

        var groupLINQ = from queue in sortDict.Values
                        from lib in queue
                        group lib by lib.Name;
                        /* into g
                        select new { Name = g.Key, Count = g.Count() };
                        */

        Console.WriteLine("LINQ:");
        foreach (var group in groupLINQ)
        {
            Console.WriteLine("Count: " + group.Count());
            foreach (var item in group)
                 // Console.WriteLine(item.Name + " : " + item.Count);
                 Console.WriteLine(item.Name);
        }

        var groupMethods = sortDict.Values.SelectMany(q => q)
                                          .GroupBy(lib => lib.Name)
                                          .Select(g => new { Name = g.Key, Count = g.Count() });

        Console.WriteLine("Extension Methods:");
        foreach (var item in groupMethods)
            Console.WriteLine(item.Name + " : " + item.Count);
        Console.WriteLine();
    }

    static void FirstMethod(MyGenericHashtable<Organization> hs)
    {
        Console.WriteLine("Names with number 8:");
        var elems = hs.SelectWhere(elem => elem.Name.Contains('8'));
        foreach (var elem in elems)
            Console.WriteLine(elem.Value.Name);
        Console.WriteLine();
    }

    static void SecondMethod(MyGenericHashtable<Organization> hs)
    {
        var result = hs.CountOrgs(elem => elem.EmployeesCount > 100);
        Console.WriteLine("Organizations with employees more than 100: " + result);
    }

    static void ThirdMethod(MyGenericHashtable<Organization> hs)
    {
        Console.WriteLine("Sort by employees count:");
        var result = hs.SortOrgsBy(org => org.EmployeesCount)
                       .Select(elem => new { elem.Value.Name, elem.Value.EmployeesCount });
        foreach (var item in result)
            Console.WriteLine("Название организации: " + item.Name +
                              "\nКоличество сотрудников: " + item.EmployeesCount);
    }
};
