let out = document.getElementById("output")
let iter = 100 // количество попыток теста Ферма


function getRandom(floor, ceiling)
{
    return floor + Math.floor(Math.random() * (ceiling - floor)) + 1
}


function modPower(a, n)
{
    let res = 1
    for (let i = 0; i < n - 1; i++)
    {
        res = (res * a) % n
    }
    return res
}


function isPrime(n)
{
    for (let i = 0; i < iter; i++)
    {
        let a = getRandom(n, 2 * n)
        while (a % n == 0) a = getRandom(n, 2 * n)
        if (modPower(a, n) != 1)
            return false
    }
    return true
}


function show()
{
    let num = Number(document.getElementById("num").value)

    if ( Math.floor(num) != num || num % 2 != 0 || num <= 2)
    {
        out.innerText = `Неправильный ввод`
        document.getElementById("num").value = ''
        return
    }
    let a = Math.floor(num / 2)
    let b = Math.floor(num / 2)
    if (a + b < num) b++
    while (b > Math.floor(num / 2) - 1)
    {
        if (isPrime(a) && isPrime(b))
        {
            out.innerText = `${a} + ${b} = ${num}\n`
            out.innerText += `где ${a} и ${b} - простые`
            return
        }
        a--
        b++
    }
}