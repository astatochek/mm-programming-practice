<html>

<head>
    <link href="style.css" rel="stylesheet">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 4</title>
</head>

<body>
    <div class='wrapper_1'>
        <h1>Word Search</h1>
        <form action="puzzle.php" method="POST">
            <p>Height:</p><input type="text" name="height" required autocomplete='off'>
            <p>Width:</p><input type="text" name="width" required autocomplete='off'>
            <p>Word List</p>
            <textarea rows=10 cols=20 name="wordList" required autocomplete='off'></textarea>
            <p>(type in words with one per line)</p>
            <input type="submit" value="Generate Puzzle">
        </form>
    </div>
</body>

</html>