

function calc(obj)
{
    let a = Number(obj.num1.value)
    let b = Number(obj.num2.value)
    let c = Number(obj.num3.value)
    let d = Number(obj.num4.value)

    let val = 0

    if (a + b + c + d == 20) { val = 100 }
    else if (Math.min(Math.min(a, b), Math.min(c, d)) <= 3) { val = 0 }
    else { val = 75 }

    obj.res.value = `${val} у. е.`
}