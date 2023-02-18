let par = {
    year: 'numeric',
    month: 'long',
    day: 'numeric',
  }


function getChosen(options)
{
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            return options[i]
        }
    }
}


function putBlocks(text, output)
{
    let div = document.createElement('div')
    div.className = "cell";
    div.innerText = text
    output.append(div)
}


function getList()
{
    let blocks = document.getElementsByClassName("cell")
    while (blocks.length != 0)
    {
        blocks[0].remove()
    }

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

    out = document.getElementById("output")
    let res = []

    let name = getChosen(document.getElementById("subject").options).innerText
    document.getElementById("name").textContent = `Расписание по предмету ${name}`
    
    num = (Number(endDate) - Number(startDate)) / (24 * 3600 * 1000)
    let cur = startDate
    for (let i = 0; i <= num; i++)
    {
        if (cur.getDay() == chosenDay)
        {
            res.push(`${cur.toLocaleString("ru", par)}`)
        }
        cur.setDate(cur.getDate() + 1)
    }

    for (let i in res)
    {
        putBlocks(res[i], out)
    }
}