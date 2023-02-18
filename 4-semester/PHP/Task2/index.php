<html>
<head>
    <link href="style.css" rel="stylesheet">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 2</title>
</head>
<body>
    <div class="wrapper">
        <p>Web-Page Generator</p>
        <form method="POST" action="custom.php">
            <p>Title</p>
            <input type="text" name="title" size=20 required>
            <p>Page Text</p>
            <textarea name="content" cols=30 rows=3 required ></textarea>
            <p>Background Color: <select name="bc">
                <option>#d74374</option>
                <option>#d7a3c8</option>
                <option>#d7a386</option>
                <option>#d76244</option>
                <option>#d7b2c1</option>
            </select></p>
            <p>Font Color:  <select name="fc">
                <option>#000044</option>
                <option>#002e3a</option>
                <option>#3d2e3a</option>
                <option>#1e265b</option>
            </select></p>
            <input type="submit" value="Create">
        </form>
    </div>
</body>
</html>