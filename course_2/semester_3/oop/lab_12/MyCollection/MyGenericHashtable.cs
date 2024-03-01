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
    // : ICollection<MyGenericElement<TKey, TValue>>
      // IEnumerable<MyGenericElement<TKey, TValue>>,
      // ICloneable
{
    public int Capacity { get; private set; }
    public MyGenericElement<TKey, TValue>?[]? buckets;

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
    public MyGenericHashtable(MyGenericHashtable<TKey, TValue> other)
    {
        Capacity = other.Capacity;
        buckets = other.CloneBuckets();
    }

    public void Add(MyGenericElement<TKey, TValue>? elem)
    {
        if ((elem != null) &&
            (elem.Key != null) &&
            (elem.Value != null))
        {
            this.Add(elem.Key, elem.Value);
        }
    }

    public bool Add(TKey key, TValue value)
    {
        if (key == null || buckets == null)
        {
            return false;
        }

        int index = Math.Abs(key.GetHashCode() % Capacity);
        MyGenericElement<TKey, TValue> newElem = new MyGenericElement<TKey, TValue>(key, value);

        if (buckets[index] == null)
        {
            buckets[index] = newElem;
            return true;
        }

        MyGenericElement<TKey, TValue>? cur = buckets[index];
        if (cur != null)
        {
            while (cur.Next != null)
            {
                cur = cur.Next;
            }
            cur.Next = newElem;
            return true;
        }
        else
        {
            return false;
        }
    }

    public bool Delete(TKey key)
    {
        if (key == null || buckets == null)
        {
            return false;
        }

        int index = Math.Abs(key.GetHashCode() % Capacity);
        if (buckets[index] == null)
        {
            return false;
        }

        MyGenericElement<TKey, TValue>? cur = buckets[index];
        if (cur != null)
        {
            if (cur.Key != null)
            {
                if (String.Compare(cur.Key.ToString(), key.ToString()) == 0)
                {
                    if (cur.Next == null)
                    {
                        buckets[index] = null;
                    }
                    else
                    {
                        buckets[index] = cur.Next;
                    }
                    return true;
                }

                while (cur.Next != null)
                {
                    if (cur.Next.Key != null)
                        if (String.Compare(cur.Next.Key.ToString(), key.ToString()) == 0)
                            break;
                    cur = cur.Next;
                }

                if (cur.Next != null)
                {
                    cur.Next = cur.Next.Next;
                    return true;
                }
            }
        }

        return false;
    }

    public void Clear()
    {
        Capacity = 0;
        buckets = null;
    }

    public bool Contains(MyGenericElement<TKey, TValue>? item)
    {
        if ((buckets == null) ||
            (item == null) ||
            (item.Key == null) ||
            (item.Value == null))
        {
            return false;
        }

        int index = Math.Abs(item.Key.GetHashCode() % Capacity);
        if (buckets[index] == null)
        {
            return false;
        }

        MyGenericElement<TKey, TValue>? cur = buckets[index];
        if ((cur != null) &&
            (cur.Key != null) &&
            (cur.Value != null))
        {
            if (String.Compare(cur.Key.ToString(), item.Key.ToString()) == 0 &&
                String.Compare(cur.Value.ToString(), item.Value.ToString()) == 0)
            {
                return true;
            }

            while (cur.Next != null)
            {
                if (cur.Next.Key != null &&
                    cur.Next.Value != null)
                {
                    if (String.Compare(cur.Key.ToString(), item.Key.ToString()) == 0 &&
                        String.Compare(cur.Value.ToString(), item.Value.ToString()) == 0)
                    {
                        return true;
                    }
                }
                cur = cur.Next;
            }
        }

        return false;
    }

    // TODO(pryazha): Implement CopyTo for ICollection
    public void CopyTo(MyGenericTable<TKey, TValue> array, int arrayIndex)
    {
    }

    public void Print()
    {
        if (buckets == null)
        {
            return;
        }

        for (int i = 0; i < Capacity; ++i)
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
            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<TKey, TValue>? cur = buckets[i];
                while (cur != null)
                {
                    result.Add(cur.Key, cur.Value);
                    cur = cur.Next;
                }
            }
        }
        else
        {
            result.buckets = null;
        }
        return result;
    }
    
    // TODO(pryazha): This won't probably work right.
    // It is necessary to clone the of the following elements.
    public MyGenericElement<TKey, TValue>?[]? CloneBuckets()
    {
        if (buckets != null)
        {
            MyGenericElement<TKey, TValue>[] result =
                new MyGenericElement<TKey, TValue>[Capacity];

            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<TKey, TValue>? cur = buckets[i];
                if ((cur != null) &&
                    (cur.Key != null) &&
                    (cur.Value != null)) 
                {
                    MyGenericElement<TKey, TValue>? newElem =
                        new MyGenericElement<TKey, TValue>(cur.Key, cur.Value);
                    while (cur.Next != null &&
                           cur.Next.Key != null &&
                           cur.Next.Value != null)
                    {
                        newElem.Next = new MyGenericElement(cur.Next.Key, cur.Next.Value);
                    }
                    result[i] = newElem;
                }
            }

            return result;
        }
        else
        {
            return null;
        }
    }
}
