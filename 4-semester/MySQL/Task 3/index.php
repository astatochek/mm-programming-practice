<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 3</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>

	<h3>
		Запрос 1: SELECT country.Name, countrylanguage.Language FROM `country`, `countrylanguage` WHERE countrylanguage.IsOfficial = 'T' AND countrylanguage.CountryCode = country.Code ORDER BY country.Population DESC LIMIT 15 
	</h3>
<?php
$server = 'localhost';
$user = 'root';
$pass = 'root';
$conn = new PDO('mysql:host=localhost;dbname=world', $user, $pass);

$firstQuery = "SELECT country.Name, countrylanguage.Language FROM `country`, `countrylanguage` WHERE countrylanguage.IsOfficial = 'T' AND countrylanguage.CountryCode = country.Code ORDER BY country.Population DESC LIMIT 15;";
$result1 = $conn->query($firstQuery);

$table = "<table  border=1 width = '600px' align=center>";
$table .= "<tr>";
$table .= "<th >" . "Name" . "</th>";
$table .= "<th >" . "Official Language" . "</td>";
$table .= "</tr>";

foreach ($conn->query($firstQuery) as $row)
{
	$table .= "<tr >";
	$table .= "<td >" . $row['Name'] . "</td>";
	$table .= "<td >" . $row['Language'] . "</td>";
	$table .= "</tr>";
}
$table .= "</table>";
echo $table;


$sql2 = "SELECT Name, Continent, LocalName FROM country ORDER BY Population DESC LIMIT 15;"
?>

<h3>
	Запрос 2: SELECT Name, Continent, LocalName FROM country ORDER BY Population DESC LIMIT 15;.
</h3>
<?php
$table = "<table  border=1 width = '600px' align=center>";
$table .= "<tr>";
$table .= "<th >" . "Name" . "</th>";
$table .= "<th >" . "Continent" . "</td>";
$table .= "<th >" . "Local Name" . "</td>";
$table .= "</tr>";

foreach ($conn->query($sql2) as $row) {
	$table .= "<tr >";
	$table .= "<td >" . $row['Name'] . "</td>";
	$table .= "<td >" . $row['Continent'] . "</td>";
	$table .= "<td >" . $row['LocalName'] . "</td>";
	$table .= "</tr>";
}

$table .= "</table>";
echo $table; ?>


</body>
</html>