CPPC = gcc
CPPC_FLAGS = -g -Wall -Werror

TARGET = terminal

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(SRC_DIR)/*.cpp

DEL_FILE = rm -f
LIBS_DIRS = -I/.include/
LIBS = $(LIBS_DIRS) -lstdc++

.PHONY: clean build
all: clean build
 
build: $(SOURCE)
	$(CPPC) $(CPPC_FLAGS) $(LIBS) $(SOURCES) -o $(BIN_DIR)/$(TARGET)
run:
	./$(BIN_DIR)/$(TARGET)
  
clean:
	$(DEL_FILE) $(BIN_DIR)/*


