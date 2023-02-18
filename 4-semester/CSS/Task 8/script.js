let blur = 30
let isbluring = false
let i = 0
let j = 0
let colors = [[245, 145, 0], [255, 255, 0], [120, 249, 81], [81, 249, 243], [100, 81, 249], [201, 81, 249], [249, 81, 162]]
let bg = ['rgb(220, 220, 220)', 'rgb(200, 200, 200)', 'rgb(186, 186, 186)', 'rgb(200, 200, 200)', 'rgb(220, 220, 220)', 'white']
function changeBG()
{
    let palette = bg[j]
    document.getElementById('col').style.backgroundColor = palette
    j = (j+1) % bg.length
}


function next()
{
    i = (i+1) % colors.length
    let palette = colors[i]
    document.getElementById('block').style.backgroundColor = `rgba(${palette[0]}, ${palette[1]}, ${palette[2]}, 1)`
    document.getElementById('block').style.filter = `drop-shadow(5px 5px 5px rgba(${palette[0]}, ${palette[1]}, ${palette[2]}, 0.5))`
}

function manageBlur()
{
    if (isbluring)
    {
        toblur()
    }
    else
    {
        unblur()
    }
}
function toblur()
{
    if (blur < 30)
    {
        blur += 1
        document.getElementById('target').style = `filter: blur(${blur}px);`
        setTimeout('toblur()', 10)
        return
    }
    isbluring = false
}
function unblur()
{
    if (blur > 0)
    {
        blur -= 1
        document.getElementById('target').style = `filter: blur(${blur}px);`
        setTimeout('unblur()', 10)
        return
    }
    isbluring = true
}