
function calc()
{
    let num = Number(document.getElementById("num").value)
    let out = document.getElementById("output")
    let res = 1
    for (let i = 2; i <= num; i++)
    {
        res *= i
    }
    out.textContent = `${num}! = ${res}`
}