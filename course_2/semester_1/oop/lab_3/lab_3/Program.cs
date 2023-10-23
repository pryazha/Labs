using System;

namespace lab_3
{
    class Program
    {
        static void Main(string[] args)
        {
            double y;
            double k = 0.09;

            for (double x = 0.1; x <= 1; x += k)
            {
                double prevFactN = 1, sn = 1, se = 1, n = 1;
                y = EvalFirstExpr(x);

                for (n = 1; n <= 30; n++)
                {
                    prevFactN *= n;
                    sn += (n * n + 1) / prevFactN * Math.Pow(x / 2, n);
                }
                n = 1;
                prevFactN = 1;
                while (y - se >= 0.0001)
                {
                    prevFactN *= n;
                    se += (n * n + 1) / prevFactN * Math.Pow(x / 2, n);
                    n++;
                }
                Console.WriteLine($"X={x}\tSN={sn}\tSE={se}\tY={y}");
            }
        }

        static double EvalFirstExpr(double x)
        {
            return ((double)Math.Pow(x, 2) / 4 + (double)x / 2 + 1) * Math.Exp((double)x / 2);
        }
    }
}