using System;

namespace lab3
{
    class Program
    {
        static int bound = 20;


        static int Main(string[] args)
        {
            int counter = 0;    
            var rand = new Random();
            for (int i = 0; i < 20; i++)
            {
                counter++;
                Console.WriteLine($"{counter,5}:{rand.Next(100, 1000)}");
            }

            for (int i = 5; i < 10; i++)
            {
                for (int j = 3; j < 7; j++)
                {
                    for (int k = 0; k < 6; k++)
                    {
                        counter++;
                        if (counter == bound)
                            return 0;


                    }
                }
            }

            return 0;

        }

    }
}