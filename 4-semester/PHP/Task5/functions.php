<?php

function add($pdo, $name, $pass)
{
	$sql = "INSERT INTO users(name,password) VALUES (:name,:password)";

	$stmt = $pdo->prepare($sql);
	$stmt->bindParam(':name', $name);
	$stmt->bindParam(':password', md5($pass));
	$result = $stmt->execute();
	$stmt->close();
}

function login($pdo, $name, $pass)
{
	$sql = sprintf("SELECT * FROM users WHERE name='%s'", $name);
	$result = $pdo->querySingle($sql, true);
	if ($result) {
		if (md5($pass) == $result["password"]) {
			return true;
		}
		return false;
	}
	return false;
}


function write($pdo, $name, $text)
{
	$sql = "INSERT INTO notes(name,text) VALUES (:name,:text)";
	$stmt = $pdo->prepare($sql);
	$stmt->bindParam(':name', $name);
	$stmt->bindParam(':text', $text);
	$result = $stmt->execute();
	$stmt->close();
}

function read_admin($pdo)
{
	$sql = "SELECT * FROM notes";
	$results = $pdo->query($sql);
	while ($row = $results->fetchArray()) {
?>
		<?php
		print_r($row["name"] . " : " . $row["text"]); ?> <form method="POST" action="index.php"><input type="submit" name="<?php echo $row["id"] ?>" value="delete"></form><br>
	<?php
	}
}

function remove($pdo, $val)
{
	$sql = "DELETE FROM notes WHERE ID=:id";
	$stmt = $pdo->prepare($sql);
	$stmt = $pdo->prepare($sql);
	$stmt->bindParam(':id', $val);
	$result = $stmt->execute();
	$stmt->close();
}

function logout()
{
	unset($_SESSION["user_status"]);
}

function read($pdo)
{
	$sql = "SELECT * FROM notes";
	$results = $pdo->query($sql);
	while ($row = $results->fetchArray()) {
	?>
		<?php
		print_r($row["name"] . " : " . $row["text"]); ?><br>
<?php
	}
}


?>