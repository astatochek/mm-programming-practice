

function processAction()
{
    let index = -1
    if (document.getElementById("dot 1").checked)
    {
        index = 1
    }
    else if (document.getElementById("dot 2").checked)
    {
        index = 2
    }
    else if (document.getElementById("dot 3").checked)
    {
        index = 3
    }
    let obj = document.getElementById(`dot ${index}`)
    document.getElementById("output").textContent = `Вы выбрали: ${obj.value}`
}