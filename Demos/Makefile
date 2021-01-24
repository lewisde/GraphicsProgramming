cc = g++
CFLAGS = -Wall -std=c++17 -O2
GLFLAGS = -lglut -lGL -lGLU

all: opengl_triangle 

opengl_triangle: opengl_triangle.cpp
	$(cc) $(CFLAGS) opengl_triangle.cpp $(GLFLAGS) -o opengl_triangle

clean: 
	$(RM) opengl_triangle

test: opengl_triangle 
	./opengl_triangle
