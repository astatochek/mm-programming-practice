let blocks = document.getElementsByClassName('block');
let i = 0;
function next()
{
    blocks[i].style.visibility = 'hidden';
    i = (i + 1) % (blocks.length)
    blocks[i].style.visibility = 'visible';
}