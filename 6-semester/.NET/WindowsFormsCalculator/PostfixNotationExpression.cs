using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WindowsFormsCalculator
{
    public class PostfixNotationExpression
    {
        public PostfixNotationExpression()
        {
            _operators = new List<string>(_standardOperators);
            
        }
        private readonly List<string> _operators;
        private readonly List<string> _standardOperators =
            new List<string>(new[] { "(", ")", "+", "-", "*", "/" });
        private static byte GetPriority(string s)
        {
            switch (s)
            {
                case "(":
                case ")":
                    return 0;
                case "+":
                case "-":
                    return 1;
                case "*":
                case "/":
                    return 2;
                default:
                    return 3;
            }
        }

        private IEnumerable<string> ConvertToPostfixNotation(List<object> input)
        {
            var outputSeparated = new List<string>();
            var stack = new Stack<string>();
            foreach (var c in input)
            {
                if (_operators.Contains(c.ToString()))
                {
                    if (stack.Count > 0 && !c.ToString().Equals("("))
                    {
                        if (c.ToString().Equals(")"))
                        {
                            var s = stack.Pop();
                            while (s != "(")
                            {
                                outputSeparated.Add(s);
                                s = stack.Pop();
                            }
                        }
                        else if (GetPriority(c.ToString()) > GetPriority(stack.Peek()))
                            stack.Push(c.ToString());
                        else
                        {
                            while (stack.Count > 0 && GetPriority(c.ToString()) <= GetPriority(stack.Peek()))
                                outputSeparated.Add(stack.Pop());
                            stack.Push(c.ToString());
                        }
                    }
                    else
                        stack.Push(c.ToString());
                }
                else
                    outputSeparated.Add(c.ToString());
            }

            if (stack.Count <= 0) return outputSeparated.ToArray();
            {
                outputSeparated.AddRange(stack);
            }

            return outputSeparated.ToArray();
        }
        public TNumber Calculate(List<object> input)
        {
            var stack = new Stack<string>();
            var queue = new Queue<string>(ConvertToPostfixNotation(input));
            var str = queue.Dequeue();
            while (queue.Count >= 0)
            {
                if (!_operators.Contains(str))
                {
                    stack.Push(str);
                    str = queue.Dequeue();
                }
                else
                {
                    var sum = new TNumber("0");
                    switch (str)
                    {
                        case "+":
                        {
                            var a = new TNumber(stack.Pop());
                            Check(a);
                            var b = new TNumber(stack.Pop());
                            Check(b);
                            sum = a + b; 
                            Check(sum);
                            break;
                        }
                        case "-":
                        {
                            var a = new TNumber(stack.Pop());
                            Check(a);
                            var b = new TNumber(stack.Pop());
                            Check(b);
                            sum = b - a;
                            Check(sum);
                            break;
                        }
                        case "*":
                        {
                            var a = new TNumber(stack.Pop());
                            Check(a);
                            var b = new TNumber(stack.Pop());
                            Check(b);
                            sum = b * a;
                            Check(sum);
                            break;
                        }
                        case "/":
                        {
                            var a = new TNumber(stack.Pop());
                            Check(a);
                            var b = new TNumber(stack.Pop());
                            Check(b);
                            if (a.ToString() == @"0")
                            {
                                throw new DivideByZeroException();
                            }
                            sum = b / a;
                            Check(sum);
                            break;
                        }
                    }
                    stack.Push(sum.ToString());
                    if (queue.Count > 0)
                        str = queue.Dequeue();
                    else
                        break;
                }
                
            }

            // MessageBox.Show($@"Result is {new TNumber(stack.Pop())}");
            return new TNumber(stack.Pop());
        }
        
        private static void Check(TNumber val)
        {
            try
            {
                var tmp = val.ToString();
            }
            catch (Exception)
            {
                throw new ArgumentException();
            }
        }
    }
}