using System;
using System.Collections.Generic;
using System.Linq;

namespace WindowsFormsCalculator
{
    public class TNumber
    {
        private const int BASE = 7;
        private const string DIGITS = "0123456";
        private const int MANTISSA_LEN = 5;

        public TNumber(string value)
        {
            if (string.IsNullOrEmpty(value))
            {
                throw new ArgumentException("Value cannot be null or empty.");
            }
            
            IsNegative = value[0] == '-';

            var strings = value.Trim('-').Split('.');
            if (strings.Length > 2 || strings.Length == 0)
            {
                throw new ArgumentException("Invalid number format.");
            }
            
            Digits = Parse(strings[0]);
            Mantissa = Array.Empty<int>();
            if (strings.Length != 2) return;
            Mantissa = Cut(Parse(strings[1]));
        }

        private static int[] Cut(IReadOnlyCollection<int> mantissa)
        {
            var res = mantissa.Count > MANTISSA_LEN
                ? mantissa
                    .Skip(mantissa.Count - MANTISSA_LEN)
                    .ToArray()
                : Enumerable
                    .Repeat(0, MANTISSA_LEN - mantissa.Count)
                    .ToArray()
                    .Concat(mantissa)
                    .ToArray();
            return res.All(x => x == 0) ? Array.Empty<int>() : res;
        }

        private TNumber(bool isNegative, int[] digits, int[] mantissa)
        {
            IsNegative = isNegative;
            Digits = digits;
            Mantissa = Cut(mantissa);
        }

        private bool IsNegative { get; }
        private int[] Digits { get; }
        private int[] Mantissa { get; }

        private static int[] Parse(string value)
        {
            var res = new int[value.Length];
            
            for (var i = 0; i < value.Length; i++)
            {
                var c = value[i];

                if (!DIGITS.Contains($"{c}"))
                {
                    throw new ArgumentException($"Invalid digit '{c}' at position {i}.");
                }

                res[value.Length - i - 1] = DIGITS.IndexOf(c);
            }

            return res;
        }

        private double ToDecimal()
        {
            var res = Digits.Select((t, i) => Math.Pow(BASE, i) * t).Sum();
            if (Mantissa.Length != 0)
            {
                res += Mantissa.Select((t, i) => Math.Pow(BASE, i - MANTISSA_LEN) * t).Sum();
            }

            if (IsNegative)
            {
                res *= -1;
            }

            return res;
        }

        private static TNumber ToTNumber(double val)
        {
            var isNegative = val < 0;
            var target = (int)(Math.Abs(val) * Math.Pow(BASE, MANTISSA_LEN));
            var allDigits = new List<int>();
            var div = target / BASE;
            var mod = target % BASE;
            allDigits.Add(mod);
            while (div >= BASE)
            {
                mod = div % BASE;
                div /= BASE;
                allDigits.Add(mod);
            }
            allDigits.Add(div);

            while (allDigits.Count < MANTISSA_LEN + 1)
            {
                allDigits.Add(0);
            }
            
            var digits = allDigits.Skip(MANTISSA_LEN).ToArray();
            var mantissa = allDigits.Take(MANTISSA_LEN).ToArray();
            
            return new TNumber(isNegative, digits, mantissa);
        }


        public static TNumber operator +(TNumber num1, TNumber num2) => ToTNumber(num1.ToDecimal() + num2.ToDecimal());
        public static TNumber operator -(TNumber num1, TNumber num2) => ToTNumber(num1.ToDecimal() - num2.ToDecimal());
        public static TNumber operator *(TNumber num1, TNumber num2) => ToTNumber(num1.ToDecimal() * num2.ToDecimal());
        public static TNumber operator /(TNumber num1, TNumber num2) => ToTNumber(num1.ToDecimal() / num2.ToDecimal());




        public override string ToString()
        {
            var nIndent = IsNegative ? 1 : 0;

            var zeros = 0;
            foreach (var t in Mantissa)
            {
                if (t == 0)
                {
                    zeros++;
                }
                else
                {
                    break;
                }
            }

            var sMantissa = Mantissa.Skip(zeros).ToArray();
            var mIndent = sMantissa.Length > 0 ? 1 : 0;
            
            var chars = new char[nIndent + Digits.Length + mIndent + sMantissa.Length];

            if (IsNegative)
            {
                chars[0] = '-';
            }

            for (var i = 0; i < Digits.Length; i++)
            {
                chars[nIndent + i] = DIGITS[Digits[Digits.Length - i - 1]];
            }

            if (mIndent == 1)
            {
                chars[nIndent + Digits.Length] = '.';
            }
            
            for (var i = 0; i < sMantissa.Length; i++)
            {
                chars[nIndent + Digits.Length + mIndent + i] = DIGITS[sMantissa[sMantissa.Length - i - 1]];
            }

            return new string(chars);
        }
    }
}