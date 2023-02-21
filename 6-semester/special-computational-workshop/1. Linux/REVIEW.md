# REVIEW


```bash
astatochek@LAPTOP-UO46SGTQ:/mnt/c/WINDOWS/system32$ ssh korotchenok_ostap@84.201.137.222
korotchenok_ostap@84.201.137.222's password:
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-60-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Tue Feb 21 07:19:06 AM UTC 2023

  System load:  0.00439453125      Processes:             186
  Usage of /:   28.8% of 14.68GB   Users logged in:       4
  Memory usage: 32%                IPv4 address for eth0: 10.129.0.21
  Swap usage:   0%

 * Strictly confined Kubernetes makes edge and IoT secure. Learn how MicroK8s
   just raised the bar for easy, resilient and secure K8s cluster deployment.

   https://ubuntu.com/engage/secure-kubernetes-at-the-edge

15 updates can be applied immediately.
To see these additional updates run: apt list --upgradable



The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

korotchenok_ostap@linux-server:~$ mkdir -p folder
korotchenok_ostap@linux-server:~$ ls
folder
korotchenok_ostap@linux-server:~$ cd folder
korotchenok_ostap@linux-server:~/folder$ touch file1.txt
korotchenok_ostap@linux-server:~/folder$ touch file2.txt
korotchenok_ostap@linux-server:~/folder$ ls
file1.txt  file2.txt
korotchenok_ostap@linux-server:~/folder$ chmod 740 file1.txt
korotchenok_ostap@linux-server:~/folder$ chmod 755 file2.txt
korotchenok_ostap@linux-server:~/folder$ vim file1.txt
korotchenok_ostap@linux-server:~/folder$ cat file1.txt
Lorem Ipsum - это текст-"рыба", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной "рыбой" для текстов на латинице с начала XVI века. В то время некий безымянный печатник создал большую коллекцию размеров и форм шрифтов, используя Lorem Ipsum для распечатки образцов. Lorem Ipsum не только успешно пережил без заметных изменений пять веков, но и перешагнул в электронный дизайн. Его популяризации в новое время послужили публикация листов Letraset с образцами Lorem Ipsum в 60-х годах и, в более недавнее время, программы электронной вёрстки типа Aldus PageMaker, в шаблонах которых используется Lorem Ipsum.Lorem Ipsum - это текст-"рыба", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной "рыбой" для текстов на латинице с начала XVI века. В то время некий безымянный печатник создал большую коллекцию размеров и форм шрифтов, используя Lorem Ipsum для распечатки образцов. Lorem Ipsum не только успешно пережил без заметных изменений пять веков, но и перешагнул в электронный дизайн. Его популяризации в новое время послужили публикация листов Letraset с образцами Lorem Ipsum в 60-х годах и, в более недавнее время, программы электронной вёрстки типа Aldus PageMaker, в шаблонах которых используется Lorem Ipsum.
korotchenok_ostap@linux-server:~/folder$ vim file2.txt
korotchenok_ostap@linux-server:~/folder$ cat file2.txt
Давно выяснено, что при оценке дизайна и композиции читаемый текст мешает сосредоточиться. Lorem Ipsum используют потому, что тот обеспечивает более или менее стандартное заполнение шаблона, а также реальное распределение букв и пробелов в абзацах, которое не получается при простой дубликации "Здесь ваш текст.. Здесь ваш текст.. Здесь ваш текст.." Многие программы электронной вёрстки и редакторы HTML используют Lorem Ipsum в качестве текста по умолчанию, так что поиск по ключевым словам "lorem ipsum" сразу показывает, как много веб-страниц всё ещё дожидаются своего настоящего рождения. За прошедшие годы текст Lorem Ipsum получил много версий. Некоторые версии появились по ошибке, некоторые - намеренно (например, юмористические варианты).Давно выяснено, что при оценке дизайна и композиции читаемый текст мешает сосредоточиться. Lorem Ipsum используют потому, что тот обеспечивает более или менее стандартное заполнение шаблона, а также реальное распределение букв и пробелов в абзацах, которое не получается при простой дубликации "Здесь ваш текст.. Здесь ваш текст.. Здесь ваш текст.." Многие программы электронной вёрстки и редакторы HTML используют Lorem Ipsum в качестве текста по умолчанию, так что поиск по ключевым словам "lorem ipsum" сразу показывает, как много веб-страниц всё ещё дожидаются своего настоящего рождения. За прошедшие годы текст Lorem Ipsum получил много версий. Некоторые версии появились по ошибке, некоторые - намеренно (например, юмористические варианты).
```

```bash
korotchenok_ostap@linux-server:~/folder$ cd ../
korotchenok_ostap@linux-server:~$ chmod 755 folder
korotchenok_ostap@linux-server:~$ cd ../
korotchenok_ostap@linux-server:/home$ chmod 755 korotchenok_ostap
korotchenok_ostap@linux-server:/home$ cd zhgilevilya
korotchenok_ostap@linux-server:/home/zhgilevilya$ ls
dir
korotchenok_ostap@linux-server:/home/zhgilevilya$ cd dir
korotchenok_ostap@linux-server:/home/zhgilevilya/dir$ ls
file1.txt  file2.txt
korotchenok_ostap@linux-server:/home/zhgilevilya/dir$ cat file1.txt
cat: file1.txt: Permission denied
korotchenok_ostap@linux-server:/home/zhgilevilya/dir$ cat file2.txt
test test test test another test user
```

```bash
korotchenok_ostap@linux-server:/home$ cp -R zhgilevilya/dir korotchenok_ostap
cp: cannot open 'zhgilevilya/dir/file1.txt' for reading: Permission denied
korotchenok_ostap@linux-server:/home$ cd korotchenok_ostap
korotchenok_ostap@linux-server:~$ ls
dir  folder
korotchenok_ostap@linux-server:~$ cd dir
korotchenok_ostap@linux-server:~/dir$ ls
file2.txt
korotchenok_ostap@linux-server:~/dir$ cat file2.txt
test test test test another test user
korotchenok_ostap@linux-server:~/dir$ grep -o -i TEST file2.txt
test
test
test
test
test
```

```bash
korotchenok_ostap@linux-server:~/dir$ cd ../
korotchenok_ostap@linux-server:~$ ls
dir  folder
korotchenok_ostap@linux-server:~$ chmod 700 folder
korotchenok_ostap@linux-server:~$ ls -l
total 8
drwxrwxr-x 2 korotchenok_ostap korotchenok_ostap 4096 Feb 21 07:46 dir
drwx------ 2 korotchenok_ostap korotchenok_ostap 4096 Feb 21 07:32 folder
```
