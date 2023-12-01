using DiapasonLibrary;

class Program
{
    static void Main()
    {
        Console.WriteLine("Часть 1:");
        Diapason diap1 = new Diapason();
        Diapason diap2 = new Diapason(12, 5.5);
        Diapason diap3 = new Diapason(diap2);
        Console.Write("diap1: "); diap1.Print();
        Console.Write("diap2: "); diap2.Print();
        Console.Write("diap3: "); diap3.Print();
        Console.WriteLine($"Число 5 находится в диапазоне diap2: {diap2.InRange(5)}");
        Console.WriteLine($"Число 12.1 находится в диапазоне diap2: {diap2.InRange(12.1)}");
        Console.WriteLine($"Число 3.53 находится в диапазоне [3.52, 4]: {Diapason.InRange(3.53, 3.52, 4)}");
        Console.WriteLine($"Количество созданных объектов: diap1.ObjectsCount = {diap1.ObjectsCount}");
        
        Console.WriteLine("\nЧасть 2:");
        Console.WriteLine($"Длина диапазона !diap3 = {!diap3}");
        ++diap3;
        Console.Write("diap3 после ++diap3: "); diap3.Print();
        Console.WriteLine($"(int)diap3 = {(int)diap3}");
        Console.WriteLine($"5.4 + diap3 = {5.4 + diap3}");
        Console.WriteLine($"6.4 < diap3 = {6.4 < diap3}");
        Console.WriteLine($"6.6 < diap3 = {6.6 < diap3}");

        Console.WriteLine("\nЧасть 3");
    }
}
