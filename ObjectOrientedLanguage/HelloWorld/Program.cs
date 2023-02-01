//using Scanner;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            Laser laser = new Laser(4,50);
            laser.SetPeriod(40);
            laser.SetBrightness(100.0f);
        } // no free or delete: garbage collector will reclaim the laser memory
    }
}
