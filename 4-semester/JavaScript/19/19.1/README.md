Аналогично ```11.7```. Теперь вывод работает иначе: создаются блоки ```div``` одного класса и присоединяются к блоку для вывода. Также, при нажатии на кнопку "Сформировать" они сначала удаляются.


Добавление блока:
```js
function putBlocks(text, output)
{
    let div = document.createElement('div')
    div.className = "cell";
    div.innerText = text
    output.append(div)
}
```


Удаление блоков:
```js
let blocks = document.getElementsByClassName("cell")
while (blocks.length != 0)
{
    blocks[0].remove()
}
```

Обработка ошибок (как и в ```11.7```) отсутствует