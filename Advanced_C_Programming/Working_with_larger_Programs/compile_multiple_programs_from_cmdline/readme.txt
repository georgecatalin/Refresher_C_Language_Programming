georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Working_with_larger_Programs/Overview$ ls -lh
total 28K
-rwxrwxr-x 1 georgeca georgeca 16K Sep 15 11:24 main
-rw-rw-r-- 1 georgeca georgeca 121 Sep 15 11:21 main.c
-rw-rw-r-- 1 georgeca georgeca  60 Sep 15 11:21 other.c
-rw-rw-r-- 1 georgeca georgeca  82 Sep 15 11:21 other.h
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Working_with_larger_Programs/Overview$ gcc other.c -c
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Working_with_larger_Programs/Overview$ ls -lh
total 32K
-rwxrwxr-x 1 georgeca georgeca  16K Sep 15 11:24 main
-rw-rw-r-- 1 georgeca georgeca  121 Sep 15 11:21 main.c
-rw-rw-r-- 1 georgeca georgeca   60 Sep 15 11:21 other.c
-rw-rw-r-- 1 georgeca georgeca   82 Sep 15 11:21 other.h
-rw-rw-r-- 1 georgeca georgeca 1,3K Sep 15 11:50 other.o
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Working_with_larger_Programs/Overview$ gcc main.c -c
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Working_with_larger_Programs/Overview$ ls -lh
total 36K
-rwxrwxr-x 1 georgeca georgeca  16K Sep 15 11:24 main
-rw-rw-r-- 1 georgeca georgeca  121 Sep 15 11:21 main.c
-rw-rw-r-- 1 georgeca georgeca 1,6K Sep 15 11:50 main.o
-rw-rw-r-- 1 georgeca georgeca   60 Sep 15 11:21 other.c
-rw-rw-r-- 1 georgeca georgeca   82 Sep 15 11:21 other.h
-rw-rw-r-- 1 georgeca georgeca 1,3K Sep 15 11:50 other.o
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Working_with_larger_Programs/Overview$ gcc main.o other.o -o program
georgeca@georgeca-VirtualBox:~/my_sandbox/Advanced_C_Programming/Working_with_larger_Programs/Overview$ ls -lh
total 52K
-rwxrwxr-x 1 georgeca georgeca  16K Sep 15 11:24 main
-rw-rw-r-- 1 georgeca georgeca  121 Sep 15 11:21 main.c
-rw-rw-r-- 1 georgeca georgeca 1,6K Sep 15 11:50 main.o
-rw-rw-r-- 1 georgeca georgeca   60 Sep 15 11:21 other.c
-rw-rw-r-- 1 georgeca georgeca   82 Sep 15 11:21 other.h
-rw-rw-r-- 1 georgeca georgeca 1,3K Sep 15 11:50 other.o
-rwxrwxr-x 1 georgeca georgeca  16K Sep 15 11:50 program
