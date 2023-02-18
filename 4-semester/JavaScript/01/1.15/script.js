

function triangle(obj)
{
    let a = obj.st1.value
    let b = obj.st2.value
    let c = obj.st3.value

    let p = 1 * a + 1 * b + 1 * c
    obj.res1.value = p
    p /= 2
    let s = Math.sqrt(p * (p - a) * (p - b) * (p - c))
    obj.res2.value = s
}
