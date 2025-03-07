# make file configured for EGR111 workspace
# see https://dev.to/talhabalaj/setup-visual-studio-code-for-multi-file-c-projects-1jpi
# Thank you Talha Balaj
# 3/5/2022
# ******* Requirements ******
# 1. Included launch.json and tasks.json files provided
# 2. Add bin folder. Compiled binary is here as main
# 3. Only one main() function with int return
# 4. Use subdirectories as required
# 5. *** src_dir must be updated ***
src_dir = week09/carddeck

CC        := g++
C_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := $(src_dir)
INCLUDE := $(src_dir)

LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c $(SRC)/*.h
	$(CC) $(C_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
