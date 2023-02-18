

function calc()
{
    let f = document.getElementById("func").value
    let t = Number(document.getElementById("t").value)
    let eps = Number(document.getElementById("eps").value)
    let out = document.getElementById("output")

    let x = t
    let x1 = eval(f)

    while (Math.abs(x - x1) >= eps)
    {
        x = x1
        x1 = eval(f)
    }

    out.textContent = `${x1}`
}