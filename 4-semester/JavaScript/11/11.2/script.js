let months = ["Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"]
let days = ["Воскресение", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"]

function getTime()
{
    let out = document.getElementById("output")
    out.innerText = ""
    let time = new Date()
    out.innerText += `Год: ${time.getFullYear()}\n`
    out.innerText += `Месяц: ${months[time.getMonth()]}\n`
    out.innerText += `Число: ${time.getDate()}\n`
    out.innerText += `День: ${days[time.getDay()]}\n`
    out.innerText += `Время: `

    let hours = time.getHours()
    let minutes = time.getMinutes()
    let seconds = time.getSeconds()
    if (hours < 10)
    {
        out.innerTextt += "0"
    }
    out.innerText += `${hours}:`
    if (minutes < 10)
    {
        out.innerText += "0"
    }
    out.innerText += `${minutes}:`
    if (seconds < 10)
    {
        out.innerText += "0"
    }
    out.innerText += `${seconds}`
}