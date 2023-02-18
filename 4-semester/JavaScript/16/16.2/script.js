let out = document.getElementById("output")

function factorial(n)
{
    if (n != 1)
    {
        return n * factorial(n - 1)
    }
    return n
}

function show()
{
    let num = Number(document.getElementById("num").value)
    out.innerText = `${num}! = ${factorial(num)}`
}