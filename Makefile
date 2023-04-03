main: v2 main.cpp
	g++ v2.o main.cpp
v2: glmath/v2.cpp glmath/v2.h
	g++ -c glmath/v2.cpp
