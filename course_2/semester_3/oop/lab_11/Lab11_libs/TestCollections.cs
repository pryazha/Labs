using OrganizationsLibrary;

namespace Lab11_libs;

public class TestCollections
{
    public Stack<Organization> orgStack = new();
    public Stack<string> strStack = new();
    public Dictionary<Organization, Library> orgDict = new();
    public Dictionary<string, Library> strDict = new();

    public int Count { get => count; }

    public TestCollections(int size)
    {
        for (int i = 0; i < size; i++) 
        {
            Library lib = new Library();
            if (orgStack.Contains(lib))
            {
                lib = new Library();
            }
            orgStack.Push(lib);
            strStack.Push(lib.ToString());
            orgDict.Add(lib.BaseOrganization, lib);
            strDict.Add(lib.ToString(), lib);
            count++;
        }
    }

    public bool Add(Library lib)
    {
        if (orgStack.Contains(lib))
        {
            return false;
        }
        orgStack.Push(lib);
        strStack.Push(lib.ToString());
        orgDict.Add(lib.BaseOrganization, lib);
        strDict.Add(lib.ToString(), lib);
        count++;
        return true;
    }

    public bool Delete(Library lib)
    {
        if (!orgStack.Contains(lib))
        {
            return false;
        }
        RemoveItemFromStack(orgStack, lib);
        RemoveItemFromStack(strStack, lib.ToString());
        orgDict.Remove(lib);
        strDict.Remove(lib.ToString());
        count--;
        return true;
    }

    static void RemoveItemFromStack<T>(Stack<T> stack, T itemToRemove) where T: notnull
    {
        Stack<T> tempStack = new Stack<T>();

        while (stack.Count > 0)
        {
            T currentItem = stack.Pop();
            if (!currentItem.Equals(itemToRemove))
            {
                tempStack.Push(currentItem);
            }
        }

        while (tempStack.Count > 0)
        {
            stack.Push(tempStack.Pop());
        }
    }

    private int count = 0;
}
