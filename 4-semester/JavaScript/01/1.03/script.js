function care(a, h)
{
    return a * h / 2
}

function calculateCare()
{
    let val1 = document.f.input1.value
    let val2 = document.f.input2.value
    let out = document.getElementById("box")
    out.textContent = `Площадь равна: ${care(val1, val2)}`
}
