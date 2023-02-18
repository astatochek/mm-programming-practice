<?php
$pdo= new SQLite3("mydb.sqlite");
$pdo->query("BEGIN;
CREAte table if not exists users(id INTEGER PRIMARY KEY, name CHAR(255),password CHAR(32));
COMMIT;");
$pdo->query("BEGIN;
CREAte table if not exists notes(id INTEGER PRIMARY KEY, name CHAR(255),text CHAR(255));
COMMIT;");

?>