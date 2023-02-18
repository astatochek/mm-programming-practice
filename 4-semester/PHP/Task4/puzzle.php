<?php

function getInput()
{
    global $word, $wordList, $boardData;
    $SUCCESS = TRUE;
    $wordList = strtoupper($wordList);
    $word = explode("\n", $wordList);
    foreach ($word as $currentWord) {
        $currentWord = rtrim($currentWord);
        if ((strLen($currentWord) > $boardData["width"]) &&
            (strLen($currentWord) > $boardData["height"])
        ) {
            print $currentWord . " is too long for puzzle; ";
            $SUCCESS = FALSE;
        }
    }
    return $SUCCESS;
}

function putDots()
{
    global $board, $boardData;
    for ($row = 0; $row < $boardData["height"]; $row++) {
        for ($col = 0; $col < $boardData["width"]; $col++) {
            $board[$row][$col] = ".";
        }
    }
}


function fillWithLetters()
{
    global $word;
    $direction = array("N", "S", "E", "W");
    $SUCCESS = TRUE;
    $counter = 0;
    $keepGoing = TRUE;
    while ($keepGoing) {
        $dir = rand(0, 3);
        $result = addWord($word[$counter], $direction[$dir]);
        if ($result == FALSE) {
            $keepGoing = FALSE;
            $SUCCESS = FALSE;
        }
        $counter++;
        if ($counter >= count($word)) {
            $keepGoing = FALSE;
        }
    }
    return $SUCCESS;
}



function addWord($theWord, $dir)
{
    global $board, $boardData;
    $theWord = rtrim($theWord);
    $SUCCESS = TRUE;
    switch ($dir) {
        case "E":
            $newCol = rand(0, $boardData["width"] - 1 - strlen($theWord));
            $newRow = rand(0, $boardData["height"] - 1);
            for ($i = 0; $i < strlen($theWord); $i++) {
                $boardLetter = $board[$newRow][$newCol + $i];
                $wordLetter = substr($theWord, $i, 1);
                if (($boardLetter == $wordLetter) ||
                    ($boardLetter == ".")
                ) {
                    $board[$newRow][$newCol + $i] = $wordLetter;
                } else {
                    $SUCCESS = FALSE;
                }
            }
            break;
        case "W":
            $newCol = rand(strlen($theWord), $boardData["width"] - 1);
            $newRow = rand(0, $boardData["height"] - 1);
            for ($i = 0; $i < strlen($theWord); $i++) {
                $boardLetter = $board[$newRow][$newCol - $i];
                $wordLetter = substr($theWord, $i, 1);
                if (($boardLetter == $wordLetter) ||
                    ($boardLetter == ".")
                ) {
                    $board[$newRow][$newCol - $i] = $wordLetter;
                } else {
                    $SUCCESS = FALSE;
                }
            }
            break;
        case "S":
            $newCol = rand(0, $boardData["width"] - 1);
            $newRow = rand(0, $boardData["height"] - 1 - strlen($theWord));
            for ($i = 0; $i < strlen($theWord); $i++) {
                $thisRow = $newRow + $i;
                $boardLetter = $board[$thisRow][$newCol];
                $wordLetter = substr($theWord, $i, 1);
                if (($boardLetter == $wordLetter) ||
                    ($boardLetter == ".")
                ) {
                    $thisRow = $newRow + $i;
                    $board[$thisRow][$newCol] = $wordLetter;
                } else {
                    $SUCCESS = FALSE;
                }
            }
            break;
        case "N":
            $newCol = rand(0, $boardData["width"] - 1);
            $newRow = rand(strlen($theWord), $boardData["height"] - 1);
            for ($i = 0; $i < strlen($theWord); $i++) {
                $thisRow = $newRow - $i;
                $boardLetter = $board[$thisRow][$newCol];
                $wordLetter = substr($theWord, $i, 1);
                if (($boardLetter == $wordLetter) ||
                    ($boardLetter == ".")
                ) {
                    $thisRow = $newRow - $i;
                    $board[$thisRow][$newCol] = $wordLetter;
                } else {
                    $SUCCESS = FALSE;
                }
            }
            break;
    }
    return $SUCCESS;
}


function createBoard($theBoard)
{
    global $boardData;
    $puzzle = "";
    $puzzle .= "<table border = 0>\n";
    for ($row = 0; $row < $boardData["height"]; $row++) {
        $puzzle .= "<tr>\n";
        for ($col = 0; $col < $boardData["width"]; $col++) {
            $puzzle .= " <td width = 15>{$theBoard[$row][$col]}</td>\n";
        }
        $puzzle .= "</tr>\n";
    }
    $puzzle .= "</table>\n";
    return $puzzle;
}




function fillExtraSpace()
{
    global $board, $boardData;
    for ($row = 0; $row < $boardData["height"]; $row++) {
        for ($col = 0; $col < $boardData["width"]; $col++) {
            if ($board[$row][$col] == ".") {
                $newLetter = rand(65, 90);
                $board[$row][$col] = chr($newLetter);
            }
        }
    }
}


function printPuzzle()
{
    global $puzzle, $word, $keyPuzzle, $boardData;
    print <<<HERE
<center>
<h1>{$boardData["name"]}</h1>
$puzzle
<h3>Word List</h3>
<table border = 0>
HERE;
    foreach ($word as $theWord) {
        print "<tr><td>$theWord</td></tr>\n";
    }
    print "</table>\n";
    $puzzleName = $boardData["name"];
    print <<<HERE
<br><br>
<form action = "answers.php"
method = "post">
<input type = "hidden"
name = "key"
value = "$keyPuzzle">
<input type = "hidden"
name = "puzzleName"
value = "$puzzleName">
<input type = "submit"
value = "Show Answers">
</form>
</center>
HERE;
} ?>



<html>

<head>
    <link href="style.css" rel="stylesheet">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Word Puzzle</title>
</head>

<body>
    <div class='wrapper_2'>
        <?
        if ($_REQUEST["wordList"] == NULL) {
            $word = array(
                "ANDY",
                "HEATHER",
                "LIZ",
                "MATT",
                "JACOB"
            );
            $boardData = array(
                'width' => 10,
                'height' => 10,
                'name' => "Generic Puzzle"
            );
        } else {
            $boardData = array(
                'width' => $_REQUEST["width"],
                'height' => $_REQUEST["height"],
                'name' => "PUZZLE"
            );
            $wordList = $_REQUEST["wordList"];
            if (getInput() == TRUE) {
                $legalBoard = FALSE;
                while ($legalBoard == FALSE) {
                    putDots();
                    $legalBoard = fillWithLetters();
                }
                $key = $board;
                $keyPuzzle = createBoard($key);
                fillExtraSpace();
                $puzzle = createBoard($board);
                printPuzzle();
            }
        } ?>
    </div>
</body>