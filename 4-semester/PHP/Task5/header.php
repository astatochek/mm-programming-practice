<?php
session_start();

if (!file_exists("mydb.db")){
	$db=new SQLite3("mydb.db");
	$sql="CREATE TABLE users(
	id INTEGER PRIMARY KEY;
	s
	)";
}

?>