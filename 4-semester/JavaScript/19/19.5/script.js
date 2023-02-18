function putCol(ind, num, output) // создает колонки итоговой таблицы и заполняет ячейками
{
    let div = document.createElement('div')
    div.className = "col";
    let cur = ind
    let cell
    for (let i = 1; i <= num; i++)
    {
        cell = document.createElement('div')
        cur = (cur + num - 1) % num
        cell.className = "cell"
        cell.innerText = cur + 1
        div.append(cell)
    }
    output.append(div)
}


function show() // обработка входных данных и все остальное
{
    let toRemove = document.getElementsByClassName("output") // освобождаем блоки вывода
    while (toRemove.length != 0)
        toRemove[0].remove()

    out = document.getElementById("outputWrapper")
    let div = document.createElement('div') // создаем пустой блок для вывода
    div.className = "output";
    div.id = "out"
    out.append(div)
    let table = document.createElement('div')
    table.className = "table"
    div.append(table)

    let n = Number(document.getElementById("n").value)

    for (let i = 1; i <= n; i++)
    {
        putCol(i, n, table)
    }
}