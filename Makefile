all: bin/soalnomor3.out bin/segitigaGradien.cc

bin/soalnomor3.out: pre-build src/soalnomor3.cc
	gcc src/soalnomor3.cc -lglut -lGL -o bin/soalnomor3.out

bin/segitigaGradien.cc: pre-build src/segitigaGradien.cc
	gcc src/segitigaGradien.cc -lglut -lGL -o bin/segitigaGradien.out

pre-build:
