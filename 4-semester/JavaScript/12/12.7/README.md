Сначала строка с пробелами схлопывается в строку без пробелов, затем проверятся в цикле ```for``` симметричность:
```js
for (let i = 0; i < str.length / 2 + 1; i++)
    {
        if (str[i] != str[str.length - 1 - i])
        {
            return false
        }
    }
return true
```