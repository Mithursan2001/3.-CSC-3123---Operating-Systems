login as: 2021asp32
2021asp32@172.16.150.200's password:
Last login: Mon Sep  8 10:22:44 2025 from 172.16.150.22
[2021asp32@fedora ~]$ mkdir mithu
mkdir: cannot create directory ‘mithu’: File exists
[2021asp32@fedora ~]$ mkdir A
mkdir: cannot create directory ‘A’: File exists
[2021asp32@fedora ~]$ mkdir M
mkdir: cannot create directory ‘M’: File exists
[2021asp32@fedora ~]$ cd mithu
[2021asp32@fedora mithu]$ touch ex1.c
[2021asp32@fedora mithu]$ vi ex1.c
[2021asp32@fedora mithu]$ cd A
-bash: cd: A: No such file or directory
[2021asp32@fedora mithu]$ mkdir A
[2021asp32@fedora mithu]$ cd A
[2021asp32@fedora A]$ touch ex1.c
[2021asp32@fedora A]$ vi ex1.c
[2021asp32@fedora A]$ gcc ex1.c -o f1exe
[2021asp32@fedora A]$ ./f1exe
Hello!
Good Morning!
Good Morning!
You're Welcome!
You're Welcome!
You're Welcome!
You're Welcome!
[2021asp32@fedora A]$ touch ex2.c
[2021asp32@fedora A]$ vi ex2.c
[2021asp32@fedora A]$ gcc ex2.c -o f2exe
[2021asp32@fedora A]$ ./f2exe
My process is 7371
[2021asp32@fedora A]$ touch ex3.c
[2021asp32@fedora A]$ vi ex3.c
[2021asp32@fedora A]$ gcc ex3.c -o f3exe
[2021asp32@fedora A]$ ./f3exe
My process is 7787
[2021asp32@fedora A]$ vi ex3.c
[2021asp32@fedora A]$ gcc ex3.c -o f3exe
[2021asp32@fedora A]$ ./f3exe
Hello!
My process is 8022
My process is 8023
[2021asp32@fedora A]$ touch ex4.c
[2021asp32@fedora A]$ vi ex4.c
[2021asp32@fedora A]$ gcc ex4.c -o f4exe
[2021asp32@fedora A]$ ./f4exe
Hello!
My process is 8518
Parent process is 1784
[2021asp32@fedora A]$ ./f4exe
Hello!
My process is 8681
Parent process is 1784
[2021asp32@fedora A]$ touch ex5.c
[2021asp32@fedora A]$ vi ex5.c
[2021asp32@fedora A]$ gcc ex5.c -o f5exe
[2021asp32@fedora A]$ ./f5exe
My process is 8989 and parent process is 1784
My process is 8991 and parent process is 8989
My process is 8992 and parent process is 8990
My process is 8990 and parent process is 8989
[2021asp32@fedora A]$ touch ex6.c
[2021asp32@fedora A]$ vi ex6.c
[2021asp32@fedora A]$ gcc ex6.c -o f6exe
[2021asp32@fedora A]$ ./f6exe

I'm Parent! My process id  is 9598

My Parent's process id  is 1784
Value of v is 9599

I'm Child! My process id  is 9599

My Parent's process id  is 1
Value of v is 0
[2021asp32@fedora A]$
