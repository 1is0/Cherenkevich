all: build run clean
LR7.o: 6.2(24).cpp Menu.cpp InputOutput.cpp Structs.cpp InputOutput.h Menu.h Structs.h
 	gcc -c -o LR7.o 6.2(24).cpp Menu.cpp InputOutput.cpp Structs.cpp InputOutput.h Menu.h Structs.h
build: LR7.o
      	gcc -o LR7 LR7.o
run:
      	LR7.exe
clean:
      	del *.o LR7
