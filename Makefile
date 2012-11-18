all: bin/Robot bin/robot

bin/Robot:
	mkdir -p bin/Robot

bin/Main.o: src/Main.cpp
	g++ -c src/Main.cpp -o bin/Main.o

bin/Robot/Application.o: src/Robot/Application.cpp
	g++ -c src/Robot/Application.cpp -o bin/Robot/Application.o

bin/Robot/FrameListener.o:  src/Robot/FrameListener.cpp
	g++ -c src/Robot/FrameListener.cpp -o bin/Robot/FrameListener.o

bin/robot: bin/Main.o bin/Robot/Application.o bin/Robot/FrameListener.o
	g++ bin/Main.o bin/Robot/Application.o bin/Robot/FrameListener.o -o bin/robot -l boost_system -l OgreMain -l OIS

.PHONY:
clean:
	rm -rf bin ogre.cfg ogre.log

.PHONY:
execute: all
	./bin/robot
