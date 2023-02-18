let par = {
    year: 'numeric',
    month: 'long',
    day: 'numeric',
  }

function getList()
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

    out = document.getElementById("output")
    out.innerText = ``

    num = (Number(endDate) - Number(startDate)) / (24 * 3600 * 1000)
    let cur = startDate
    for (let i = 0; i < num; i++)
    {
        cur.setDate(cur.getDate() + 1)
        if (cur.getDay() == chosenDay)
        {
            out.innerText += `${cur.toLocaleString("ru", par)}\n`
        }
    }
}