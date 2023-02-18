
function getLine(str)
{
    let res = ""
    for (let i = 0; i < str.length; i++)
    {
        if (str[i] != " ")
        {
            res += str[i]
        }
    }
    return res
}

function check(str)
{
    for (let i = 0; i < str.length / 2 + 1; i++)
    {
        if (str[i] != str[str.length - 1 - i])
        {
            return false
        }
    }
    return true
}


function show()
{
    let s = document.getElementById("str").value
    let out = document.getElementById("output")
    if (check(getLine(s)))
    {
        out.innerText = `является палиндромом`
    }
    else
    {
        out.innerText = `не является палиндромом`
    }
    
}