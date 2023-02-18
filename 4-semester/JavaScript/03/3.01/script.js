
function processAction(obj)
{
    let width = obj.w.value
    let thickness = obj.t.value
    let pic = document.getElementById("pict")


    if (width != "")
    {
        pic.width = width
    }
    if (thickness != "")
    {
        pic.border = thickness
    }
}