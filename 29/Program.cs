using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _29
{
    class Program
    {
        static void Main(string[] args)
        {
            int y = 1 / 2;
            int x = Divide(1, 2);
            Console.WriteLine(x);
            Console.Read();
        }

        public static Tuple<long, long> DivideHelper(long dividend, long divisor)
        {
            // Returns a tuple containing (quotient, remainder)

            if(divisor == 1)
            {
                return new Tuple<long, long>(dividend, 0);
            }
            int quotient = 0;

            while (dividend > 0)
            {
                dividend -= divisor;
                if (dividend >= 0)
                {
                    quotient++;
                }
            }
            long remainder = (dividend == 0) ? 0 : (divisor - Math.Abs(dividend));
            return new Tuple<long, long>(quotient, remainder);
        }

        public static int Divide(int dividend, int divisor)
        {
            // Mom's short division method

            // Check for overflow
            if (divisor == -1 && dividend == Int32.MinValue)
            {
                return Int32.MaxValue;
            }
            Tuple<long, long> tempQuotient;
            if (divisor == 1)
            {
                return dividend;
            }

            // Don't mess around with negative numbers; just keep track if the quotient needs to be negative
            // We need to use longs in case of Int32.MinValue
            bool isNegative = (dividend < 0) ^ (divisor < 0);
            long absDividend = Math.Abs((long)dividend);
            long absDivisor = Math.Abs((long)divisor);

            if (absDividend < 10)
            {
                tempQuotient = DivideHelper((long)absDividend, (long)absDivisor);
                return isNegative == true ? (int)tempQuotient.Item1 * -1 : (int)tempQuotient.Item1;
            }

            long quotient = 0;

            // Get the individual digits in a way I can access them
            var intEnumerable = absDividend.ToString().Select(digit => long.Parse(digit.ToString()));
            List<long> intList = intEnumerable.ToList();


            int i = 0;
            int begin;

            do
            {
                begin = i;
                long tempDividend = intList.ElementAt(begin);
                for (;;)
                {
                    if (tempDividend < absDivisor)
                    {
                        i++;
                        tempDividend = Convert.ToInt64(string.Format("{0}{1}", tempDividend, intList.ElementAt(i)));
                    }
                    break;
                }
                tempQuotient = DivideHelper(tempDividend, absDivisor);
                quotient = Convert.ToInt64(string.Format("{0}{1}", quotient, tempQuotient.Item1));
                i++;
                intList.Insert(i, tempQuotient.Item2);
            } while (i < intList.Count() - 1);
            quotient = isNegative ? quotient * -1 : quotient;
            return (int)quotient;
        }
    }
}
