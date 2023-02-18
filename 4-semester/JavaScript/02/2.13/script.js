

function determine(obj)
{
    let val = Number(obj.inpt.value)

    let out = "Нет такого";

    switch(val)
    {
        case 1: out = "Понедельник"; break;
        case 2: out = "Вторник"; break;
        case 3: out = "Среда"; break;
        case 4: out = "Четверг"; break;
        case 5: out = "Пятница"; break;
        case 6: out = "Суббота"; break;
        case 7: out = "Воскресение"; break;
    }

    obj.res.value = out
}