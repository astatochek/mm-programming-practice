let top_top = 50
let top_left = 480
let bot_top = 70
let bot_left = 500
let top_left_most = 170
let current_top_left = 480
let current_bot_left = 500
let current_top_top = 50
let current_bot_top = 70
let flag = true
let is_working = false


function move_left()
{
    let top = document.getElementById("mount")
    if (top.style.zIndex == "-1")
    {
        top = document.getElementById("forest")
    }
    if (current_top_left > top_left_most)
    {
        current_top_left -= 4
        top.style.left = `${current_top_left}px`
        setTimeout('move_left()', 1)
        return
    }
    move_right()
}

function move_a_little()
{
    let top = document.getElementById("mount")
    let bot = document.getElementById("forest")
    if (top.style.zIndex == "-1")
    {
        top = document.getElementById("forest")
        bot = document.getElementById("mount")
    }
    if (current_bot_top > top_top)
    {
        current_bot_top -= 1
        current_bot_left -= 1
        current_top_top += 1
        bot.style.top = `${current_bot_top}px`
        bot.style.left = `${current_bot_left}px`
        top.style.top = `${current_top_top}px`
        setTimeout('move_a_little()', 10)
    }
}

function move_right()
{
    let top = document.getElementById("mount")
    let bot = document.getElementById("forest")
    if (!flag)
    {
        top = document.getElementById("forest")
        bot = document.getElementById("mount")
    }
    top.style.zIndex = '1'
    bot.style.zIndex = '-1'
    
    if (current_top_left < bot_left)
    {
        current_top_left += 4
        bot.style.left = `${current_top_left}px`
        setTimeout('move_right()', 1)
        return
    }
    is_working = false
}

function swap()
{
    if (is_working) return
    is_working = true
    current_top_left = 480
    current_bot_left = 500
    current_top_top = 50
    current_bot_top = 70
    flag = !flag
    move_left()
    move_a_little()
}