<html>
<head>
	<link rel="stylesheet" href="style.css">
</head>
<body>
	<div class="wrapper">

	<form action="" method="post">
		<div class="field">
			<div class="text"><h3>Выберите отображаемые элементы таблицы country базы данных world:</h3></div>
			<div class="list">
				<div class="row">
					<input type="checkbox" id="Code" name="columns[]" value='Code'>
					<label for="Code">Code</label>
				</div>

				<div class="row">
					<input type="checkbox" id="Name" name="columns[]" value='Name'>
					<label for="Name">Name</label>
				</div>

				<div class="row">
					<input type="checkbox" id="Continent" name="columns[]" value='Continent'>
					<label for="Continent">Continent</label>
				</div>

				<div class="row">
					<input type="checkbox" id="Region" name="columns[]" value='Region'>
					<label for="Region">Region</label>
				</div>

				<div class="row">
					<input type="checkbox" id="SurfaceArea" name="columns[]" value='SurfaceArea'>
					<label for="SurfaceArea">Surface Area</label>
				</div>

				<div class="row">
					<input type="checkbox" id="Population" name="columns[]" value='Population'>
					<label for="Population">Population</label>
				</div>

				<div class="row">
					<input type="checkbox" id="LifeExpectancy" name="columns[]" value='LifeExpectancy'>
					<label for="LifeExpectancy">Life Expectancy</label>
				</div>

				<div class="row">
					<input type="checkbox" id="GNP" name="columns[]" value='GNP'>
					<label for="GNP">GNP</label>
				</div>

				<div class="row">
					<input type="checkbox" id="LocalName" name="columns[]" value="LocalName">
					<label for="LocalName">Local Name</label>
				</div>

				<div class="row">
					<input type="checkbox" id="GovernmentForm" name="columns[]" value='GovernmentForm'>
					<label for="GovernmentForm">Government Form</label>
				</div>

				<div class="row">
					<input type="checkbox" id="Capital" name="columns[]" value="Capital">
					<label for="Capital">Capital</label>
				</div>
			</div>
		</div>
		
		<div class="field">
			<div class="text" align='center'>
				Количество записей:
			</div>
			<input name="num" required type=text autocomplete="off">
		</div> 
		<input type="submit" value="Вывести">
	</form>

	<?php
	$columns = $_POST['columns'];
	if (empty($columns))
	{
		echo('Вы не выбрали ни одного столбца таблицы!');
	}
	else
	{

		if (isset($_POST['num']))
		{
			$sql = 'Select ' . implode(", ", $columns).' from country'. ' limit ' . $_POST['num'];
			$server = 'localhost';
			$user = 'root';
			$pass = 'root';
			$conn = new PDO('mysql:host=localhost;dbname=world', $user, $pass);

			$table = "<table  border=1 width = '600px' align=center>";
			$table .= "<tr>";
			foreach ($columns as $header)
			{
				$table .= "<th >" . $header . "</th>";
			}
			$table .= "</tr>";
			
			foreach ($conn->query($sql) as $row)
			{
				$table .= "<tr>";
				foreach ($columns as $header)
				{
					$table .= "<td>" . $row[$header] . "</td>";
				}
				$table .= "</tr>";
			}
			$table .= "</table>";
			echo $table;
		}	

	}
	
	?>

	</body>
 
</html>