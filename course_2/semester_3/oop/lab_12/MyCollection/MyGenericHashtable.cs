using System.Collections;

namespace MyCollection;

public class MyGenericElement<T>
{
    public int Key { get; private set; }
    public T Value { get; set; }
    public MyGenericElement<T>? Next { get; set; }

    public MyGenericElement(T value)
    {
        Value = value;
        Key = GetHashCode();
        Next = null;
    }

    public override int GetHashCode()
    {
        if (Value != null)
            return Value.GetHashCode();
        return -1;
    }

    public override string ToString()
    {
        if (Value != null)
        {
            return "Ключ: " + Key.ToString() + "\n" +
                   "Значение:\n" + Value.ToString();
        }
        else
        {
            return "Ключ:\nЗначение:";
        }
    }
}

public class MyGenericHashtable<T>
    : ICollection<MyGenericElement<T>>,
      IEnumerable<MyGenericElement<T>>,
      ICloneable
    where T : ICloneable
{
    public int Capacity { get; protected set; }
    public int Count { get; protected set; }
    public bool IsReadOnly => false;
    protected MyGenericElement<T>?[]? buckets;

    public MyGenericHashtable()
    {
        Capacity = 0;
        Count = 0;
        buckets = null;
    }
    public MyGenericHashtable(int capacity)
    {
        if (capacity > 0)
        {
            buckets = new MyGenericElement<T>[capacity];
            Capacity = capacity;
            Count = 0;
        }
    }
    public MyGenericHashtable(MyGenericHashtable<T> other)
    {
        Capacity = other.Capacity;
        Count = other.Count;
        buckets = other.CloneBuckets();
    }

    public virtual T? this[string Key]
    {
        get
        {
            if (buckets != null)
            {
                int key = Key.GetHashCode();
                int index = Math.Abs(key % Capacity);
                MyGenericElement<T>? cur = buckets[index];
                while (cur != null &&
                       cur.Value != null)
                {
                    if (cur.Key == key)
                        return cur.Value;
                    cur = cur.Next;
                }
            }

            return default(T);
        }

        set
        {
            if (buckets != null)
            {
                int key = Key.GetHashCode();
                int index = Math.Abs(key.GetHashCode() % Capacity);
                MyGenericElement<T>? cur = buckets[index];
                while (cur != null)
                {
                    if (cur.Key == key.GetHashCode())
                        if (value != null)
                            cur.Value = value;
                    cur = cur.Next;
                }
            }
        }
    }

    public void Add(MyGenericElement<T>? elem)
    {
        if (elem != null &&
            elem.Value != null)
        {
            Add(elem.Value);
        }
    }

    public virtual bool Add(T value)
    {
        if (buckets == null ||
            Contains(value))
        {
            return false;
        }

        int index = Math.Abs(value.GetHashCode() % Capacity);
        MyGenericElement<T> newElem =
            new MyGenericElement<T>(value);

        if (buckets[index] == null)
        {
            buckets[index] = newElem;
            ++Count;
            return true;
        }

        MyGenericElement<T>? cur = buckets[index];
        if (cur != null)
        {
            while (cur.Next != null)
                cur = cur.Next;
            cur.Next = newElem;
            ++Count;
            return true;
        }
        else
        {
            return false;
        }
    }

    public void Clear()
    {
        Capacity = 0;
        buckets = null;
    }

    public bool Contains(MyGenericElement<T>? item)
    {
        if (buckets == null ||
            item == null ||
            item.Value == null)
        {
            return false;
        }

        int index = Math.Abs(item.Key % Capacity);
        if (buckets[index] == null)
            return false;

        MyGenericElement<T>? cur = buckets[index];
        while (cur != null &&
               cur.Value != null)
        {
            if (String.Compare(cur.Value.ToString(), item.Value.ToString()) == 0)
                return true;
            cur = cur.Next;
        }

        return false;
    }

    public bool Contains(T value)
    {
        if (value == null || buckets == null)
            return false;

        int key = value.GetHashCode();
        int index = Math.Abs(key % Capacity);
        if (buckets[index] == null)
            return false;

        MyGenericElement<T>? cur = buckets[index];
        while (cur != null)
        {
            if (cur.Key == key)
                return true;
            cur = cur.Next;
        }

        return false;
    }

    public void CopyTo(MyGenericElement<T>[] array, int arrayIndex)
    {
        if (array == null)
            throw new ArgumentNullException(nameof(array));
        if (arrayIndex < 0 || arrayIndex >= array.Length)
            throw new ArgumentOutOfRangeException(nameof(arrayIndex));
        if (array.Length - arrayIndex < Count)
            throw new ArgumentException("Недостаточно места для копирования.");
    }

    public bool Remove(MyGenericElement<T> item)
    {
        if (item != null &&
            item.Value != null)
        {
            if (Contains(item))
            {
                Remove(item.Value.ToString());
                return true;
            }

            return false;
        }
        else
        {
            return false;
        }
    }

    public virtual bool Remove(string value)
    {
        if (value == null || buckets == null)
            return false;

        int key = value.GetHashCode();
        int index = Math.Abs(value.GetHashCode() % Capacity);
        if (buckets[index] == null)
            return false;

        MyGenericElement<T>? cur = buckets[index];
        if (cur != null)
        {
            if (cur.Key == key)
            {
                if (cur.Next == null)
                    buckets[index] = null;
                else
                    buckets[index] = cur.Next;
                --Count;
                return true;
            }

            while (cur.Next != null)
            {
                if (cur.Next.Key == key)
                    break;
                cur = cur.Next;
            }

            if (cur.Next != null)
            {
                cur.Next = cur.Next.Next;
                --Count;
                return true;
            }
        }

        return false;
    }


    public IEnumerator<MyGenericElement<T>> GetEnumerator()
    {
        if (buckets != null)
        {
            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<T>? cur = buckets[i];
                while (cur != null &&
                       cur.Value != null) 
                {
                    yield return cur;
                    cur = cur.Next;
                }
            }
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

    public void Print()
    {
        if (buckets == null)
            return;

        for (int i = 0; i < Capacity; ++i)
        {
            MyGenericElement<T>? cur = buckets[i];
            Console.WriteLine(i + ":");
            while (cur != null)
            {
                Console.WriteLine(cur);
                cur = cur.Next;
            }
            Console.WriteLine();
        }
    }

    public object ShallowCopy()
    {
        return (MyGenericHashtable<T>)MemberwiseClone();
    }

    public object Clone()
    {
        MyGenericHashtable<T> result = new MyGenericHashtable<T>(Capacity);
        if (buckets != null)
        {
            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<T>? cur = buckets[i];
                while (cur != null)
                {
                    result.Add((T)cur.Value.Clone());
                    cur = cur.Next;
                }
            }
        }
        else
        {
            result.buckets = null;
        }
        return (object)result;
    }
    
    public MyGenericElement<T>?[]? CloneBuckets()
    {
        if (buckets != null)
        {
            MyGenericElement<T>[] result =
                new MyGenericElement<T>[Capacity];

            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<T>? cur = buckets[i];
                if (cur != null &&
                    cur.Value != null) 
                {
                    MyGenericElement<T>? newElem =
                        new MyGenericElement<T>((T)cur.Value.Clone());

                    MyGenericElement<T>? nextElem = newElem;

                    while (cur.Next != null &&
                           cur.Next.Value != null)
                    {
                        nextElem.Next = new MyGenericElement<T>((T)cur.Next.Value.Clone());
                        nextElem = nextElem.Next;
                        cur = cur.Next;
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
