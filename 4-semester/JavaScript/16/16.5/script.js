let out = document.getElementById("output")

function getF(f)
{
    function func(x)
    {
        return eval(f)
    }
    return func
}

function getSections(pair, f)
{
    let left = pair[0]
    let right = pair[1]
    let n = 1000
    res = []
    for (let i = 0; i < n; i++)
    {
        if (f(left + i * (right - left) / n) * f(left + (i + 1) * (right - left) / n) < 0)
        {
            res.push([left + i * (right - left) / n, left + (i + 1) * (right - left) / n])
        }
    }
    return res
}

function bisection(section, f, e)
{
    let left = section[0]
    let right = section[1]
    let cen = left + (right - left) / 2

    if (f(cen) == 0 || (right - left) / 2 <= e)
    {
        return cen
    }
    else
    {
        if (f(cen) * f(right) < 0)
        {
            return bisection([cen, right], f, e)
        }
        else
        {
            return bisection([left, cen], f, e)
        }
    }
}


function show()
{
    let y = document.getElementById("func").value
    let a = Number(document.getElementById("left").value)
    let b = Number(document.getElementById("right").value)
    let eps = Number(document.getElementById("eps").value)
    out.innerText = ""
    let f = getF(y)
    let appr
    let sections = getSections([a, b], f)
    console.log(sections)
    for (let i = 0; i < sections.length; i++)
    {
        appr =  bisection(sections[i], f, eps)
        out.innerText += `Значение X: ${appr}\nПогрешность: ${Math.abs(f(appr))}\n`
    }
}