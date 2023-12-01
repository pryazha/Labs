namespace DiapasonLibrary;

public class Diapason
{
    public double x { get; }
    public double y { get; }

    public int ObjectsCount => _objectsCount;

    public Diapason()
    {
        x = 0;
        y = 0;
        _objectsCount++;
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
        _objectsCount++;
    }

    public Diapason(Diapason d)
    {
        x = d.x;
        y = d.y;
        _objectsCount++;
    }

    ~Diapason()
    {
        _objectsCount--;
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

    private static int _objectsCount;
}

public class DiapasonArray
{
    DiapasonArray()
    {
        _arr = new Diapason[0];
    }

    DiapasonArray(int size) 
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

    private Diapason[] _arr;
}
