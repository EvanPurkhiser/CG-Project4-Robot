all: bin/robot

bin/robot: src/robot.cpp src/common/shader.cpp
	g++ src/robot.cpp src/common/shader.cpp src/common/texture.cpp -o bin/robot -l glew32s -l glfw -l opengl32 -static -D GLEW_STATIC

test:
	cd src && ../bin/robot
