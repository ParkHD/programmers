using System;
using System.Linq;
namespace Programmers
{
 
    class Program
    {
        static void Main(string[] args)
        {
            string[] digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" }; 
            digits = digits.Where((x, index) => x.Length < index).ToArray();

            Console.WriteLine(digits[0]);
        }
    }
}
