<?php
header('Content-Type: text/html; charset=utf-8');?>
<html>
<head>
    <link href="style.css" rel="stylesheet">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo($_POST['title']); ?> </title>
</head>
<body style="background-color: <?php echo($_POST['bc']) ?>;">
    <font color="<?php echo($_POST['fc']) ?>" size=18>
    <p><?php echo($_POST['content']) ?></p>
</font>
</body>
</html>