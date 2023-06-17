PROJ_NAME = main
CXX = g++
CPPFLAGS = -Wall -Wextra -std=c++17 -pedantic
RM = rm -rf
OBJ_DIR = bin
RM = rm -rf

all: $(OBJ_DIR) $(PROJ_NAME)

$(PROJ_NAME):	$(OBJ_DIR)/main.o $(OBJ_DIR)/compressor.o $(OBJ_DIR)/decompressor.o	$(OBJ_DIR)/Compactor.o
	$(CXX) $(CPPFLAGS) $^  -o $(PROJ_NAME) 

$(OBJ_DIR)/main.o:	src/main.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/compressor.o: src/compressor.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/decompressor.o: src/decompressor.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/Compactor.o: src/Compactor.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR) $(PROJ_NAME)
