let out = document.getElementById("output")

let symbol = ['+', '-', '*', '%']

function getExpression(nums, s, index, ans)
{
    if (index == nums.length - 1)
    {
        let expr = ``, output = ``
        for (let i = 0; i < nums.length - 1; i++)
        {
            expr += ` nums[${i}] ${s[i]}`
            output += ` ${nums[i]} ${s[i]}`
        }
        expr += ` nums[${index}] == ans`
        output += ` ${nums[index]} = ${ans}`
        console.log(output)

        if (eval(expr))
        {
            out.innerText += `${output}\n`
        }
    }
    else
    {
        for (let j in symbol)
        {
            getExpression(nums, s + symbol[j], index + 1, ans)
        }
    }

}

function show()
{
    let a = document.getElementById("a").value
    a = a.split(' ').map(Number)
    let b = Number(document.getElementById("b").value)
    out.innerText = ``
    getExpression(a, ``, 0, b)
}