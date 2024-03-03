using System.Collections;
using System.Collections.Generic;

namespace MyCollection;

public class MyGenericElement<TKey, TValue>
{
    public TKey Key { get; private set; }
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

    public override string ToString()
    {
        if (Key != null &&
            Value != null)
        {
            return "Ключ: " + Key.ToString() + "\n" +
                   "Значение: " + Value.ToString();
        }
        else
        {
            return "Ключ:\nЗначение:";
        }
    }
}

public class MyGenericHashtable<TKey, TValue>
    : ICollection<MyGenericElement<TKey, TValue>>,
      IEnumerable<MyGenericElement<TKey, TValue>>,
      ICloneable
    where TValue : ICloneable
{
    public int Capacity { get; private set; }
    public int Count { get; private set; }
    public bool IsReadOnly => false;
    private MyGenericElement<TKey, TValue>?[]? buckets;

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
        Count = other.Count;
        buckets = other.CloneBuckets();
    }

    public TValue this[TKey key]
    {
        get
        {
            if (key != null &&
                Contains(key))
            {
                int index = Math.Abs(key.GetHashCode() % Capacity);
                MyGenericElement<TKey, TValue>? cur = buckets[index];
                while (cur != null &&
                       cur.Key != null &&
                       cur.Value != null)
                {
                    if (String.Compare(cur.Key.ToString(), key.ToString()) == 0)
                        return cur.Value;
                    cur = cur.Next;
                }
            }

            return default(TValue);
        }

        set
        {
            if (Contains(key))
            {
                int index = Math.Abs(key.GetHashCode() % Capacity);
                MyGenericElement<TKey, TValue>? cur = buckets[index];
                while (cur != null &&
                       cur.Key != null &&
                       cur.Value != null)
                {
                    if (String.Compare(cur.Key.ToString(), key.ToString()) == 0)
                        cur.Value = value;
                    cur = cur.Next;
                }
            }
        }
    }

    public void Add(MyGenericElement<TKey, TValue>? elem)
    {
        if (elem != null &&
            elem.Key != null &&
            elem.Value != null)
        {
            this.Add(elem.Key, elem.Value);
        }
    }

    public bool Add(TKey key, TValue value)
    {
        if (key == null ||
            buckets == null ||
            Contains(key))
        {
            return false;
        }

        int index = Math.Abs(key.GetHashCode() % Capacity);
        MyGenericElement<TKey, TValue> newElem =
            new MyGenericElement<TKey, TValue>(key, value);

        if (buckets[index] == null)
        {
            buckets[index] = newElem;
            ++Count;
            return true;
        }

        MyGenericElement<TKey, TValue>? cur = buckets[index];
        if (cur != null &&
            cur.Key != null)
        {
            while (cur.Next != null)
            {
                cur = cur.Next;
            }
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

    public bool Contains(MyGenericElement<TKey, TValue>? item)
    {
        if (buckets == null ||
            item == null ||
            item.Key == null ||
            item.Value == null)
        {
            return false;
        }

        int index = Math.Abs(item.Key.GetHashCode() % Capacity);
        if (buckets[index] == null)
        {
            return false;
        }

        MyGenericElement<TKey, TValue>? cur = buckets[index];
        while (cur != null &&
               cur.Key != null &&
               cur.Value != null)
        {
            if (String.Compare(cur.Key.ToString(), item.Key.ToString()) == 0 &&
                String.Compare(cur.Value.ToString(), item.Value.ToString()) == 0)
            {
                return true;
            }
            cur = cur.Next;
        }

        return false;
    }

    public bool Contains(TKey key)
    {
        if (key == null ||
            buckets == null)
        {
            return false;
        }

        int index = Math.Abs(key.GetHashCode() % Capacity);
        if (buckets[index] == null)
        {
            return false;
        }

        MyGenericElement<TKey, TValue>? cur = buckets[index];
        while (cur != null &&
               cur.Key != null)
        {
            if (String.Compare(cur.Key.ToString(), key.ToString()) == 0)
            {
                return true;
            }
            cur = cur.Next;
        }

        return false;
    }

    // TODO(pryazha): Implement CopyTo for ICollection
    public void CopyTo(MyGenericElement<TKey, TValue>[] array, int arrayIndex)
    {
        if (array == null)
        {
            throw new ArgumentNullException(nameof(array));
        }
        if (arrayIndex < 0 || arrayIndex >= array.Length)
        {
            throw new ArgumentOutOfRangeException(nameof(arrayIndex));
        }
        if (array.Length - arrayIndex < Count)
        {
            throw new ArgumentException("Недостаточно места для копирования.");
        }

        for (int i = 0; i < Capacity; ++i)
        {
        }
    }

    public bool Remove(MyGenericElement<TKey, TValue> item)
    {
        if (item == null ||
            item.Key == null ||
            item.Value == null)
        {
            return false;
        }

        if (Contains(item))
        {
            Remove(item.Key);
            return true;
        }

        return false;
    }

    public bool Remove(TKey key)
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
        if (cur != null &&
            cur.Key != null)
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
                --Count;
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
                --Count;
                return true;
            }
        }

        return false;
    }


    public IEnumerator<MyGenericElement<TKey, TValue>> GetEnumerator()
    {
        if (buckets != null)
        {
            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<TKey, TValue>? cur = buckets[i];
                while (cur != null &&
                       cur.Key != null &&
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
        {
            return;
        }

        for (int i = 0; i < Capacity; ++i)
        {
            MyGenericElement<TKey, TValue>? cur = buckets[i];
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
        return (MyGenericHashtable<TKey, TValue>)MemberwiseClone();
    }

    public object Clone()
    {
        MyGenericHashtable<TKey, TValue> result = new MyGenericHashtable<TKey, TValue>(Capacity);
        if (buckets != null)
        {
            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<TKey, TValue>? cur = buckets[i];
                while (cur != null)
                {
                    result.Add(cur.Key, (TValue)cur.Value.Clone());
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
    
    public MyGenericElement<TKey, TValue>?[]? CloneBuckets()
    {
        if (buckets != null)
        {
            MyGenericElement<TKey, TValue>[] result =
                new MyGenericElement<TKey, TValue>[Capacity];

            for (int i = 0; i < Capacity; ++i)
            {
                MyGenericElement<TKey, TValue>? cur = buckets[i];
                if (cur != null &&
                    cur.Key != null &&
                    cur.Value != null) 
                {
                    MyGenericElement<TKey, TValue>? newElem =
                        new MyGenericElement<TKey, TValue>(cur.Key, (TValue)cur.Value.Clone());

                    MyGenericElement<TKey, TValue>? nextElem = newElem;

                    while (cur.Next != null &&
                           cur.Next.Key != null &&
                           cur.Next.Value != null)
                    {
                        nextElem.Next = new MyGenericElement<TKey, TValue>(cur.Next.Key, (TValue)cur.Next.Value.Clone());
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
