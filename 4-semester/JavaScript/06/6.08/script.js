
let output = [['Матвеев Сергей', 0]]

function changeMark()
{
    let averageMark = 0
    let allFields = document.getElementsByName("field")
    for (let i = 0; i < allFields.length; i++)
    {
        if (allFields[i].checked)
        {
            averageMark += Number(allFields[i].value)
        }
    }
    console.log(output)
    let last = output.pop()
    output.push([last[0], averageMark / 4])
    console.log(output)
    out = document.getElementById("output")
    out.textContent = ""
    for (let i = 0; i < output.length; i++)
    {
        out.innerText += `${i+1}. ${output[i][0]}: ${output[i][1]}\n`
    }
}


function changeStudent()
{
    let options = document.getElementById("form").elements[0]
    let studentName = ""
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            studentName = options[i].textContent
        }
    }
    let averageMark = 0
    let allFields = document.getElementsByName("field")
    console.log(allFields)
    for (let i = 0; i < allFields.length; i++)
    {
        console.log(allFields[i].value)
        if (allFields[i].checked)
        {
            averageMark += Number(allFields[i].value)
            
        }
    }
    output.push([studentName, averageMark / 4])
    out = document.getElementById("output")
    out.textContent = ""
    for (let i = 0; i < output.length; i++)
    {
        out.innerText += `${i+1}. ${output[i][0]}: ${output[i][1]}\n`
    }
}