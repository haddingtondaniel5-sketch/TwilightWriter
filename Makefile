# Define the target executable
TARGET := TwilightWriter

# Compiler
C_COMPILER := clang

# Homebrew pkg-config path (Apple Silicon)
export PKG_CONFIG_PATH := /opt/homebrew/lib/pkgconfig

# Compiler & Linker flags
CFLAGS := 
LDFLAGS := -lncurses

FLAGS := -Wextra
ADDSAN := -fsanitize=address

# Directories
SRC_DIR := source/
OBJ_DIR := object/

# Source and object files
SOURCE := $(wildcard $(SRC_DIR)*.c)
OBJECTS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))

# Linking command
LINK := $(C_COMPILER) $(FLAGS) $(ADDSAN) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Build all
all: $(TARGET)

test: all
	./TwilightWriter test_file

# Build executable
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	echo "CREATING EXECUTABLE..."
	$(LINK)

# Compile object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "COMPILING OBJECT ($@)"
	$(C_COMPILER) $(FLAGS) $(ADDSAN) $(CFLAGS) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	echo "CREATING OBJECT DIRECTORY..."
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	echo "REMOVING OBJECT FILES..."
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean all
.SILENT: