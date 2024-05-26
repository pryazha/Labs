using MyCollection;

namespace MainProgram;

public class CollectionHandlerEventArgs<T> : EventArgs
    where T : ICloneable
{
    public string name;
    public string eventType;
    public T? changedElement;

    public CollectionHandlerEventArgs(string name, string eventType, T? changedElement)
    {
        this.name = name;
        this.eventType = eventType;
        this.changedElement = changedElement;
    }

    public override string ToString() 
    {
        return "Название коллекции: " + name +
               "\nДействие: " + eventType +
               "\nИзменённый элемент:\n" + changedElement?.ToString() ?? "" + "\n";
    }
}

public delegate void CollectionHandler<T>(object source,
        CollectionHandlerEventArgs<T> args) where T : ICloneable;

public class MyNewCollection<T> : MyGenericHashtable<T>
    where T : ICloneable
{
    public string Name { get; set; }

    public event CollectionHandler<T>? CollectionCountChanged;
    public event CollectionHandler<T>? CollectionReferenceChanged;

    public MyNewCollection() : base()
    {
        Name = "";
    }
    public MyNewCollection(string name, int capacity) : base(capacity)
    {
        Name = name;
    }

    public void OnCollectionCountChanged(object source,
            CollectionHandlerEventArgs<T> args)
    {
        if (CollectionCountChanged != null)
            CollectionCountChanged(source, args);
    }

    public void OnCollectionReferenceChanged(object source,
            CollectionHandlerEventArgs<T> args)
    {
        if (CollectionReferenceChanged != null)
            CollectionReferenceChanged(source, args);
    }

    public override bool Remove(string? key)
    {
        if (key == null) 
            return false;
        if (base[key] != null)
        {
            OnCollectionCountChanged(this,
                    new CollectionHandlerEventArgs<T>(Name, "delete", base[key]));
            return base.Remove(key);
        }
        else
        {
            return false;
        }
    }

    public override bool Add(T value)
    {
        if (value != null)
        {
            OnCollectionCountChanged(this,
                    new CollectionHandlerEventArgs<T>(Name, "add", value));
            return base.Add(value);
        }
        else
        {
            return false;
        }
    }

    public override T? this[string key]
    {
        get
        {
            return base[key];
        }
        set
        {
            if (value != null &&
                base[key] != null)
            {
                OnCollectionReferenceChanged(this,
                        new CollectionHandlerEventArgs<T>(Name, "changed", value));
            }
            base[key] = value;
        }
    }
}

public class JournalEntry<T> where T : ICloneable
{
    public string name;
    public string eventType;
    public T changedElement;

    public JournalEntry(string name, string eventType, T changedElement)
    {
        this.name = name;
        this.eventType = eventType;
        this.changedElement = changedElement;
    }

    public override string ToString() 
    {
        return "Название коллекции: " + name +
               "\nДействие: " + eventType +
               "\nИзменённый элемент:\n" + changedElement.ToString() + "\n";
    }
}

public class Journal<T> where T : ICloneable
{
    private List<CollectionHandlerEventArgs<T>>? journal;

    public void CollectionCountChanged(object source,
            CollectionHandlerEventArgs<T> args)
    {
        var entry = new CollectionHandlerEventArgs<T>(args.name, args.eventType, args.changedElement);
        if (journal == null) {
            journal = new List<CollectionHandlerEventArgs<T>>();
        }
        journal.Add(entry);
    }

    public void CollectionReferenceChanged(object source,
            CollectionHandlerEventArgs<T> args)
    {
        var entry = new CollectionHandlerEventArgs<T>(args.name, args.eventType, args.changedElement);
        if (journal == null) {
            journal = new List<CollectionHandlerEventArgs<T>>();
        }
        journal.Add(entry);
    }

    public void Print()
    {
        if (journal != null)
            foreach (var entry in journal)
                Console.WriteLine(entry);
    }
}
