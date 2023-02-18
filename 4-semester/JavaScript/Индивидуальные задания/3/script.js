
let week = ["Вс", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб"]

let opts = {
    month: 'long',
    year: 'numeric'
}


function formatDate(num)
{
    let date = new Date(Number(num))
    let dd = date.getDate();
    if (dd < 10) dd = '0' + dd;
  
    let mm = date.getMonth() + 1;
    if (mm < 10) mm = '0' + mm;
  
    let yy = date.getFullYear() % 100;
    if (yy < 10) yy = '0' + yy;
  
    return dd + '.' + mm + '.' + yy;
}


function getToday()
{
    let now = new Date()
    show(Number(now))
}


function darken(num)
{
    document.getElementById(`${num}`).style = "background-color: rgb(200, 200, 200);"
}


function lighten(num)
{
    document.getElementById(`${num}`).style = "background-color: rgb(239, 239, 239);"
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
            let num = Number(cur)
            cell.id = num

            if (Number(cur) == Number(today))
            {
                cell.className = "cellT"
                cell.innerText = cur.getDate()
            }
            else if (cur.getMonth() == today.getMonth())
            {
                // console.log(cur.getMonth())
                cell.className = "cell"
                cell.innerText = cur.getDate()  
                cell.addEventListener("mouseout", () => lighten(num))
                cell.addEventListener("mouseover", () => darken(num))
            }
            else
            {
                cell.className = "cell"
                cell.addEventListener("mouseout", () => lighten(num))
                cell.addEventListener("mouseover", () => darken(num))
            }
            cell.addEventListener("click", () => show(num))
            cell.title = formatDate(num)

            div.append(cell)
        }
        cur.setDate(cur.getDate() + 1)
    }
    output.append(div)
}




function useInput()
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
    // console.log(today)
    return Number(today)
}


function start()
{
    show(useInput())
}


function moveMonth(next)
{
    let date = new Date(useInput())
    console.log("DATE:", date)
    let cur = new Date(date)
    if (next)
    {
        while(cur.getMonth() == date.getMonth())
            cur.setDate(cur.getDate() + 1)
    }
    else
    {
        while(cur.getMonth() == date.getMonth())
            cur.setDate(cur.getDate() - 1)
    }
    console.log("CUR: ", cur)
    show(Number(cur))
}


function show(num) // обработка входных данных и все остальное
{
    let today = new Date(num)
    document.getElementById("Month").value = today.getMonth() + 1
    document.getElementById("Year").value = today.getFullYear()
    document.getElementById("Date").value = today.getDate()
    console.log(today)
    let toRemove = document.getElementsByClassName("output") // освобождаем блоки вывода
    while (toRemove.length != 0)
    {
        toRemove[0].remove()
    }

    document.getElementById("name").innerText = today.toLocaleString("ru", opts)

    out = document.getElementById("outputWrapper")
    let div = document.createElement('div') // создаем пустой блок для вывода
    div.className = "output";
    div.id = "out"
    out.append(div)
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
    // console.log(first, last)

    let leftArrow = document.createElement('div')
    leftArrow.className = "mover"
    leftArrow.innerText = "<"
    leftArrow.id = "left"
    leftArrow.addEventListener('click', () => moveMonth(false))
    leftArrow.addEventListener("mouseover", () => darken("left"))
    leftArrow.addEventListener("mouseout", () => lighten("left"))
    div.append(leftArrow)

    div.append(table)

    let rightArrow = document.createElement('div')
    rightArrow.className = "mover"
    rightArrow.innerText = ">"
    rightArrow.id = "right"
    rightArrow.addEventListener('click', () => moveMonth(true))
    rightArrow.addEventListener("mouseover", () => darken("right"))
    rightArrow.addEventListener("mouseout", () => lighten("right"))
    div.append(rightArrow)


    

    for (let i = 0; i <= 6; i++)
    {
        putCol(i, table, first, last, today)
    }

}