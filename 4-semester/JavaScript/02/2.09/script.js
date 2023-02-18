
let minWidth = 500

let maxWidth = 1600

let flag = false

function change()
{
    flag = !flag
    if (flag)
    {
        changeSizeDown()
    }
    else
    {
        changeSizeUp()
    }
}

function changeSizeDown()
{
    let pic = document.getElementById("pic")

    pic.width -= 1

    if (pic.width <= minWidth || !flag)
    {
        return
    }

    setTimeout("changeSizeDown()", 1)
}

function changeSizeUp()
{
    let pic = document.getElementById("pic")

    pic.width += 1

    if (pic.width >= maxWidth || flag)
    {
        return
    }

    setTimeout("changeSizeUp()", 1)
}