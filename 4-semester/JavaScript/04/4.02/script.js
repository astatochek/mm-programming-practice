

function processAction(code)
{
    let obj = document.getElementById(`dot ${code}`)
    document.getElementById("output 1").textContent = `Value: ${obj.value}`
    document.getElementById("output 2").textContent = `Name: ${obj.name}`
    document.getElementById("output 3").textContent = `Type: ${obj.type}`
}