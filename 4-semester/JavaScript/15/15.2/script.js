let out = document.getElementById("output")

function getNums(str)
{
    let cur = ""
    let res = []
    for (let i = 0; i < str.length; i++)
    {
        if (str[i] == " ")
        {
            res.push(Number(cur))
            cur = ""
        }
        else
        {
            cur += str[i]
        }
    }
    if (cur != "")
    {
        res.push(Number(cur))
    }
    return res
}

function show()
{
    let f = document.getElementById("func").value
    let pair = getNums(document.getElementById("xy").value)
    let x = pair[0], y = pair[1]
    if (eval(f))
    {
        out.innerText = `Точка (${x}, ${y}) принадлежит области`
    }
    else
    {
        out.innerText = `Точка (${x}, ${y}) не принадлежит области`
    }
}