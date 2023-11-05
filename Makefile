# Specified compile and linker flags
CC:=i686-w64-mingw32-gcc
CXX:=i686-w64-mingw32-g++
CFLAGS = -Wall -Wextra -Werror -DCONSOLE_DEBUG_ONLY
CXXFLAGS = -Wall -Wextra -Werror -DCONSOLE_DEBUG_ONLY
CLINKFLAGS = -static -shared
CXXLINKFLAGS = -static -shared


rwc = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwc,$d/,$2))

# Discover all C and C++ source files in core and the specified project
CORE_C_SOURCES = $(call rwc,core/src/,*.c)
CORE_CXX_SOURCES = $(call rwc,core/src/,*.cpp)
PROJECT_C_SOURCES = $(call rwc,projects/$(PROJECT)/src/,*.c)
PROJECT_CXX_SOURCES = $(call rwc,projects/$(PROJECT)/src/,*.cpp)

# Determine object file names by replacing the source directory with $(BUILD_DIR)/obj and the file extension with .o
CORE_C_OBJECTS = $(patsubst core/src/%, $(BUILD_DIR)/obj/core/src/%, $(CORE_C_SOURCES:.c=.o))
CORE_CXX_OBJECTS = $(patsubst core/src/%, $(BUILD_DIR)/obj/core/src/%, $(CORE_CXX_SOURCES:.cpp=.o))
PROJECT_C_OBJECTS = $(patsubst projects/$(PROJECT)/src/%, $(BUILD_DIR)/obj/projects/$(PROJECT)/src/%, $(PROJECT_C_SOURCES:.c=.o))
PROJECT_CXX_OBJECTS = $(patsubst projects/$(PROJECT)/src/%, $(BUILD_DIR)/obj/projects/$(PROJECT)/src/%, $(PROJECT_CXX_SOURCES:.cpp=.o))

# Library include and link paths for ehook
EH_LIB_DIR = lib/ehook/build/x32/lib
EH_INCLUDE_DIR = lib/ehook/src
LIBS = -L$(EH_LIB_DIR) -lehook
INCLUDES = -I$(EH_INCLUDE_DIR) -Icore/src

ifndef PROJECT
default_target: help
else
default_target: all
endif

ifeq ($(MAKECMDGOALS),debug)
    CFLAGS += -O0 -g -DDEBUG
    BUILD_DIR = build/debug
else
    CFLAGS += -O3
    BUILD_DIR = build/release
endif

.PHONY: help all debug lib_ehook clean default_target

help:
	@echo "Usage: make [TARGET] PROJECT=project_name"
	@echo ""
	@echo "If no TARGET is specified, a release build is created by default."
	@echo "TARGET:"
	@echo "  (none) : Build the specified project as a release build."
	@echo "  debug  : Build the specified project with debug information."
	@echo "  clean  : Remove all built objects and the resulting binaries of the specified project."
	@echo ""
	@echo "The PROJECT variable specifies which project to build."
	@echo "For example, to build a project named 'aimbot' in release mode use:"
	@echo "  make PROJECT=aimbot"
	@echo "To build with debug information:"
	@echo "  make debug PROJECT=aimbot"
	@echo ""
	@echo "Use 'make clean' to clean the build artifacts."

all: lib_ehook $(BUILD_DIR)/bin/projects/$(PROJECT).dll
debug: default_target

lib_ehook:
	$(MAKE) -C lib/ehook build ARCH=32

# Pattern rules for compiling C and C++ source files to object files
$(BUILD_DIR)/obj/core/src/%.o: core/src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/obj/core/src/%.o: core/src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/obj/projects/$(PROJECT)/src/%.o: projects/$(PROJECT)/src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/obj/projects/$(PROJECT)/src/%.o: projects/$(PROJECT)/src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Link the object files to create the binary
$(BUILD_DIR)/bin/projects/$(PROJECT).dll: $(CORE_C_OBJECTS) $(CORE_CXX_OBJECTS) $(PROJECT_C_OBJECTS) $(PROJECT_CXX_OBJECTS)
	mkdir -p $(dir $@)
	$(CXX) $(CORE_C_OBJECTS) $(CORE_CXX_OBJECTS) $(PROJECT_C_OBJECTS) $(PROJECT_CXX_OBJECTS) $(CXXLINKFLAGS) $(LIBS) -o $@

clean:
	rm -rf build
	$(MAKE) -C lib/ehook clean
