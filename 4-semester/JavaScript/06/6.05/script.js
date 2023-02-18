

let output = []


function process()
{
    let options = document.getElementById("form").elements[0]
    console.log(options)
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            output.push(options[i].textContent)
        }
    }
    out = document.getElementById("output")
    out.innerText = ""
    for (let i = 0; i < output.length; i++)
    {
        out.innerText += `${i+1}. ${output[i]}\n`
    }
}