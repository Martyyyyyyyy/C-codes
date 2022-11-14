using System;

namespace dmlab2
{
    class Program
    {
        static int bound = 30;


        static int Main(string[] args)
        {

            int counter = 0;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        counter++;
                        Console.WriteLine($"{counter,5}: {i} {j} {k}");
                        if (counter == bound)
                            return 0;


                    }
                }
            }

            return 0;

        }

    }
}