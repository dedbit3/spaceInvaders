SOURCES = main.cpp
space_invaders: $(SOURCES)
	g++ -Wall -g -o space_invaders.exe $(SOURCES) -lGLEW -lglfw -lGL
.PHONY: test clean all
