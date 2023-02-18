При нажатии на область картинки (одной из пяти) вызывается функция ```processActiond(val)``` от индекса этой картинки. Сама функция запоминает эти индексы, и при повторном вызове меняет местами выбранные картинки через изменение параметра ```src``` в блоке ```img```.


Для того, чтобы поменять картинки местами, используется третья переменная
```js
let tmp = document.getElementById(val1).src
document.getElementById(val1).src = document.getElementById(val2).src
document.getElementById(val2).src = tmp
```