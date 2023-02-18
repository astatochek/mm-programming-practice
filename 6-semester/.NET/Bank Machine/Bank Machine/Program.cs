
var targetValue = -1;
var isValidInput = false;
while (!isValidInput)
{
    Console.WriteLine("Enter the denomination of the banknote:");
    try
    {
        targetValue = Convert.ToInt32(Console.ReadLine());
        if (targetValue < 0)
        {
            Console.WriteLine("Entered number is invalid");
        }
        else
        {
            isValidInput = true;
        }
    }
    catch (Exception)
    {
        Console.WriteLine("Entered string is not a natural number");
    }
}

var bankMachineValues = new List<int>();
isValidInput = false;
while (!isValidInput)
{
    Console.WriteLine("Enter the list of denominations, available in the Bank Machine:");
    var endFlag = false;
    while (!endFlag)
    {
        try
        {
            var input = Array.ConvertAll(Console.ReadLine()!.Split(" ").ToArray(), int.Parse);
            foreach (var val in input)
            {
                if (val < 0)
                {
                    Console.WriteLine("Some values are invalid");
                    bankMachineValues.Clear();
                    endFlag = true;
                    break;
                }

                if (val == 0)
                {
                    endFlag = true;
                    isValidInput = true;
                    break;
                }
                bankMachineValues.Add(val);
            }
        }
        catch (Exception)
        {
            Console.WriteLine("Some values are invalid");
            bankMachineValues.Clear();
            break;
        }
    }

    if (isValidInput && bankMachineValues.Count == 0)
    {
        isValidInput = false;
        Console.WriteLine("No values int put");
    }
}

bankMachineValues = bankMachineValues.Distinct().ToList();
bankMachineValues.Sort();
bankMachineValues.Reverse();

Console.WriteLine($"Entered denomination of the banknote: {targetValue}");
Console.Write("Denominations, available in the Bank Machine:");
foreach (var val in bankMachineValues)
{
    Console.Write($" {val}");
}
Console.WriteLine();


var allCombinations = new List<List<int>>();

void PrintCombination(List<int> combination)
{
    for (var i = 0; i < combination.Count; i++)
    {
        if (combination[i] != 0)
        {
            Console.Write($"{combination[i]}x'{bankMachineValues![i]}' ");
        }
    }
    Console.WriteLine();
    combination.Clear();
}

void GetAllCombinations(int sum, int idx, List<int> combination)
{
    if (sum == 0)
    {
        PrintCombination(combination);
    } else if (idx < bankMachineValues!.Count)
    {
        for (var i = 0; i * bankMachineValues[idx] <= sum; i++)
        {
            var nextCombination = new List<int>(combination) { i };
            GetAllCombinations(sum - i * bankMachineValues[idx], idx + 1, nextCombination);
        }
    }
}

Console.WriteLine("All combinations:");
GetAllCombinations(targetValue, 0, new List<int>());