let out = document.getElementById("output")

let symbols = ['+', '-', '*', '%']

function getExpression(a, b, c, d)
{
    let s
    for (let i = 0; i < symbols.length; i++)
    {
        for (let j = 0; j < symbols.length; j++)
        {
            s = `a ${symbols[i]} b ${symbols[j]} c == d`
            console.log(s)
            if (eval(s))
            {
                out.innerText += `${a} ${symbols[i]} ${b} ${symbols[j]} ${c} = ${d}\n`
            }
        }
    }

}

function show()
{
    let A = Number(document.getElementById("a").value)
    let B = Number(document.getElementById("b").value)
    let C = Number(document.getElementById("c").value)
    let D = Number(document.getElementById("d").value)
    out.innerText = ``
    getExpression(A, B, C, D)
}
