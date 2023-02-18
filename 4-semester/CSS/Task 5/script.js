let block = document.getElementById('block');
let startTop = -80;
let startLeft = 300;
let currentTop = startTop;
let currentLeft = startLeft;
let step = 40;
function toTop()
{
    currentTop -= step; 
    block.style.top = `${currentTop}px`; 
}
function toBottom()
{
    currentTop += step;
    block.style.top = `${currentTop}px`;
}
function toLeft()
{
    currentLeft -= step;
    block.style.left = `${currentLeft}px`;
}
function toRight()
{
    currentLeft += step;
    block.style.left = `${currentLeft}px`;
}
function showText(){ document.getElementById('text').style.visibility = 'visible'; }
function hiddenText(){ document.getElementById('text').style.visibility = 'hidden'; }