
function process()
{
    let options = document.getElementById("form").elements[0]
    console.log(options)
    out = document.getElementById("output")
    if (options[0].selected)
    {
        out.textContent = `Social Credit: ${10000}`
    }
    else
    {
        out.textContent = `Social Credit: ${0}`
    }
}