# Task 2
* Загрузим в ```PhpMyAdmin``` (используется OpenServer) тренировочную базу данных [MySQL—world.sql](https://dev.mysql.com/doc/index-other.html) и рассмотрим раблицу ```countrylanguage```.
* Выведем первые 15 строк и используем только столбцы ```CountryCode```, ```Language```, ```IsOfficial```
```cmd
mysql> SELECT CountryCode, Language, IsOfficial  FROM `countrylanguage` limit 15; 
+-------------+------------------+------------+
| CountryCode | Language         | IsOfficial |
+-------------+------------------+------------+
| ABW         | Dutch            | T          |
| ABW         | English          | F          |
| ABW         | Papiamento       | F          |
| ABW         | Spanish          | F          |
| AFG         | Balochi          | F          |
| AFG         | Dari             | T          |
| AFG         | Pashto           | T          |
| AFG         | Turkmenian       | F          |
| AFG         | Uzbek            | F          |
| AGO         | Ambo             | F          |
| AGO         | Chokwe           | F          |
| AGO         | Kongo            | F          |
| AGO         | Luchazi          | F          |
| AGO         | Luimbe-nganguela | F          |
| AGO         | Luvale           | F          |
+-------------+------------------+------------+
15 rows in set (0.00 sec)
```
* Выведем данные о странах, где процент говорящего на нем населения максимален.
```cmd
mysql> SELECT * FROM countrylanguage WHERE Percentage = (SELECT MAX(Percentage) from countrylanguage CountryCode) ORDER BY `countrylanguage`.`CountryCode` ASC
    -> ;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    304
Current database: WORLD

+-------------+----------------+------------+------------+
| CountryCode | Language       | IsOfficial | Percentage |
+-------------+----------------+------------+------------+
| BMU         | English        | T          |      100.0 |
| CPV         | Crioulo        | F          |      100.0 |
| CUB         | Spanish        | T          |      100.0 |
| DMA         | Creole English | F          |      100.0 |
| ESH         | Arabic         | T          |      100.0 |
| FRO         | Faroese        | T          |      100.0 |
| GRD         | Creole English | F          |      100.0 |
| HTI         | Haiti Creole   | F          |      100.0 |
| KNA         | Creole English | F          |      100.0 |
| MDV         | Dhivehi        | T          |      100.0 |
| RWA         | Rwanda         | T          |      100.0 |
| SLV         | Spanish        | T          |      100.0 |
| SMR         | Italian        | T          |      100.0 |
+-------------+----------------+------------+------------+
13 rows in set (0.01 sec)
```
* Выведем все страны, где Английский является официальным языком.
```cmd
mysql> SELECT * FROM countrylanguage WHERE LANGUAGE = 'English' AND IsOfficial = 'T' ORDER BY `countrylanguage`.`CountryCode` ASC
    -> ;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM countrylanguage WHERE LANGUAGE = 'English' AND IsOfficial = 'T' ORDER BY `countrylanguage`.`CountryCode` ASC;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    341
Current database: WORLD

+-------------+----------+------------+------------+
| CountryCode | Language | IsOfficial | Percentage |
+-------------+----------+------------+------------+
| AIA         | English  | T          |        0.0 |
| ASM         | English  | T          |        3.1 |
| ATG         | English  | T          |        0.0 |
| AUS         | English  | T          |       81.2 |
| BLZ         | English  | T          |       50.8 |
| BMU         | English  | T          |      100.0 |
| BRB         | English  | T          |        0.0 |
| CAN         | English  | T          |       60.4 |
| CCK         | English  | T          |        0.0 |
| CXR         | English  | T          |        0.0 |
| CYM         | English  | T          |        0.0 |
| FLK         | English  | T          |        0.0 |
| GBR         | English  | T          |       97.3 |
| GIB         | English  | T          |       88.9 |
| GUM         | English  | T          |       37.5 |
| HKG         | English  | T          |        2.2 |
| IRL         | English  | T          |       98.4 |
| KNA         | English  | T          |        0.0 |
| LCA         | English  | T          |       20.0 |
| LSO         | English  | T          |        0.0 |
| MHL         | English  | T          |        0.0 |
| MLT         | English  | T          |        2.1 |
| MNP         | English  | T          |        4.8 |
| MSR         | English  | T          |        0.0 |
| NFK         | English  | T          |        0.0 |
| NIU         | English  | T          |        0.0 |
| NRU         | English  | T          |        7.5 |
| NZL         | English  | T          |       87.0 |
| PLW         | English  | T          |        3.2 |
| SHN         | English  | T          |        0.0 |
| SYC         | English  | T          |        3.8 |
| TCA         | English  | T          |        0.0 |
| TKL         | English  | T          |        0.0 |
| TON         | English  | T          |        0.0 |
| TUV         | English  | T          |        0.0 |
| UMI         | English  | T          |        0.0 |
| USA         | English  | T          |       86.2 |
| VCT         | English  | T          |        0.0 |
| VGB         | English  | T          |        0.0 |
| VIR         | English  | T          |       81.7 |
| VUT         | English  | T          |       28.3 |
| WSM         | English  | T          |        0.6 |
| ZAF         | English  | T          |        8.5 |
| ZWE         | English  | T          |        2.2 |
+-------------+----------+------------+------------+
44 rows in set (0.01 sec)
```