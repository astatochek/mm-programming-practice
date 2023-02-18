

function processAction(obj)
{
    let val1 = Number(obj.MA.value)
    let val2 = Number(obj.AT.value)
    let val3 = Number(obj.T.value)
    let val4 = Number(obj.TY.value)

    let sum = val1 + val2 + val3 + val4

    let array = document.getElementsByClassName("bar")

    for (let i = 0; i < 4; i++)
    {
        console.log(array[i])
    }

    array[0].style.height = `${val1 * 100 / sum}%`
    array[1].style.height = `${val2 * 100 / sum}%`
    array[2].style.height = `${val3 * 100 / sum}%`
    array[3].style.height = `${val4 * 100 / sum}%`
}

function showStat(val, obj, flag)
{
    if (flag)
    {
        let arr = [Number(obj.MA.value), Number(obj.AT.value), Number(obj.T.value), Number(obj.TY.value)]

        let sum = arr[0] + arr[1] + arr[2] + arr[3]

        let box = document.getElementById(val)

        if (arr[val - 1] != 0)
        {
            box.textContent = `${Math.round(arr[val - 1] * 10000 / sum) / 100}%`
        }
    }
    else
    {
        let box = document.getElementById(val)
        box.textContent = ""
    }
    

}