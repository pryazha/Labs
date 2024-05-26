using OrganizationsLibrary;
using MyCollection;

namespace MainProgram;

public static class MyNewCollection
{
    public static IEnumerable<MyGenericElement<T>>
    Where<T>(this MyGenericHashtable<T> hst, Func<T, bool> rule) where T : ICloneable
    {
        foreach (var item in hst)
            if (rule(item.Value))
                yield return item;
    }

    public static IEnumerable<MyGenericElement<Organization>>
    SelectWhere(this MyGenericHashtable<Organization> hst, Func<Organization, bool> rule)
    {
        return hst.Where(rule);
    }

    public static int
    CountOrgs(this MyGenericHashtable<Organization> hst, Func<Organization, bool> rule)
    {
        int count = hst.Where(rule).Count();
        return count;
    }

    public static IEnumerable<MyGenericElement<Organization>>
    SortOrgsBy<TKey>(this MyGenericHashtable<Organization> hst, Func<Organization, TKey> keySelector)
    {
        var elements = new List<MyGenericElement<Organization>>();
        foreach (var item in hst)
            elements.Add(item);
        return elements.OrderBy(e => keySelector(e.Value));
    }
}
