

function determine(obj)
{
    let val = obj.inpt.value

    let out = "Нет такого";

    switch(val)
    {
        case "понедельник": out = `день номер ${1}`; break;
        case "вторник": out = `день номер ${2}`; break;
        case "среда": out = `день номер ${3}`; break;
        case "четверг": out = `день номер ${4}`; break;
        case "пятница": out = `день номер ${5}`; break;
        case "суббота": out = `день номер ${6}`; break;
        case "воскресение": out = `день номер ${7}`; break;
    }

    obj.res.value = out
}