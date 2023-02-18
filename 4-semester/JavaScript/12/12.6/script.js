
function getList(str)
{
    let cur = ""
    let res = []
    for (let i = 0; i < str.length; i++)
    {
        if (str[i] == " " || str[i] == "\n")
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


function show()
{
    let text = document.getElementById("input").value
    console.log(text)
    let s = document.getElementById("str").value
    let out = document.getElementById("output")
    let cnt = 0
    let arr = getList(text)
    console.log(arr)
    for (let i in arr)
    {
        if (arr[i] == s)
        {
            cnt++
        }
    }
    out.innerText = `Количество повторений: ${cnt}`
}