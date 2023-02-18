

function processAction(obj, code)
{
    let newBorder = Number(obj.B.value)
    let newPadding = Number(obj.P.value)
    let newMargin = Number(obj.M.value)

    let array = document.getElementsByClassName("cell")

    for (let i = 0; i < array.length; i++)
    {
        if (code == 1)
        {
            array[i].style.border = `${newBorder}px  solid rgb(230, 230, 230)`
            continue
        }
        if (code == 2)
        {
            array[i].style.padding = `${newPadding}px`
            continue
        }
        if (code == 3)
        {
            array[i].style.margin = `${newMargin}px`
            continue
        }
    }
}