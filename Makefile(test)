CC = g++
CCFLAGS = -I./include -L./build
SRC_DIR = src
OBJ_DIR = build
INC_DIR = include
BIN = bin
LIBS = -llayer -lnetwork

test.exe : $(SRC_DIR)/test.cpp $(OBJ_DIR)/liblayer.a $(OBJ_DIR)/libnetwork.a
	$(CC) $< $(CCFLAGS) -fno-elide-constructors $(LIBS) -o $@
	
$(OBJ_DIR)/datahandler/datahandler.o : $(SRC_DIR)/datahandler/datahandler.cpp $(INC_DIR)/datahandler/datahandler.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/core/core.o : $(SRC_DIR)/core/core.cpp $(INC_DIR)/core/core.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/layer/zeropadding.o : $(SRC_DIR)/layer/zeropadding.cpp $(INC_DIR)/layer/zeropadding.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/layer/maxpooling.o : $(SRC_DIR)/layer/maxpooling.cpp $(INC_DIR)/layer/maxpooling.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/layer/convolution.o : $(SRC_DIR)/layer/convolution.cpp $(INC_DIR)/layer/convolution.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/layer/relu.o : $(SRC_DIR)/layer/relu.cpp $(INC_DIR)/layer/relu.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/layer/fc.o : $(SRC_DIR)/layer/fc.cpp $(INC_DIR)/layer/fc.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/layer/softmax.o : $(SRC_DIR)/layer/softmax.cpp $(INC_DIR)/layer/softmax.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/network/model.o : $(SRC_DIR)/network/model.cpp $(INC_DIR)/network/model.hpp
	$(CC) -c $< -o $@

$(OBJ_DIR)/liblayer.a : $(OBJ_DIR)/core/core.o $(OBJ_DIR)/layer/zeropadding.o $(OBJ_DIR)/layer/maxpooling.o $(OBJ_DIR)/layer/convolution.o $(OBJ_DIR)/layer/relu.o $(OBJ_DIR)/layer/fc.o
	ar rc $@ $^

$(OBJ_DIR)/libnetwork.a : $(OBJ_DIR)/network/model.o $(OBJ_DIR)/datahandler/datahandler.o
	ar rc $@ $^

clean:
	rm -f $(OBJ_DIR)/core/*.o
	rm -f $(OBJ_DIR)/layer/*.o