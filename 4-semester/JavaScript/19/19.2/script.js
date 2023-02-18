
function formatDate(date)
{
    let dd = date.getDate();
    if (dd < 10) dd = '0' + dd;

    let mm = date.getMonth() + 1;
    if (mm < 10) mm = '0' + mm;

    let yy = date.getFullYear() % 100;
    if (yy < 10) yy = '0' + yy;

    return dd + '.' + mm + '.' + yy;
}


function getChosen(options) // возвращает выбранный в select элемент
{
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            return options[i]
        }
    }
}


function putCol(text, output, num, putNums) // создает колонки итоговой таблицы и заполняет ячейками
{
    let div = document.createElement('div')
    div.className = "col";
    let cell
    for (let i = 0; i <= num; i++)
    {
        cell = document.createElement('div')
        cell.className = "cell"
        if (i == 0)
        {
            cell.innerText = text
        }
        else if (putNums)
        {
            cell.innerText = i
        }
        div.append(cell)
    }
    output.append(div)
}


function getList() // обработка входных данных и все остальное
{
    let startDate = new Date()
    startDate.setDate(document.getElementById("startDate").value)
    startDate.setFullYear(document.getElementById("startYear").value)
    let options = document.getElementById("startMonth").options
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            startDate.setMonth(i)
        }
    }
    console.log(startDate)

    let endDate = new Date()
    endDate.setDate(document.getElementById("endDate").value)
    endDate.setFullYear(document.getElementById("endYear").value)
    options = document.getElementById("endMonth").options
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            endDate.setMonth(i)
        }
    }
    console.log(endDate)

    let chosenDay = 0
    options = document.getElementById("dayOfWeek").options
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            chosenDay = (i + 8) % 7
        }
    }
    console.log(chosenDay)

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
    let table = document.createElement('div')
    table.className = "table"
    


    let res = [] // массив для дат
    
    num = (Number(endDate) - Number(startDate)) / (24 * 3600 * 1000)
    let cur = startDate
    for (let i = 0; i <= num; i++)
    {
        if (cur.getDay() == chosenDay)
        {
            res.push(formatDate(cur))
        }
        cur.setDate(cur.getDate() + 1)
    }

    let name = getChosen(document.getElementById("subject").options).innerText
    let n = Number(document.getElementById("students").value)
    let group = document.getElementById("group").value

    let block = document.createElement('div')
    block.className = "text"
    block.innerHTML = `Дисциплина: <b>${name}</b>`
    div.append(block)
    block = document.createElement('div')
    block.className = "text"
    block.innerHTML = `<i>Группа: <b>${group}</b></i>`
    div.append(block)
    div.append(table)

    putCol("№", table, n, true)
    putCol("ФИО", table, n, false)
    for (let i in res)
    {
        putCol(res[i], table, n, false)
    }
    putCol("Отметка", table, n, false)
}