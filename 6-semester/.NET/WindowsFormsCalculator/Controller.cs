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
        
        private readonly string[] _nums = { @".", @"0", @"1", @"2", @"3", @"4", @"5", @"6", @"7", @"8", @"9", @"A", @"B", @"C", @"D" };
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
            if (arg == @".")
            {
                if (Dots() < 1)
                {
                    Arg.Text += arg;
                }
            }
            else if (Arg.Text == @"0")
            {
                Arg.Text = arg;
            }
            else
            {
                Arg.Text += arg;
            }
        }

        private void ProcessOperand(string operand)
        {
            var val = new TNumber(Arg.Text);
            if (operand == @"(") // If "(" was passed
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
            }
            else if (operand == @")")
            {
                if (UnclosedBrackets <= 0) return;
                Add(val);
                Add(@")");
                ClearArg();
                UnclosedBrackets--;
            }
            else if (Sequence.Count > 0 && Sequence.Last().ToString() == @")")
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
                        Add(@"0");
                        Add(@"=");
                        Arg.Text = @"0";
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
                    Arg.Text = PostfixNotationExpression
                        .Calculate(
                            new List<object>(
                                Sequence
                                    .Take(Sequence.Count - 1)
                                )
                            )
                        .ToString();
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
            Arg.Text = @"0";
        }

        private int Dots() => Arg.Text.Count(t => t == '.');

        private void Update()
        {
            var formatted = new List<string>();
            for (var i = 0; i < Sequence.Count; i++)
            {
                var operand = Sequence[i];
                formatted.Add(operand.ToString() == @"*" ? @"×" : operand.ToString());
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