<?php if(!session_id()){
session_start();}
header('Content-Type: text/html; charset=utf-8');
if (!isset($_SESSION["balance"])){
	$_SESSION["balance"]=0;
}
if (!isset($_SESSION["ans"])){
	$_SESSION["ans"]=rand(0,1);
}
$balance = 0;
$ans=$_SESSION["ans"];
function check($expected, $actual){
    global $balance, $ans;
    if ($expected == $actual){
        $_SESSION['balance']+=100;
        echo 'Верно: Вы ввели ';
        echo $actual;
        echo ' при загаданном ';
        echo $expected;
        echo ', Ваш баланс: ';
        echo $_SESSION['balance'];
        $_SESSION["ans"]=rand(0,1);
    }
    else {
        $_SESSION['balance']-=100;
        echo 'Не верно: Вы ввели ';
        echo $actual;
        echo ' при загаданном ';
        echo $expected;
        echo ', Ваш баланс: ';
        echo $_SESSION['balance'];
        $_SESSION["ans"]=rand(0,1);
    }
}

?>
<html>
<head>
    <link href="style.css" rel="stylesheet">
    <title>Task 3</title>
</head>
<body>
    <div class="wrapper">
    Сервер Загадывает 0 или 1
    <form action="index.php" method="POST">
    Введите число: <select name="num" >
        <option value="1">1</option>
        <option value="0">0</option>
    </select>
    <input type="submit" value="Проверить">
    </form>
    <?php 
    if (isset($_POST["num"])){
        check($_SESSION["ans"],$_POST["num"]);
    }
    ?>
</body>
</html>