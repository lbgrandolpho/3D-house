all: main

main:
	gcc casa3d.c -o casa3d -lm -lGL -lGLU -lglut

clean:
	rm casa3d