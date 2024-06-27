SOURCES = main.cpp graphics.cpp
space_invaders: $(SOURCES)
	g++ -Wall -g -o space_invaders.exe $(SOURCES) -lGLEW -lglut -lglfw -lGL
.PHONY: test clean all
