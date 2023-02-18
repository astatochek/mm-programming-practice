let out = document.getElementById("output")

function toBinary(n, s)
{
    if (n != 0)
    {
        return toBinary(Math.floor(n / 2), `${n % 2}` + s)
    }
    return s
}

function show()
{
    let num = Number(document.getElementById("num").value)
    out.innerText = toBinary(num, ``)
}