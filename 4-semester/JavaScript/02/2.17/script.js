

let firstIndex = -1
let secondIndex = -1

function processAction(ind)
{
    if (firstIndex == -1)
    {
        firstIndex = ind
    }
    else if (secondIndex == -1)
    {
        secondIndex = ind

        let tmp = document.getElementById(`${firstIndex}`).src

        document.getElementById(`${firstIndex}`).src = document.getElementById(`${secondIndex}`).src
        document.getElementById(`${secondIndex}`).src = tmp

        firstIndex = -1
        secondIndex = -1
    }
    
}