# Variables
CC=gcc
CFLAGS=-Wall -Wpedantic -std=c11
LDFLAGS=-lGL -lSDL2

SRC_DIR=./src
BUILD_DIR=./build
BIN_DIR=./bin

# Name of output program
NAME=uvisual

SRCS=$(wildcard $(SRC_DIR)/*.c)

# Replace all of the source files to build files
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)


# Build rules

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(BIN_DIR)/$(NAME)

# Make sure that a build directory exists before trying to build
$(OBJS): | $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o

# Make sure the directory structure is as it should be
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)
