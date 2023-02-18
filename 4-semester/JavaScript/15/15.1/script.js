let out = document.getElementById("output")

function round(num)
{
    return Math.round(num * 1000) / 1000
}

function show()
{
    let y = document.getElementById("func").value
    let a = Number(document.getElementById("left").value)
    let b = Number(document.getElementById("right").value)
    let n = Number(document.getElementById("num").value)
    out.innerText = ""
    let x = a
    for (let i = 0; i < n; i++)
    {
        x = a + i * (b - a) / (n - 1)
        out.innerText += `${i+1}: f(${round(x)}): ${round(eval(y))}\n`
    }
}