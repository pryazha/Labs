using DiapasonLibrary;

class Program
{
    static double Max(DiapasonArray darr)
    {
        double max = -1;
        for (int i = 0; i < darr.Length; i++)
            if (darr[i] > max)
                max = darr[i];
        return max;
    }

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
        Console.WriteLine($"Количество созданных объектов: diap1.ObjectsCount = {Diapason.s_objectsCount}");
        
        Console.WriteLine("\nЧасть 2:");
        Console.WriteLine($"Длина диапазона !diap3 = {!diap3}");
        ++diap3;
        Console.Write("diap3 после ++diap3: "); diap3.Print();
        Console.WriteLine($"(int)diap3 = {(int)diap3}");
        Console.WriteLine($"5.4 + diap3 = {5.4 + diap3}");
        Console.WriteLine($"6.4 < diap3 = {6.4 < diap3}");
        Console.WriteLine($"6.6 < diap3 = {6.6 < diap3}");

        Console.WriteLine("\nЧасть 3");
        DiapasonArray darr1 = new DiapasonArray();
        Console.WriteLine("darr1:"); darr1.Print();
        DiapasonArray darr2 = new DiapasonArray(5);
        Console.WriteLine("darr2:"); darr2.Print();
        darr1 = new DiapasonArray(4);
        Console.WriteLine("darr1:"); darr1.Print();
        darr1[2] = new Diapason(4, 100.4);
        Console.WriteLine("darr1:"); darr1.Print();
        try 
        {
            darr1[5] = new Diapason(5, 10);
        } catch(IndexOutOfRangeException e) 
        {
            Console.WriteLine("Обращение к элементу за границами массива");
        }
        Console.Write("darr2[4]: "); darr2[4].Print();
        Console.WriteLine($"Max(darr1) = {Max(darr1)}");
        Console.WriteLine($"Количество созданных объектов diapason: {Diapason.s_objectsCount}");
        Diapason diap4 = new Diapason(6.5, 13); 
        Diapason diap = new Diapason();
        Console.Write("diap3: "); diap3.Print();
        Console.Write("diap4: "); diap4.Print();
        Console.WriteLine(Diapason.Equals(diap3, diap4));
    }
}
