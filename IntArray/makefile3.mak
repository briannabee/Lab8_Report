a.exe: IntArray.o main-skeleton.o
	g++ IntArray.o main-skeleton.o
IntArray.o: IntArray.h IntArray.cpp
	g++ -c -g IntArray.cpp
main.o: IntArray.h main-skeleton.cpp
	g++ -c -g main-skeleton.cpp
clean:
	del *.o a.exe