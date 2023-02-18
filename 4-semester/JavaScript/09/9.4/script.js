
function calc()
{
    let num = Number(document.getElementById("num").value)
    let out = document.getElementById("output")
    let res = num
    for (let i = num - 1; i > 1; i--)
    {
        res *= i
    }
    out.textContent = `${num}! = ${res}`
}