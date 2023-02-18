let out = document.getElementById("output")

function getArray(str)
{
    let cur = ""
    let res = []
    for (let i = 0; i < str.length; i++)
    {
        if (str[i] == " ")
        {
            res.push(cur)
            cur = ""
        }
        else
        {
            cur += str[i]
        }
    }
    if (cur != "")
    {
        res.push(cur)
    }
    return res
}

function getNumberOfLetter(letter)
{
    let startPos = 'а'.charCodeAt(0)
    let currentPos = letter.toLowerCase().charCodeAt(0);
    console.log(letter, currentPos - startPos)
    return currentPos - startPos;
}

function getSize(str, num)
{
    let res = 0
    let j = num
    for (let i = 0; i < str.length; i++)
    {
        res += Math.pow(100, j) * getNumberOfLetter(str[i])
        j--
    }
    console.log(str, res)
    return res
}

function compare(a, b)
{
    let num = Math.max(a.length, b.length)
    return getSize(a, num) <= getSize(b, num)
}


function merge(a, b)
{
    let m = a.length
    let n = b.length
    let i = 0
    let j = 0
    while (i < m && j < n)
    {
        if (compare(a[i], b[j]))
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
    let arr1 = getArray(document.getElementById("arr1").value)
    let arr2 = getArray(document.getElementById("arr2").value)
    merge(arr1, arr2)
}