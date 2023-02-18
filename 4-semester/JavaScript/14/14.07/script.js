let out = document.getElementById("output")


function getNums(str)
{
    let cur = ""
    let res = []
    for (let i = 0; i < str.length; i++)
    {
        if (str[i] == " ")
        {
            res.push(Number(cur))
            cur = ""
        }
        else
        {
            cur += str[i]
        }
    }
    if (cur != "")
    {
        res.push(Number(cur))
    }
    return res
}


function binSearch(i, j, nums, target)
{
    let ind = Math.floor((i + j) / 2)
    out.innerText += `i: ${i} j: ${j}`
    if (nums[ind] == target)
    {
        out.innerText += ` a[${ind}] = ${target} → ${ind}`
        return ind
    }
    if (i > j)
    {
        out.innerText += `${i} > ${j} → -1`
        return -1
    }
    if (nums[ind] < target)
    {
        out.innerText += ` a[${ind}] < ${target} →\n`
        return binSearch(ind + 1, j, nums, target)
    }
    out.innerText += ` a[${ind}] >= ${target} →\n`
    return binSearch(i, ind - 1, nums, target)
}


function show()
{
    let def = document.getElementById("arr").value
    let num = Number(document.getElementById("num").value)
    out.innerText = ""
    let arr = getNums(def)
    console.log(arr)
    binSearch(0, arr.length - 1, arr, num)
}