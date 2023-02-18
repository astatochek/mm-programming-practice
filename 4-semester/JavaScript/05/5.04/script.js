
let subject_flags = [
    [false, [false, false, false], [false, false], [false, false]],
    [false, [false, false, false], [false, false], [false, false]],
    [false, [false, false, false], [false, false], [false, false]],
    [false, [false, false, false], [false, false], [false, false]],
    [false, [false, false, false], [false, false], [false, false]]
]

let base_costs = [100, 200, 130, 120, 200]

let results = [0, 0, 0, 0, 0]

function calc_sum()
{
    let sum = 0
    for (let i = 0; i < 5; i++)
    {
        sum += results[i]
    }
    document.getElementById(`sum`).textContent = `${sum}$`
    console.log(`sum: ${sum}`)
}


function process(item, index, subindex)
{
    console.log(`entered with ${item} ${index} ${subindex}`)

    if (index == 0){
        subject_flags[item][index] = !subject_flags[item][index]
    }
    if (index == 1){
        for (let i = 0; i < 3; i++){
            if (subindex == i){
                subject_flags[item][index][i] = true
            }
            else{
                subject_flags[item][index][i] = false
            }
        }
    }
    if (index == 2){
        subject_flags[item][index][subindex] = !subject_flags[item][index][subindex]
    }
    if (index == 3)
    {
        let first = subindex
        let second = -1
        if (first == 0){
            second = 1
        }
        else{
            second = 0
        }
        subject_flags[item][index][first] = true
        subject_flags[item][index][second] = false
    }
    
    console.log(subject_flags[item])

    let val = 1

    if (subject_flags[item][0]){
        val = base_costs[item]
    }
    else{
        document.getElementById(`out${item}`).textContent = ""
        results[item] = 0
        calc_sum()
        return 
    }

    if (subject_flags[item][1][0]){
        val *= 3
    }
    else if (subject_flags[item][1][1]){
        val *= 6
    }
    else if (subject_flags[item][1][2]){
        val *= 9
    }
    else{
        document.getElementById(`out${item}`).textContent = "0$"
        results[item] = 0
        calc_sum()
        return
    }

    if (subject_flags[item][2][0]){
        val += 50
    }
    if (subject_flags[item][2][1]){
        val += 50
    }

    if (subject_flags[item][3][0]){
        val *= 4
    }
    else if (subject_flags[item][3][1]){
        val *= 2
    }
    else{
        document.getElementById(`out${item}`).textContent = "0$"
        results[item] = 0
        calc_sum()
        return
    }

    results[item] = val

    document.getElementById(`out${item}`).textContent = `${val}$`
    
    calc_sum()
}

