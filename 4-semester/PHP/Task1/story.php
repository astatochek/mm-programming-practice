<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <link rel="stylesheet" type="text/css" href="style.css" >
  <title>Task 1</title>
 </head>
 <body>
 	<?php
	 	echo "<div id='output'>";
	 	echo "Мне больно видеть " . $_POST["field_1"] . ",";
		echo "<br>";
		echo "Мне лучше в " . $_POST["field_2"] . ",";
		echo "<br>";
		echo "Я " . $_POST["field_3"] . " лет";
		echo "<br>";
		echo "Мечтаю только о " . $_POST["field_4"] . ".";
		echo "<br>";
		echo "Мне слишком тесно в " . $_POST["field_5"] . ",";
		echo "<br>";
		echo "И я мечтаю об одном:";
		echo "<br>";
		echo "Скорей свободу обрести,";
		echo "<br>";
		echo "Прогрызть свой " . $_POST["field_6"] . ".";
	 	echo "</div>";
	?>
 </body>
</html>
