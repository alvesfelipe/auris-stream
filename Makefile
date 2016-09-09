CXX=g++
INC_AURIS=-I include/
PATH_SRC=src/*.cpp test/*.cpp
LDFLAGS=-lboost_system -lboost_filesystem -std=c++11
INC_PSTREAMS=-I ../lib/pstreams-0.8.1

all: auris_stream.bin

auris_stream.bin:
	@$(CXX) $(INC_AURIS) $(INC_MIDIFILE) $(INC_PSTREAMS) $(PATH_SRC) -o auris_stream.out \
	$(LDFLAGS)

test:
	@./auris_stream.out