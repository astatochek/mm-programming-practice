

function processAction(obj)
{
    let ind1 = Number(obj.num1.value)
    let ind2 = Number(obj.num2.value)

    let tmp = document.getElementById(`${ind1}`).src

    document.getElementById(`${ind1}`).src = document.getElementById(`${ind2}`).src
    document.getElementById(`${ind2}`).src = tmp
    
    obj.num1.value = ""
    obj.num2.value = ""
}