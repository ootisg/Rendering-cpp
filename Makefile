main: v2 mat2 main.cpp
	g++ v2.o mat2.o main.cpp
v2: glmath/v2.cpp glmath/v2.h
	g++ -c glmath/v2.cpp
mat2: glmath/mat2.cpp glmath/mat2.h
	g++ -c glmath/mat2.cpp
