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


function merge(a, b)
{
    let m = a.length
    let n = b.length
    let i = 0
    let j = 0
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            out.innerText += ` ${a[i]}`
            i++
        }
        else
        {
            out.innerText += ` ${b[j]}`
            j++
        }
    }
    while (i < m)
    {
        out.innerText += ` ${a[i]}`
        i++
    }
    while (j < n)
    {
        out.innerText += ` ${b[j]}`
        j++
    }
}


function show()
{
    out.innerText = ""
    let arr1 = getNums(document.getElementById("arr1").value)
    let arr2 = getNums(document.getElementById("arr2").value)
    merge(arr1, arr2)
}