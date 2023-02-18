function care(obj)
{
    return (obj.input1.value * obj.input2.value) / 2
}

function calculateCare()
{
    let val = document.f
    let out = document.getElementById("box")
    out.textContent = `Площадь равна: ${care(val)}`
}
