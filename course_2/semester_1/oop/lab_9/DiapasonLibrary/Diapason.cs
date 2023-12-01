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

    private static int _objectsCount;
}
