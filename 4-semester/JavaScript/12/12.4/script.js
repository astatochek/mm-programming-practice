
function show()
{
    let s = document.getElementById("str").value
    let letter = document.getElementById("let").value
    let out = document.getElementById("output")
    let cnt = 0
    for (let i in s)
    {
        if (s[i] == letter)
        {
            cnt++
        }
    }
    out.innerText = `"${letter}" в "${s}" повторяется ${cnt} раз`
}