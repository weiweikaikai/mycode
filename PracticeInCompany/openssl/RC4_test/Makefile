
SRC=RC4.cpp
BIN=RC4
LIB=  -lssl
INCLUDE=-I./
FLAGS=-Wall -g #-O2

$(BIN):$(SRC)
	g++  $^ -o $@ $(FLAGS)  $(LIB) $(INCLUDE)
clean:
	rm $(BIN) 

