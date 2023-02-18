<?php
session_start();
header('Content-Type: text/html; charset=utf-8');
if (!($_SESSION["user_status"])) {
	$_SESSION["user_status"] = "guest";
}
?>

<html>

<head>
	<link href="style.css" rel="stylesheet">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 5</title>
</head>

<body>
	<?php
	include "connect.php";
	include "functions.php";



	if (isset($_POST["log_out"])) {
		$_SESSION["user_status"] = "guest";
	}

	if ($_SESSION["user_status"] == "guest") {

		if (isset($_POST["log_reg"])) {
			add($pdo, $_POST["log_reg"], $_POST["pass_reg"]);
			$_SESSION["user_status"] = "user";
			$_SESSION["username"] = $_POST["log_reg"];
			if ($_SESSION["username"] == "admin") {
				$_SESSION["user_status"] = "admin";
			}
			include "message.php";
		} else {
			include "homepage.html";
		}
		if (isset($_POST["log_in"])) {
			$check = login($pdo, $_POST["log_in"], $_POST["pass_in"]);
			if ($check) {
				$_SESSION["user_status"] = "user";
				$_SESSION["username"] = $_POST["log_in"];
				if ($_SESSION["username"] == "admin") {
					$_SESSION["user_status"] = "admin";
				}
				include "message.php";
	?><?php
			}
		}
	} else {
		include "message.php";
		if (isset($_POST["note"])) {
			write($pdo, $_SESSION["username"], $_POST["note"]);
		}
	}
	if ($_SESSION["user_status"] != "guest") {
		?><form action="" method="POST"><input type="submit" name="log_out" value="Log Out"></form><br><?php
		}
		if (array_search("delete", $_POST)) {
		remove($pdo, array_search("delete", $_POST));
		}


		if ($_SESSION["user_status"] == "admin") {
		read_admin($pdo);
		} else {
		read($pdo);
		}
		?>

</body>

</html>