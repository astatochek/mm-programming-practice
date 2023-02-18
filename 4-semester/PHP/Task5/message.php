<html>

<head>
    <link href="style.css" rel="stylesheet">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 5</title>
</head>

<body>
    <div class="wrapper" style="height: 200px;">
    <form action="" method="POST">
        <p>Logged in as: <?php print $_SESSION["username"]?></p>
        <p>Access level: <?php print $_SESSION["user_status"]?></p>
        <p><input type="text" name="note" required size="40"></p>
        <p><input type="submit" value="Send" name="2"></p>
    </form>
</div>
</body>

</html>