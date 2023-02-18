

let curTop = 181

let curLeft = 244

let d = 25


function moveLeft()
{
    if (curLeft <= 0)
    {
        return
    }
    curLeft -= d
    document.getElementById("p").style.left = `${curLeft}px`
}


function moveRight()
{
    if (curLeft >= 470)
    {
        return
    }
    curLeft += d
    document.getElementById("p").style.left = `${curLeft}px`
}


function moveUp()
{
    if (curTop <= -50)
    {
        return
    }
    curTop -= d
    document.getElementById("p").style.top = `${curTop}px`
}


function moveDown()
{
    if (curTop >= 420)
    {
        return
    }
    curTop += d
    document.getElementById("p").style.top = `${curTop}px`
}