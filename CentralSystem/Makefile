EXECUTABLE=central_server

INCLUDE_DIR=include/
SOURCE_DIR=src/

BUILD_DIR=build
BIN_DIR=$(BUILD_DIR)/bin/
OBJECT_DIR=$(BUILD_DIR)/obj/

CFLAGS=-c -Wall -I$(INCLUDE_DIR)
LDFLAGS=

CC=g++
RM=rm -r
MKDIR=mkdir -p

SOURCES=$(notdir $(wildcard $(SOURCE_DIR)/*.cpp))
OBJECTS=$(SOURCES:.cpp=.o)

CPP_OBJECTS=$(addprefix $(OBJECT_DIR),$(OBJECTS))
CPP_SOURCES=$(addprefix $(SOURCE_DIR),$(SOURCES))
CPP_EXECUTABLE=$(addprefix $(BIN_DIR),$(EXECUTABLE))

all: $(CPP_SOURCES) $(CPP_EXECUTABLE)

$(CPP_EXECUTABLE): $(CPP_OBJECTS)
	@$(MKDIR) $(@D)
	$(CC) $(LDFLAGS) $(CPP_OBJECTS) -o $@

$(OBJECT_DIR)%.o: $(SOURCE_DIR)%.cpp
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(BUILD_DIR)
