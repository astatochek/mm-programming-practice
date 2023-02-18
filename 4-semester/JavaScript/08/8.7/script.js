function f(x)
{
    return Math.sin(x * x + 1)
}

function calc()
{
    let t = Number(document.getElementById("t").value)
    let eps = Number(document.getElementById("eps").value)
    let out = document.getElementById("output")

    let first = t
    let second = f(first)

    while (Math.abs(first - second) >= eps)
    {
        first = second
        second = f(first)
    }

    out.textContent = `${second}`
}