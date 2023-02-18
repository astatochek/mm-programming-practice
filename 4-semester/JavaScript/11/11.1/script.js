
function getTime()
{
    let out = document.getElementById("output")
    out.textContent = ""
    let time = new Date()
    let hours = time.getHours()
    let minutes = time.getMinutes()
    let seconds = time.getSeconds()
    if (hours < 10)
    {
        out.textContent += "0"
    }
    out.textContent += `${hours}:`
    if (minutes < 10)
    {
        out.textContent += "0"
    }
    out.textContent += `${minutes}:`
    if (seconds < 10)
    {
        out.textContent += "0"
    }
    out.textContent += `${seconds}`
}