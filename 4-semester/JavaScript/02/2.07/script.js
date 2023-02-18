
let k = 1

let flag = true

function ref()
{
    flag = false
}

function next()
{
    let d = document
    
    if (flag)
    {
        d.pic.src = `p${k}.png`
        k = (k + 1) % 7 + 1

        setTimeout('next()', 1500)
    }
    else
    {
        return
    }
    
}