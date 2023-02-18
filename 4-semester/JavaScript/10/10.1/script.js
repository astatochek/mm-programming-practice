
function show()
{
    let form = document.getElementById("form")
    let out = document.getElementById("output")
    out.innerText = ""
    for (let i in form)
    {
        out.innerText += `${form.button.type}.${i} = ${(form.button)[i]}\n`
    }
}