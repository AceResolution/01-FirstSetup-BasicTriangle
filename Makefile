all: bin/soalnomor3.out

bin/soalnomor3.out: pre-build src/soalnomor3.cc
	gcc src/soalnomor3.cc -lglut -lGL -o bin/soalnomor3.out

pre-build:
