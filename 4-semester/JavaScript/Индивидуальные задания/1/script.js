let out = document.getElementById("output")


function toDisjunctive(f)
{
    let tmp = f.split(')').join('').split('(')
    let res = []
    for (let i in tmp) if (tmp[i] != '') res.push(tmp[i])
    return res
}


function getElements(s)
{
    let tmp = s.split('+').join(' ').split(' ')
    let res = []
    for (let i in tmp) if (tmp[i] != '') res.push(tmp[i])
    return res
}

function newUnit(let, val, unit) // переменная, bool значение, скобка
{
    let res = []
    for (let i in unit)
    {
        if (val && unit[i].length == 2 && unit[i][1] == let)
            continue
        if (val && unit[i] == let)
            return true
        if (!val && unit[i].length == 2 && unit[i][1] == let)
            return true
        if (!val && unit[i] == let)
            continue
        res.push(unit[i])
    }
    if (res.length == 0) return false
    return res
}


function insertVal(let, val, disj)
{
    console.log(`let ${let} = ${val}`)
    let res = []
    for (let i in disj)
    {
        let tmp = newUnit(let, val, disj[i])
        if (tmp == true)
            continue
        if (tmp == false)
            return false
        res.push(tmp)
    }
    if (res.length == 0) return true
    return res
}

function getLetter(disj)
{
    for (let i in disj)
    {
        let unit = disj[i]
        for (let j in unit)
        {
            if (unit[j].length == 2) return unit[j][1]
            else return unit[j]
        }
    }
}


function DPLL(disj, dict)
{
    let letter = getLetter(disj)
    let arr = [true, false]
    for (let i in arr)
    {
        let val = arr[i]
        let res = insertVal(letter, val, disj)

        let newDict = new Map()
        for (var [key, value] of dict) newDict.set(key, value)
        newDict.set(letter, val)

        if (res == true)
            return newDict
        if (res == false)
            continue
        return DPLL(res, newDict)
    }
    return false
}


function show()
{
    let formula = document.getElementById("func").value
    out.innerText = `${formula}\n`

    let disjunctive = toDisjunctive(formula)
    
    for (let i in disjunctive) disjunctive[i] = getElements(disjunctive[i])

    let res = DPLL(disjunctive, new Map())
    if (res == false) out.innerText += `НЕРАЗРЕШИМО`
    else
    {
        out.innerText += `РАЗРЕШИМО ПРИ\n`
        for (var [key, value] of res) out.innerText += `${key} => ${value}\n`
    }
}