namespace MyCollection;

public class MyGenericElement<TKey, TValue>
{
    public TKey Key { get; set; }
    public TValue Value { get; set; }
    public MyGenericElement<TKey, TValue>? Next { get; set; }

    public MyGenericElement(TKey key, TValue value)
    {
        Key = key;
        Value = value;
        Next = null;
    }

    public override int GetHashCode()
    {
        if (Key == null)
            return -1;
        return Key.GetHashCode();
    }
}

public class MyGenericHashtable<TKey, TValue>
{
    public int Capacity { get; }
    private MyGenericElement<TKey, TValue>[]? buckets;

    public MyGenericHashtable()
    {
        Capacity = 0;
        buckets = null;
    }
    public MyGenericHashtable(int capacity)
    {
        if (capacity > 0)
        {
            buckets = new MyGenericElement<TKey, TValue>[capacity];
            Capacity = capacity;
        }
    }

    // TODO(pryazha): Implement Clone
    public MyGenericHashtable(MyGenericHashtable<TKey, TValue> other)
    {
    }

    public bool Add(TKey key, TValue value)
    {
        if (key == null || buckets == null)
        {
            return false;
        }

        int index = key.GetHashCode() % Capacity;
        MyGenericElement<TKey, TValue> newElem = new MyGenericElement<TKey, TValue>(key, value);

        if (buckets[index] == null)
        {
            buckets[index] = newElem;
            return true;
        }

        MyGenericElement<TKey, TValue> cur = buckets[index];
        while (cur.Next != null)
        {
            cur = cur.Next;
        }
        cur.Next = newElem;
        return true;
    }

    public void Print()
    {
        if (buckets == null)
        {
            return;
        }

        for (int i = 0; i < buckets.Length; ++i)
        {
            MyGenericElement<TKey, TValue>? cur = buckets[i];
            Console.WriteLine(i + ":");
            while (cur != null)
            {
                Console.WriteLine("Ключ: " + cur.Key);
                Console.WriteLine("Значение: " + cur.Value);
                cur = cur.Next;
            }
            Console.WriteLine();
        }
    }

    public MyGenericHashtable<TKey, TValue> Clone()
    {
        MyGenericHashtable<TKey, TValue> result = new MyGenericHashtable<TKey, TValue>(Capacity);
        if (buckets != null)
        {
            for (int i = 0; i < buckets.Length; ++i)
            {
                // MyGenericElement<TKey, TValue> cur = 
            }
        }
        else
        {
            result.buckets = null;
        }
        return result;
    }
}
