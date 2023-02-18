# Task 1

* Создадим базу данных с именем ```ANIME```, в ней - таблицу ```CHARACTERS``` с полями ```id```, ```name```, ```anime```, ```age```.
```cmd
mysql> CREATE DATABASE ANIME;
Query OK, 1 row affected (0.01 sec)

mysql> USE ANIME;
Database changed

mysql> CREATE TABLE CHARACTERS (
    -> id INTEGER NOT NULL,
    -> name TEXT NOT NULL,
    -> anime TEXT NOT NULL,
    -> age INTEGER NOT NULL
    -> );
Query OK, 0 rows affected (0.07 sec)
```
* Добавим данных в таблицу через ```INSERT```
```cmd
mysql> INSERT INTO CHARACTERS VALUES (2, 'Asuka', 'Evangelion', 14); 
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO CHARACTERS VALUES (3, 'Shinji', 'Evangelion', 14); 
Query OK, 1 row affected (0.00 sec)

mysql> INSERT INTO CHARACTERS VALUES (4, 'Rei', 'Evangelion', 0);     
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO CHARACTERS VALUES (5, 'Misato', 'Evangelion', 29); 
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO CHARACTERS VALUES (6, 'Kaworu', 'Evangelion', 15); 
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO CHARACTERS VALUES (7, 'Gendou', 'Evangelion', 48); 
Query OK, 1 row affected (0.00 sec)

mysql> INSERT INTO CHARACTERS VALUES (8, 'Ritsuko', 'Evangelion', 30); 
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO CHARACTERS VALUES (9, 'Rei', 'Promised Neverland', 11); 
Query OK, 1 row affected (0.00 sec)

mysql> INSERT INTO CHARACTERS VALUES (10, 'Norman', 'Promised Neverland', 11); 
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO CHARACTERS VALUES (11, 'Emma', 'Promised Neverland', 11);   
Query OK, 1 row affected (0.00 sec)

mysql> INSERT INTO CHARACTERS VALUES (12, 'Isabella', 'Promised Neverland', 30); 
Query OK, 1 row affected (0.01 sec)
```
* Посмотрим, как теперь выглядит таблица
```cmd
mysql> SELECT * FROM CHARACTERS
    -> ;
+----+----------+--------------------+-----+
| id | name     | anime              | age |
+----+----------+--------------------+-----+
|  2 | Asuka    | Evangelion         |  14 |
|  3 | Shinji   | Evangelion         |  14 |
|  4 | Rei      | Evangelion         |   0 |
|  5 | Misato   | Evangelion         |  29 |
|  6 | Kaworu   | Evangelion         |  15 |
|  7 | Gendou   | Evangelion         |  48 |
|  8 | Ritsuko  | Evangelion         |  30 |
|  9 | Rei      | Promised Neverland |  11 |
| 10 | Norman   | Promised Neverland |  11 |
| 11 | Emma     | Promised Neverland |  11 |
| 12 | Isabella | Promised Neverland |  30 |
+----+----------+--------------------+-----+
11 rows in set (0.00 sec)
```
* Попробуем сделать несколько простых запросов
```cmd
mysql> SELECT * FROM CHARACTERS WHERE anime = 'Evangelion' AND age = 14
    -> ;
+----+--------+------------+-----+
| id | name   | anime      | age |
+----+--------+------------+-----+
|  2 | Asuka  | Evangelion |  14 |
|  3 | Shinji | Evangelion |  14 |
+----+--------+------------+-----+
2 rows in set (0.00 sec)
```
* Выведем всех персонажей старше 18
```cmd
mysql> SELECT * FROM CHARACTERS WHERE age >= 18                        
    -> ;
+----+----------+--------------------+-----+
| id | name     | anime              | age |
+----+----------+--------------------+-----+
|  5 | Misato   | Evangelion         |  29 |
|  7 | Gendou   | Evangelion         |  48 |
|  8 | Ritsuko  | Evangelion         |  30 |
| 12 | Isabella | Promised Neverland |  30 |
+----+----------+--------------------+-----+
4 rows in set (0.00 sec)
```
* Сделаем более сложный запрос: выведем средний возраст персонажей каждого из аниме.
```cmd
mysql> SELECT anime, AVG(age) AS average_age FROM CHARACTERS  GROUP BY anime; 
+--------------------+-------------+
| anime              | average_age |
+--------------------+-------------+
| Evangelion         |     21.4286 |
| Promised Neverland |     15.7500 |
+--------------------+-------------+
2 rows in set (0.01 sec)
```