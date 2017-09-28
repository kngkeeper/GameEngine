clean:
	rm -r *.o

all: main

main: main.o
	g++ main.o window.o shader.o input.o math.o fileutils.o buffers.o indexbuffer.o vertexarray.o simple2DRenderer.o -o main -lglfw -lGLEW -lGL -std=c++11

main.o: window.o shader.o input.o math.o fileutils.o buffers.o indexbuffer.o vertexarray.o simple2DRenderer.o
	g++ -c main.cpp -std=c++11

simple2DRenderer.o:
	g++ -c ./src/graphics/simple2DRenderer.cpp -std=c++11

renderable2D.o: buffers.o indexbuffer.o vertexarray.o math.o shader.o
	g++ -c ./src/graphics/renderable2D.cpp -std=c++11

window.o: input.o math.o
	g++ -c ./src/graphics/window.cpp -std=c++11

shader.o: fileutils.o math.o
	g++ -c ./src/graphics/shader.cpp -std=c++11

vertexarray.o: buffers.o
	g++ -c ./src/graphics/buffers/vertexarray.cpp -std=c++11



input.o:
	g++ -c ./src/IO/input.cpp -std=c++11

math.o:
	g++ -c ./src/Math/math.cpp -std=c++11

fileutils.o:
	g++ -c ./src/Utils/fileutils.cpp -std=c++11

buffers.o:
	g++ -c ./src/graphics/buffers/buffers.cpp -std=c++11

indexbuffer.o:
	g++ -c ./src/graphics/buffers/indexbuffer.cpp -std=c++11

