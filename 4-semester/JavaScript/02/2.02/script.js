

function minmax(obj)
{
    let a = Number(obj.num1.value)
    let b = Number(obj.num2.value)
    let c = Number(obj.num3.value)

    obj.res1.value = Math.max(Math.max(a, b), c)
    obj.res2.value = Math.min(Math.min(a, b), c)
}