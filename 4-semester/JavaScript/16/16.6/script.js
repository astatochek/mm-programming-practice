let out = document.getElementById("output")


function towers_of_hanoi(n, start, end, aux)
{
    if (n > 0)
    {
        towers_of_hanoi(n - 1, start, aux, end)
        out.innerText += `Переложить диск с ${start} на ${end}\n`
        towers_of_hanoi(n - 1, aux, end, start)
    }
}

function show()
{
    let num = Number(document.getElementById("num").value)
    out.innerText = ""
    towers_of_hanoi(num, 'A', 'C', 'B')
}