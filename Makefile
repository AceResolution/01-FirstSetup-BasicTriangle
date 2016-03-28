CXX = g++
CXXFLAGS = -Wall -g
LIBS = -lGLEW -lglfw3 -lGLU -lGL -lX11 -lXxf86vm -lXrandr -lXinerama -lXcursor -lpthread -lXi -ldl

all: bin 01-EnvironmentSetup 02-Triangle clean bin/soalnomor3.out bin/segitigaGradien.cc

# Initialise /bin folder
bin:
	mkdir -p bin

# For 01-EnvironmentSetup
01-EnvironmentSetup: src/01-EnvironmentSetup.o
	$(CXX) $(CXXFLAGS) -o bin/01-EnvironmentSetup.lexec 01-EnvironmentSetup.o $(LIBS)

src/01-EnvironmentSetup.o: src/01-EnvironmentSetup.cpp
	$(CXX) $(CXXFLAGS) -c src/01-EnvironmentSetup.cpp $(LIBS)

# For 02-Triangle
02-Triangle: src/02-Triangle.o
	$(CXX) $(CXXFLAGS) -o bin/02-Triangle.lexec 02-Triangle.o $(LIBS)

src/02-Triangle.o: src/02-Triangle.cpp
	$(CXX) $(CXXFLAGS) -c src/02-Triangle.cpp $(LIBS)

clean:
	find . -type f -name '*.o' -delete

# For 2nd and 3rd Question (Nizami)

bin/soalnomor3.out: pre-build src/soalnomor3.cc
	gcc src/soalnomor3.cc -lglut -lGL -o bin/soalnomor3.out

bin/segitigaGradien.cc: pre-build src/segitigaGradien.cc
	gcc src/segitigaGradien.cc -lglut -lGL -o bin/segitigaGradien.out

pre-build:
