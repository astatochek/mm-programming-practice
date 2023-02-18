
let flag = false

function change()
{
    let pic = document.getElementById("pic")

    flag = !flag
    
    pic.src = `annie${Number(flag) + 1}.png` 

    console.log(flag)
}