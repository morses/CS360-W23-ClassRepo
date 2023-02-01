namespace HelloWorld  //Scanner
{
    public class Laser
    {
       // initial brightness of laser
        private int period;// this is value for the period
        private float brightness;
        private int ON;
        private int OFF;

        public string Name;

        public Laser(int vMOD, int power)
        {
            Console.WriteLine("Initializing the laser");
        }

        public void SetPeriod(int period)
        {
            this.period = period;
            Console.WriteLine("Setting period");
        }

        public void SetBrightness(float b)
        {
            brightness = b;
            Console.WriteLine("Setting brightness");
        }
    }
}