let out = document.getElementById("output")

function getSections(pair, f)
{
    let left = pair[0]
    let right = pair[1]
    let n = 1000
    let x = 0
    let y1 = 0
    let y2 = 0
    res = []
    for (let i = 0; i < n; i++)
    {
        x = left + i * (right - left) / n
        y1 = eval(f)
        x = left + (i + 1) * (right - left) / n
        y2 = eval(f)

        if (y1 * y2 < 0)
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
    let x = 0, y1 = 0, y2 = 0

    x = cen

    if (eval(f) == 0)
    {
        return cen
    }
    else
    {
        while ((right - left) / 2 >= e)
        {
            x = cen
            y1 = eval(f)
            x = right
            y2 = eval(f)

            if (y1 * y2 < 0)
            {
                left = cen
            }
            else
            {
                right = cen
            }
            cen = left + (right - left) / 2
            x = cen
            if (eval(f) == 0)
            {
                break
            }
        }
    }

    return cen
}



function show()
{
    let y = document.getElementById("func").value
    let a = Number(document.getElementById("left").value)
    let b = Number(document.getElementById("right").value)
    let eps = Number(document.getElementById("eps").value)
    out.innerText = ""
    let appr = 0, x = 0
    let sections = getSections([a, b], y)
    console.log(sections)
    for (let i = 0; i < sections.length; i++)
    {
        appr =  bisection(sections[i], y, eps)
        x = appr
        out.innerText += `Значение X: ${appr}\nПогрешность: ${Math.abs(eval(y))}\n`
    }
}