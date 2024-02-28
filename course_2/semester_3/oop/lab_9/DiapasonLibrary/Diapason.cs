namespace DiapasonLibrary;

public class Diapason
{
    public double x { get; }
    public double y { get; }
    public static int objectsCount;

    public Diapason()
    {
        x = 0;
        y = 0;
        objectsCount++;
    }

    public Diapason(double x, double y)
    {
        if (x > y)
        {
            double temp = x;
            x = y;
            y = temp;
        }
        this.x = x;
        this.y = y;
        objectsCount++;
    }

    public Diapason(Diapason d)
    {
        x = d.x;
        y = d.y;
        objectsCount++;
    }

    ~Diapason()
    {
        objectsCount--;
    }

    public void Print()
    {
        Console.WriteLine($"[{x}, {y}]");
    }

    public bool InRange(double num)
    {
        return num >= x && num <= y;
    }

    public static bool InRange(double num, double x, double y) 
    {
        return num >= x && num <= y;
    }

    public static double operator !(Diapason d) => d.y - d.x;
    
    public static Diapason operator ++(Diapason d) => new Diapason(d.x + 1, d.y + 1);

    public static explicit operator int(Diapason d) => (int)d.x;

    public static implicit operator double(Diapason d) => d.y;

    public static Diapason operator +(Diapason d, double num) => new Diapason(d.x + num, d.y + num);

    public static bool operator <(double num, Diapason d) => num >= d.x && num <= d.y;

    public static bool operator >(double num, Diapason d) => num < d.x || num > d.y;

    public override bool Equals(object? obj) 
    {
        var item = obj as Diapason;
        if (item == null)
            return false;
        return x == item.x && y == item.y;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(x, y);
    }
}

public class DiapasonArray
{
    public int Length => _arr.Length;

    public DiapasonArray()
    {
        _arr = new Diapason[0];
    }

    public DiapasonArray(int size) 
    {
        if (size <= 0)
        {
            _arr = new Diapason[0];
            return;
        }
        Random rnd = new Random();
        _arr = new Diapason[size];
        for (int i = 0; i < size; i++)
        {
            Diapason diap = new Diapason(rnd.Next(0, 20), rnd.Next(0, 20));
            _arr[i] = diap;
        }
    }

    public DiapasonArray(Diapason[] darr)
    {
        _arr = new Diapason[darr.Length];
        for (int i = 0; i < darr.Length; i++)
        {
            _arr[i] = darr[i];
        }
    }

    public void Print()
    {
        if (_arr.Length == 0)
        {
            Console.WriteLine("Размер массива равен 0!");
            return;
        }
        for (int i = 0; i < _arr.Length; i++)
        {
            _arr[i].Print();
        }
    }

    public Diapason this[int index]
    {
        get {
            try 
            {
                return _arr[index];
            } catch(IndexOutOfRangeException) 
            {
                Console.WriteLine("Обращение к элементу за границами массива!");
                return new Diapason();
            }
        }
        set {
            try 
            {
                _arr[index] = value;
            } catch(IndexOutOfRangeException) 
            {
                Console.WriteLine("Обращение к элементу за границами массива!");
            }
        }
    }

    private Diapason[] _arr;
}
