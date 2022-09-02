CC = g++ 
SRCS = ./src/*.cpp
INC = ./src/
OPTS = -std=c++17 -Wall -Werror -lpthread -O3
DEBUG_OPTS = -std=c++17 -Wall -Werror -lpthread -g

EXEC = bin/prefix_scan

all: clean compile

debug: clean debug_compile

compile:
	$(CC) $(SRCS) $(OPTS) -I$(INC) -o $(EXEC)

debug_compile:
	$(CC) $(SRCS) $(DEBUG_OPTS) -I$(INC) -o $(EXEC)

clean:
	rm -f $(EXEC)
