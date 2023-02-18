function isSinple(val)
{
    for (let i = 2; i < val / 2 + 1; i++)
    {
        if (val % i == 0)
        {
            return false
        }
    }
    return true
}

function check()
{
    let num = Number(document.getElementById("input").value)
    let out = document.getElementById("output")
    if (isSinple(num))
    {
        out.textContent = "Простое"
    }
    else
    {
        out.textContent = "Составное"
    }
}