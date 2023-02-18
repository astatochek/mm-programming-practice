function care(a, h)
{
    return (a.value * h.value) / 2
}

function calculateCare()
{
    let val1 = document.f.input1
    let val2 = document.f.input2
    let out = document.getElementById("box")
    out.textContent = `Площадь равна: ${care(val1, val2)}`
}
