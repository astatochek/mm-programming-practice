let months = ["января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря"]
let days = ["воскресение", "понедельник", "вторник", "среду", "четверг", "пятницу", "субботу"]

function show()
{
    let out = document.getElementById("output")
    let res = ``
    let time = new Date()
    res += `В ${days[time.getDay()]} ${time.getDate()}-го ${months[time.getMonth()]} ${time.getFullYear()}-го года `
    res += `в ${time.getHours()} часа ${time.getMinutes()} минут и ${time.getSeconds()} секунд`
    out.innerText = res
}