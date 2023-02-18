let options = 
[
    "brightness(0.4)",
    "blur(5px)",
    "contrast(200%)",
    "drop-shadow(16px 16px 20px rgb(101, 101, 169))",
    "grayscale(90%)",
    "hue-rotate(90deg)",
    "invert(75%)",
    "opacity(25%)",
    "saturate(30%)",
    "sepia(60%)"
]

let set = []
for (let {} in options) set.push(false)

function choose(id)
{
    if (set[id])
    {
        set[id] = false
        document.getElementById(id).style.backgroundColor = "rgb(159, 46, 46)"
    }
    else
    {
        set[id] = true
        document.getElementById(id).style.backgroundColor = "rgb(89, 205, 114)"
    }
    line = ""
    for (let i = 0; i < set.length; i++) if (set[i]) line += options[i] + " "
    document.getElementById("target").style = `filter: ${line}`
}
