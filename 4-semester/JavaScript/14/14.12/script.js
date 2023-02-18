let out = document.getElementById("output")


function binSearch(i, j, nums, target)
{
    let ind = Math.floor((i + j) / 2)
    if (nums[ind] == target)
    {
        return ind
    }
    if (i > j)
    {
        return -1
    }
    if (nums[ind] < target)
    {
        return binSearch(ind + 1, j, nums, target)
    }
    return binSearch(i, ind - 1, nums, target)
}


function show()
{
    let arr = document.getElementById("arr").value
    arr = arr.split(' ').map(Number)
    console.log(arr)
    let num = Number(document.getElementById("num").value)
    out.innerText = ""
    let i = binSearch(0, arr.length - 1, arr, num)
    if (i != -1)
    {
        arr.splice(i, 1)
    }
    for (let j in arr)
    {
        out.innerText += ` ${arr[j]}`
    }
}