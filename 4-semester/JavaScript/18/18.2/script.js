let out = document.getElementById("output")

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


function removeSpace(expr)
{
    let res = []
    for (let i in expr)
    {
        if (expr[i] != ' ')
        {
            res.push(expr[i])
        }
    }
    return res
}


function show()
{
    let expression = document.getElementById("formula").value
    expression = removeSpace(expression.split(''))
    let res = []
    let stack = []
    let s, tmp
    console.log(expression)
    
    for (let i in expression)
    {
        s = expression[i]
        // console.log(s)
        // console.log("STACK:", stack)
        if (s == '(')
        {
            stack.push(s)
            // console.log(s, "moved to STACK:", stack)
        }
        else if (s == ')')
        {
            // console.log("while entered")
            tmp = stack.pop()
            while (tmp != '(' && stack.length != 0)
            {
                res.push(tmp)
                tmp = stack.pop()
            }
            // console.log("RES:", res)
            // console.log("STACK:", stack)
        }
        else if (!isOperation(s))
        {
            res.push(s)
            // console.log(s, "moved to RES:", res)
        }
        else
        {
            // console.log(s, "is and operation")
            if (stack.length == 0)
            {
                stack.push(s)
                // console.log(s, "moved to STACK:", stack)
            }
            else
            {
                tmp = stack.pop()
                // console.log("while to be entered with", tmp, "STACK:", stack)
                while (stack.length != 0 && isOperation(tmp) && getPriority(s) <= getPriority(tmp))
                {
                    // console.log(tmp, "is and operation with higher priority than", s)
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
            // console.log("RES:", res)
            // console.log("STACK:", stack)
            
        }
    }
    while (stack.length > 0)
    {
        res.push(stack.pop())
    }
    out.innerText = res.join(' ')
}
