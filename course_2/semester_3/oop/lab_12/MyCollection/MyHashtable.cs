using OrganizationsLibrary;

namespace MyCollection;

public class Element
{
    public int key;
    public Organization? value;
    public Element? next;

    public Element()
    {
        key = -1;
        value = null;
        next = null;
    }

    public Element(int key, Organization value, Element? next)
    {
        this.key = key;
        this.value = value;
        this.next = next;
    }

    public Element(Element other)
    {
        key = other.key;
        if (other.value != null)
        {
            value = (Organization)other.value.Clone();
        }
        next = other.next;
    }

    public override string ToString()
    {
        string value_string = "Пустая организация";
        if (value != null)
        {
            value_string = value.ToString();
        }
        return "Ключ: " + key + "\nЗначение:\n" + value_string;
    }

    public override int GetHashCode()
    {
        return key;
    }
}

public class MyHashtable
{
    public Element?[] hashtable;
    public int size;

    public MyHashtable()
    {
        size = 0;
        hashtable = new Element[size];
    }

    public MyHashtable(int size)
    {
        this.size = size;
        hashtable = new Element[size];
    }

    public bool Add(int key, Organization value)
    {
        if (value == null || size == 0)
        {
            return false;
        }
        Element newElem = new Element(key, value, null);
        int index = newElem.GetHashCode() % size; 
        if (hashtable[index] == null)
        {
            hashtable[index] = newElem;
        }
        else
        {
            Element? cur = hashtable[index];
            if (cur != null)
            {
                while (cur.next != null)
                {
                    if (key == cur.key)
                    {
                        Console.WriteLine("Элемент с таким ключом уже существует.");
                        return false;
                    }
                    cur = cur.next;
                }
                if (key == cur.key)
                {
                    Console.WriteLine("Элемент с таким ключом уже существует.");
                    return false;
                }
                cur.next = newElem;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    public void Delete(int key)
    {
        if (hashtable == null || size == 0)
        {
            Console.WriteLine("Хеш-таблица пуста.");
            return;
        }
        int index = key % size;
        if (hashtable[index] == null)
        {
            Console.WriteLine("Элемента к таким ключом не существует.");
            return;
        }
        
        Element? cur = hashtable[index];
        if (cur != null)
        {
            if (cur.key == key)
            {
                if (cur.next == null)
                {
                    hashtable[index] = null;
                }
                else
                {
                    hashtable[index] = cur.next;
                }
                Console.WriteLine($"Элемент с ключом {key} успешно удален.");
                return;
            }
            while ((cur.next != null) && (key != cur.next.key))
            {
                cur = cur.next;
            }

            if (cur.next != null)
            {
                cur.next = cur.next.next;
                Console.WriteLine($"Элемент с ключом {key} успешно удален.");
            }
            else
            {
                Console.WriteLine("Элемента к таким ключом не существует.");
            }
        }
    }

    public void Find(int key)
    {
        if (hashtable == null || size == 0)
        {
            Console.WriteLine("Хеш-таблица пуста.");
            return;
        }

        int index = key % size;
        if (hashtable[index] == null)
        {
            Console.WriteLine("Элемента к таким ключом не существует.");
            return;
        }
        
        Element? cur = hashtable[index];
        if (cur != null)
        {
            if (cur.key == key)
            {
                Console.WriteLine(cur);
                return;
            }
            while ((cur.next != null) && (key != cur.next.key))
            {
                cur = cur.next;
            }

            if (cur.next != null)
            {
                Console.WriteLine(cur);
            }
            else
            {
                Console.WriteLine("Элемента к таким ключом не существует.");
            }
        }
    }

    public void Print()
    {
        if (hashtable == null || size == 0)
        {
            Console.WriteLine("Хеш-таблица пуста.");
            return;
        }

        for (int i = 0; i < size; ++i)
        {
            if (hashtable[i] == null)
            {
                Console.WriteLine(i + ":");
            }
            else
            {
                Console.WriteLine(i + " : ");
                Element? cur = hashtable[i];
                while (cur != null)
                {
                    Console.WriteLine(cur);
                    cur = cur.next;
                }
            }
            Console.WriteLine();
        }
    }
}
