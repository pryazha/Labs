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
                double prevFactN = 1, sn = 1, se = 1, n, prevPow = 1;
                y = EvalFirstExpr(x);

                for (n = 1; n <= 30; n++)
                {
                    prevFactN *= n;
                    prevPow *= x / 2;
                    sn += (n * n + 1) / prevFactN * prevPow;
                }
                n = 1;
                prevFactN = 1;
                prevPow = 1;
                while (y - se >= 0.0001)
                {
                    prevFactN *= n;
                    prevPow *= x / 2;
                    se += (n * n + 1) / prevFactN * prevPow;
                    n++;
                }
                Console.WriteLine($"X={x, 4:F4}\tSN={sn, 4:F4}\tSE={se, 4:F4}\tY={y, 4:F4}");
            }
        }

        static double EvalFirstExpr(double x)
        {
            return ((double)Math.Pow(x, 2) / 4 + (double)x / 2 + 1) * Math.Exp((double)x / 2);
        }
    }
}