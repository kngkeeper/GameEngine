# compiler
Cxx=g++

# compiler flags
CXXFLAGS=-O -Wall -lglfw -lGLEW -lGL -std=c++11
DEBUG_FLAGS=-Og -g

# executable
OUTPUT=main

all: $(OUTPUT)

$(OUTPUT): main.o window.o shader.o input.o math.o fileutils.o buffers.o indexbuffer.o vertexarray.o simple2DRenderer.o
	$(Cxx) main.o window.o shader.o input.o math.o fileutils.o buffers.o indexbuffer.o vertexarray.o simple2DRenderer.o -o $(OUTPUT) $(CXXFLAGS)

debug: main.o window.o shader.o input.o math.o fileutils.o buffers.o indexbuffer.o vertexarray.o simple2DRenderer.o
	$(Cxx) main.o window.o shader.o input.o math.o fileutils.o buffers.o indexbuffer.o vertexarray.o simple2DRenderer.o -o $(OUTPUT) $(CXXFLAGS) $(DEBUG_FLAGS)

main.o:
	$(Cxx) -c main.cpp -std=c++11

simple2DRenderer.o:
	$(Cxx) -c ./src/graphics/simple2DRenderer.cpp -std=c++11

renderable2D.o: buffers.o indexbuffer.o vertexarray.o math.o shader.o
	$(Cxx) -c ./src/graphics/renderable2D.cpp -std=c++11

window.o: input.o math.o
	$(Cxx) -c ./src/graphics/window.cpp -std=c++11

shader.o: fileutils.o math.o
	$(Cxx) -c ./src/graphics/shader.cpp -std=c++11

vertexarray.o: buffers.o
	$(Cxx) -c ./src/graphics/buffers/vertexarray.cpp -std=c++11

input.o:
	$(Cxx) -c ./src/IO/input.cpp -std=c++11

math.o:
	$(Cxx) -c ./src/Math/math.cpp -std=c++11

fileutils.o:
	$(Cxx) -c ./src/Utils/fileutils.cpp -std=c++11

buffers.o:
	$(Cxx) -c ./src/graphics/buffers/buffers.cpp -std=c++11

indexbuffer.o:
	$(Cxx) -c ./src/graphics/buffers/indexbuffer.cpp -std=c++11

clean:
	rm -f *.o $(OUTPUT)
