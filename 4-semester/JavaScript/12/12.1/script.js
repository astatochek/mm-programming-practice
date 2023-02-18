
function show()
{
    let s = document.getElementById("num").value
    let out = document.getElementById("output")
    out.innerText = ``
    for (let i in s)
    {
        out.innerText += `${s[i]}\n`
    }
}