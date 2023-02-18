

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
    document.getElementById("output").textContent = `Вы выбрали Вариант ${index + 1}`
}