let out1 = document.getElementById("output 1")
let out2 = document.getElementById("output 2")
let out3 = document.getElementById("output 3")

let symbols = ['+', '-', '*', '/']


function getPriority(s)
{
    for (let i in symbols)
    {
        if (symbols[i] == s)
        {
            return i
        }
    }
    return -1
}


function isOperation(s)
{
    for (let i in symbols)
    {
        if (symbols[i] == s)
        {
            return true
        }
    }
    return false
}


function getPolska(expr)
{
    let res = []
    let stack = []
    let s, tmp
    for (let i in expr)
    {
        s = expr[i]
        if (s == '(')
        {
            stack.push(s)
        }
        else if (s == ')')
        {
            tmp = stack.pop()
            while (tmp != '(' && stack.length != 0)
            {
                res.push(tmp)
                tmp = stack.pop()
            }
        }
        else if (!isOperation(s))
        {
            res.push(s)
        }
        else
        {
            if (stack.length == 0)
            {
                stack.push(s)
            }
            else
            {
                tmp = stack.pop()
                while (stack.length != 0 && isOperation(tmp) && getPriority(s) <= getPriority(tmp))
                {
                    res.push(tmp)
                    tmp = stack.pop()
                }
                if (isOperation(tmp) && getPriority(s) <= getPriority(tmp))
                {
                    res.push(tmp)
                }
                else
                {
                    stack.push(tmp)
                }
                stack.push(s)
            } 
        }
    }
    while (stack.length > 0)
    {
        res.push(stack.pop())
    }
    return res.join(' ')
}


function calc(p)
{
    let s, a, b
    let stack = []
    for (i in p)
    {
        s = p[i]
        console.log(s)
        if (!isOperation(s))
        {
            stack.push(s)
        }
        else
        {
            b = Number(stack.pop())
            a = Number(stack.pop())
            switch(s)
            {
                case '+': 
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
            }
        }
    }
    return stack.pop()
}


function show()
{
    let expression = document.getElementById("formula").value
    expression = expression.split(' ')
    
    console.log(expression)

    let polska = getPolska(expression)
    
    out1.innerText = polska
    out2.innerText = calc(polska.split(' '))
    out3.innerText = eval(expression.join(' '))
}
