a.exe: FiniteQueue.o main3.o
	g++ FiniteQueue.o main3.o
FiniteQueue.o: FiniteQueue.h FiniteQueue.cpp
	g++ -c -g FiniteQueue.cpp
main3.o: FiniteQueue.h main3.cpp
	g++ -c -g main3.cpp
clean:
	del *.o a.exe