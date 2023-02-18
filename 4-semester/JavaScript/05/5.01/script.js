let sum = 0
let signed = [false, false, false, false, false, false]

function processAction(val, index)
{
    if (!signed[index])
    {
        signed[index] = true
        sum += val
    }
    else
    {
        signed[index] = false
        sum -= val
    }
    document.getElementById("output").textContent = `С вас ${sum}$ сверху`
}