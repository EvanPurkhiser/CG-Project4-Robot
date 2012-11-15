all: bin/robot

bin/robot: src/robot.cpp
	g++ src/robot.cpp -o bin/robot -l glfw -l glew32 -l opengl32 -static
