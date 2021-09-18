all: boot1 boot2

boot1: boot1.asm boot2.exe

boot2: boot2.exe

boot2.exe: boot2_s.o boot2_c.o

boot2_s.o: boot2.s 

boot2_c.o: boot2.c