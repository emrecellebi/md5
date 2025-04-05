@echo off

gcc -c ./src/test/main.c -I ./include
gcc -o ./bin/md5.exe main.o -L ./lib -lmd5
gcc -o ./bin/_md5.exe main.o -L ./lib -lmd5lib

del *.o