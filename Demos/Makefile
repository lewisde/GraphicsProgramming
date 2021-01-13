cc = g++
CFLAGS = -Wall -std=c++17 -O2
VKFLAGS = -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -lglfw
GLFLAGS = -lglut -lGL -lGLU

all: shaders hello_triangle opengl_triangle 

shaders: shader.frag shader.vert

shader.frag:
	glslc shaders/shader.frag -o frag.spv

shader.vert:
	glslc shaders/shader.vert -o vert.spv


opengl_triangle: opengl_triangle.cpp
	$(cc) $(CFLAGS) opengl_triangle.cpp $(GLFLAGS) -o opengl_triangle

hello_triangle: hello_triangle.cpp
	$(cc) $(CFLAGS) hello_triangle.cpp $(VKFLAGS) -o hello_triangle

clean: 
	$(RM) hello_triangle
	$(RM) opengl_triangle
	$(RM) frag.spv
	$(RM) vert.spv

test: hello_triangle opengl_triangle
	./hello_triangle 
	./opengl_triangle
