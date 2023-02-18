function process(val, index)
{
    let options = document.getElementById("form").elements[0]
    console.log(options)
    out = document.getElementById("output")
    for (let i = 0; i < options.length; i++)
    {
        if (options[i].selected)
        {
            out.textContent = `Вы выбрали ${options[i].textContent}`
        }
    }
}