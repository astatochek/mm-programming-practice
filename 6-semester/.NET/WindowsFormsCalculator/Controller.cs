using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsCalculator
{
    public class Controller
    {
        public Controller(TextBox input, TextBox inputAll)
        {
            Line = inputAll;
            Arg = input;
            Sequence = new List<object>();
            UnclosedBrackets = 0;
            IsShowingAnswer = false;
            PostfixNotationExpression = new PostfixNotationExpression();
        }

        private TextBox Arg { get; }
        private TextBox Line { get; }
        private List<object> Sequence { get; }
        
        private PostfixNotationExpression PostfixNotationExpression { get; set; }
        
        private readonly string[] _nums = { @".", @"0", @"1", @"2", @"3", @"4", @"5", @"6" };
        private readonly string[] _operators = { @"+", @"-", @"*", @"/", @"(", @")" };
        private readonly string[] _commands = { @"Clear", @"Delete", @"Backspace", @"=" };

        private int UnclosedBrackets { get; set; }
        private bool IsShowingAnswer { get; set; }

        public void Process(string button)
        {
            if (!_nums.Contains(button) && !_operators.Contains(button) && !_commands.Contains(button))
            {
                throw new ArgumentException($@"Command {button} is not supported");
            }

            if (IsShowingAnswer)
            {
                IsShowingAnswer = false;
                ClearArg();
                ClearLine();
                if (button == @"=")
                {
                    return;
                }
            }
            
            if (_nums.Contains(button))
            {
                ProcessArg(button);
                
            } else if (_operators.Contains(button))
            {
                ProcessOperand(button);
            } else if (_commands.Contains(button))
            {
                ProcessCommand(button);
            }
        }

        private void ProcessArg(string arg)
        {
            var next = Arg.Text;

            if (next.Length > 0 && next[0] == '.')
            {
                next = string.Join("", next.ToArray().Skip(1).ToArray()) + @".";
            }
            
            if (arg == @".")
            {
                if (Dots() < 1)
                {
                    next += arg;
                }
            }
            else if (next == @"0")
            {
                next = arg;
            }
            else if (_nums.Contains(arg))
            {
                next += arg;
            }

            switch (next.Length > 0)
            {
                case true when next[next.Length - 1] == '.':
                    next = @"." + string.Join("", next.ToArray().Take(next.Length - 1).ToArray());
                    break;
                case true when next[0] == '-':
                    next = string.Join("", next.ToArray().Skip(1).ToArray()) + @"-";
                    break;
            }

            if (next == @"")
            {
                next = @"0";
            }

            Arg.Text = next;
        }

        private void ProcessOperand(string operand)
        {
            var val = new TNumber(Arg.Text);
            switch (operand)
            {
                // If "(" was passed
                case @"(":
                {
                    UnclosedBrackets++;
                    if (Sequence.Count > 0 && Sequence.Last().GetType() == typeof(TNumber)) // If last element of `Sequence` was a `TNumber`, we add "* (" to `inputAll` and clear `input`
                    {
                        Add(@"*");
                        Add(@"(");
                        ClearArg();
                    }
                    else // If last element in `Sequence` wa an operand, we write "val (" in `inputAll` and clear `input`
                    {
                        if (Arg.Text != @"0")
                        {
                            Add(val);
                            Add(@"*");
                        }
                        Add(@"(");
                        ClearArg();
                    }

                    break;
                }
                case @")" when UnclosedBrackets <= 0:
                    return;
                case @")":
                    Add(val);
                    Add(@")");
                    ClearArg();
                    UnclosedBrackets--;
                    break;
                default:
                {
                    if (Sequence.Count > 0 && Sequence.Last().ToString() == @")")
                    {
                        Add(operand);
                        ClearArg();
                    }
                    else // If operand passed is not ")" or "(", we write "val operand" in `inputAll` and clear `input`
                    {
                        Add(val);
                        Add(operand);
                        ClearArg();
                    }
                    break;
                }
            }
        }

        private void ProcessCommand(string command)
        {
            switch (command)
            {
                case @"Clear":
                    ClearArg();
                    ClearLine();
                    break;
                case @"Delete":
                    ClearArg();
                    break;
                case @"Backspace":
                    if (Arg.Text.Length > 1)
                    {
                        Arg.Text = Arg.Text.Substring(0, Arg.Text.Length - 1);
                        ProcessArg("");
                        if (Arg.Text == @"0." || Arg.Text == @".")
                        {
                            ClearArg();
                        }
                    }
                    else
                    {
                        ClearArg();
                    }
                    break;
                case @"=":
                    if (UnclosedBrackets > 0)
                    {
                        MessageBox.Show($@"You have {UnclosedBrackets} unclosed '('");
                        break;
                    }
                    var val = new TNumber(Arg.Text);
                    if (Sequence.Count == 0)
                    {
                        Add(val);
                        Add(@"=");
                        Arg.Text = val.ToString();
                        IsShowingAnswer = true;
                        return;
                    }
                    if (Sequence.Last().ToString() == ")")
                    {
                        Add(@"=");
                    }
                    else
                    {
                        Add(val);
                        Add(@"=");
                    }
                    IsShowingAnswer = true;
                    try
                    {
                        Arg.Text = PostfixNotationExpression
                            .Calculate(
                                new List<object>(
                                    Sequence
                                        .Take(Sequence.Count - 1)
                                )
                            )
                            .ToString();
                    }
                    catch (DivideByZeroException)
                    {
                        ShowMessage(@"Cannot divide by zero");
                    }
                    catch (ArgumentException)
                    {
                        ShowMessage(@"Arithmetic overflow Error");
                    }
                    ProcessArg("");
                    break;
            }
        }

        private void Add(object val)
        {
            Sequence.Add(val);
            Update();
        }

        private void ClearLine()
        {
            Sequence.Clear();
            Update();
        }
        
        private void ClearArg()
        {
            Arg.Font = new System.Drawing.Font("JetBrains Mono SemiBold", 26F, System.Drawing.FontStyle.Bold);
            Arg.Text = @"0";
        }

        private int Dots() => Arg.Text.Count(t => t == '.');

        private void ShowMessage(string msg)
        {
            Arg.Font = new System.Drawing.Font("JetBrains Mono SemiBold", 20F, System.Drawing.FontStyle.Bold);
            Arg.Text = msg;
        }

        private void Update()
        {
            var formatted = new List<string>();
            for (var i = 0; i < Sequence.Count; i++)
            {
                var operand = Sequence[i];
                switch (operand.ToString())
                {
                    case @"(":
                        formatted.Add(@")");
                        break;
                    case @")":
                        formatted.Add(@"(");
                        break;
                    default:
                        formatted.Add(operand.ToString() == @"*" ? @"×" : operand.ToString());
                        break;
                }
                if (operand.ToString() != "(" && !(i < Sequence.Count - 1 && Sequence[i + 1].ToString() == ")"))
                {
                    formatted.Add(@" ");
                }
            }
            formatted.Reverse();
            Line.Text =  string.Join("", formatted);
        }
    }
}