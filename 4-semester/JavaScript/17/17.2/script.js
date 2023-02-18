let out = document.getElementById("output")

let symbol = ['+', '-', '*', '%']

function getExpression(a, b, c, d, e, f, g)
{
    let s
    for (let i = 0; i < symbol.length; i++)
    {
        for (let j = 0; j < symbol.length; j++)
        {
            for (let k = 0; k < symbol.length; k++)
            {
                for (let l = 0; l < symbol.length; l++)
                {
                    for (let n = 0; n < symbol.length; n++)
                    {
                        s = `a ${symbol[i]} (b ${symbol[j]} (c ${symbol[k]} (d ${symbol[l]} (e ${symbol[n]} f)))) == g`
                        if (eval(s))
                        {
                            out.innerText += `${a} ${symbol[i]} (${b} ${symbol[j]} (${c} ${symbol[k]} (${d} ${symbol[l]} (${e} ${symbol[n]} ${f})))) = ${g}\n`
                        }
                    }
                }
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
    let E = Number(document.getElementById("e").value)
    let F = Number(document.getElementById("f").value)
    let G = Number(document.getElementById("g").value)
    out.innerText = ``
    getExpression(A, B, C, D, E, F, G)
}