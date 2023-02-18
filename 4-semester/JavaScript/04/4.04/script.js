

function processAction()
{
    let arr = document.getElementsByName("field")
    let index = 0
    for (let i = 0; i < arr.length; i++)
    {
        if (arr[i].checked)
        {
            index = i
        }
    }
    let obj = document.getElementById(`dot ${index + 1}`)
    document.getElementById("output").textContent = `Вы выбрали: ${obj.value}`
}