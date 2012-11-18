all: bin/Robot bin/robot

bin/Robot:
	mkdir -p bin/Robot

bin/Main.o: src/Main.cpp
	g++ -c src/Main.cpp -o bin/Main.o

bin/Robot/Application.o: src/Robot/Application.cpp
	g++ -c src/Robot/Application.cpp -o bin/Robot/Application.o

bin/Robot/FrameListender.o:  src/Robot/FrameListender.cpp
	g++ -c src/Robot/FrameListender.cpp -o bin/Robot/FrameListender.o

bin/robot: bin/Main.o bin/Robot/Application.o bin/Robot/FrameListender.o
	g++ bin/Main.o bin/Robot/Application.o bin/Robot/FrameListender.o -o bin/robot -l boost_system -l OgreMain -l OIS

.PHONY:
clean:
	rm -rf bin ogre.cfg ogre.log

.PHONY:
execute:
	./bin/robot
