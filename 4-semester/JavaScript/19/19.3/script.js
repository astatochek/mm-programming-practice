
let week = ["Вс", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб"]

let par = {
    day: 'numeric',
    month: 'long',
  }


let holidays = [
    [1, 0, "Новый Год"],
    [7, 0, "Рождество Христово"],
    [14, 0, "Старый Новый Год"],
    [25, 0, "День студентов"],
    [8, 1, "Масленица"],
    [8, 2, "Международный женский день"],
    [1, 3, "Первое апреля"],
    [1, 4, "Праздник весны и труда"],
    [7, 7, "Иван Купала"],
    [1, 9, "День знаний"],
    [5, 10, "День учителя"],
    [28, 11, "День матери"],
]

function isHoliday(date)
{
    for (let i in holidays)
        if (date.getDate() == holidays[i][0] && date.getMonth() == holidays[i][1])
            return true
    return false
}

function getHoliday(date)
{
    for (let i in holidays)
        if (date.getDate() == holidays[i][0] && date.getMonth() == holidays[i][1])
            return holidays[i][2]
}



function putCol(ind, output, start, end, today) // создает колонки итоговой таблицы и заполняет ячейками
{
    let div = document.createElement('div')
    div.className = "col";
    let cur = new Date(start)
    let head = document.createElement('div')
    head.className = "cellH"
    head.innerText = week[ind]
    div.append(head)
    let num = (Number(end) - Number(start)) / (24 * 3600 * 1000)
    let cell
    for (let j = 0; j <= num; j++)
    {
        if (cur.getDay() == ind) // если нужный день недели
        {
            cell = document.createElement('div')

            if (Number(cur) == Number(today))
            {
                cell.className = "cellT"
                cell.innerText = cur.getDate()
            }
            else if (cur.getMonth() == today.getMonth())
            {
                console.log(cur.getMonth())
                cell.className = "cell"
                cell.innerText = cur.getDate()  
            }
            else cell.className = "cell"

            div.append(cell)
        }
        cur.setDate(cur.getDate() + 1)
    }
    output.append(div)
}


function getList() // обработка входных данных и все остальное
{
    let today = new Date()
    today.setFullYear(document.getElementById("Year").value)
    let options = document.getElementById("Month").options
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            today.setMonth(i)
        }
    }
    today.setDate(Number(document.getElementById("Date").value))
    console.log(today)

    let toRemove = document.getElementsByClassName("output") // освобождаем блоки вывода
    while (toRemove.length != 0)
    {
        toRemove[0].remove()
    }

    out = document.getElementById("outputWrapper")
    let div = document.createElement('div') // создаем пустой блок для вывода
    div.className = "output";
    div.id = "out"
    out.append(div)
    let message = document.createElement('div')
    message.className = "text"
    message.id = "message"
    div.append(message)
    let table = document.createElement('div')
    table.className = "table"
    

    let first = new Date(today)
    while (first.getMonth() == today.getMonth())
    {
        first.setDate(first.getDate() - 1)
    }
    if (first.getDay() == 6)
    {
        first.setDate(first.getDate() + 1)
    }
    while (first.getDay() != 0)
    {
        first.setDate(first.getDate() - 1)
    }


    let last = new Date(today)
    while (last.getMonth() == today.getMonth())
    {
        last.setDate(last.getDate() + 1)
    }
    if (last.getDay() == 0)
    {
        last.setDate(last.getDate() - 1)
    }
    while (last.getDay() != 6)
    {
        last.setDate(last.getDate() + 1)
    }
    console.log(first, last)


    div.append(table)

    for (let i = 0; i <= 6; i++)
    {
        putCol(i, table, first, last, today)
    }

    let mes = document.getElementById("message")
    let cur = new Date(today)
    while (!isHoliday(cur))
        cur.setDate(cur.getDate() + 1)
    mes.innerHTML = `Ближайший праздник будет <b>${cur.toLocaleString("ru", par)}</b> - <b>${getHoliday(cur)}</b>`
}