using System;
using System.Text;
using System.Linq;

namespace IntersperseExample 
{
    public static class ExtensionMethods
    {
        // Using LINQ.  This injects the Intersperse method into any IEnumerable.
        //  Found this example at: https://stackoverflow.com/questions/753316/extension-method-for-enumerable-intersperse
        public static IEnumerable<T> Intersperse<T>(this IEnumerable<T> source, T element)
        {
            var e = source.GetEnumerator(); 
            bool b = e.MoveNext();
            if (b) yield return e.Current;

            while (e.MoveNext())
            {
                yield return element;
                yield return e.Current;
            }
        }

        // This version (from the same StackOverflow page) uses an Aggregate, which is a left Fold
        public static IEnumerable<T> Delimit2a <T> (this IEnumerable<T> source, T delimiter) =>
            source.Aggregate(Enumerable.Empty<T>(), (delimited, item) => delimited.Append(delimiter).Append(item)).Skip(1);

        // I have used this on occasion, even though the syntax is horrific, for example
         // The LINQ method Aggregate is the same as functional programming's "fold" or "reduce" function
        // Get all errors in a single string, from a list of errors
        /*
        public string GetAllErrors() =>
                Validations.Aggregate("", (accumulator, validation) => accumulator + $",{validation.ErrorMessage}");
        */

    }

    public class Program
    {
        public static string Intersperse(char c, string input)
        {
            StringBuilder sb = new StringBuilder(2*input.Length);
            bool firstTime = true;
            foreach(char v in input)
            {
                if(firstTime)
                {
                    sb.Append(v);
                    firstTime = false;
                }
                else
                {
                    sb.Append(c);
                    sb.Append(v);
                }
            }
            return sb.ToString();
        }

        public static void Main(string[] args)
        {
            // Using our own method
            Console.WriteLine($"empty string -> {Intersperse(',',"")}");
            Console.WriteLine($"A -> {Intersperse(',',"A")}");
            Console.WriteLine($"AB -> {Intersperse(',',"AB")}");
            Console.WriteLine($"ABCDEFG -> {Intersperse(',',"ABCDEFG")}");

            // Using the LINQ method that uses an iterator
            string output = new string("".Intersperse(',').ToArray());
            Console.WriteLine($"empty string -> {output}");
            output = new string("A".Intersperse(',').ToArray());
            Console.WriteLine($"A -> {output}");
            output = new string("AB".Intersperse(',').ToArray());
            Console.WriteLine($"AB -> {output}");
            output = new string("ABCDEFG".Intersperse(',').ToArray());
            Console.WriteLine($"ABCDEFG -> {output}");

            // Using the LINQ method that uses a fold
            output = new string("".Delimit2a(',').ToArray());
            Console.WriteLine($"empty string -> {output}");
            output = new string("A".Delimit2a(',').ToArray());
            Console.WriteLine($"A -> {output}");
            output = new string("AB".Delimit2a(',').ToArray());
            Console.WriteLine($"AB -> {output}");
            output = new string("ABCDEFG".Delimit2a(',').ToArray());
            Console.WriteLine($"ABCDEFG -> {output}");

            // There is also String.Join but it's only for strings obviously
        }
    }
}