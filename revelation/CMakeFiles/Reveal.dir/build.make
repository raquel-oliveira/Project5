# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Raquel/Desktop/NSA/private/revelation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Raquel/Desktop/NSA/private/revelation

# Include any dependencies generated for this target.
include CMakeFiles/reveal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reveal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reveal.dir/flags.make

CMakeFiles/reveal.dir/src/main.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/reveal.dir/src/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/main.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/main.c

CMakeFiles/reveal.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/main.c > CMakeFiles/reveal.dir/src/main.c.i

CMakeFiles/reveal.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/main.c -o CMakeFiles/reveal.dir/src/main.c.s

CMakeFiles/reveal.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/main.c.o.requires

CMakeFiles/reveal.dir/src/main.c.o.provides: CMakeFiles/reveal.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/main.c.o.provides

CMakeFiles/reveal.dir/src/main.c.o.provides.build: CMakeFiles/reveal.dir/src/main.c.o


CMakeFiles/reveal.dir/src/utils/image.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/image.c.o: src/utils/image.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/reveal.dir/src/utils/image.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/image.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/image.c

CMakeFiles/reveal.dir/src/utils/image.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/image.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/image.c > CMakeFiles/reveal.dir/src/utils/image.c.i

CMakeFiles/reveal.dir/src/utils/image.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/image.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/image.c -o CMakeFiles/reveal.dir/src/utils/image.c.s

CMakeFiles/reveal.dir/src/utils/image.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/image.c.o.requires

CMakeFiles/reveal.dir/src/utils/image.c.o.provides: CMakeFiles/reveal.dir/src/utils/image.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/image.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/image.c.o.provides

CMakeFiles/reveal.dir/src/utils/image.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/image.c.o


CMakeFiles/reveal.dir/src/arguments.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/arguments.c.o: src/arguments.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/reveal.dir/src/arguments.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/arguments.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/arguments.c

CMakeFiles/reveal.dir/src/arguments.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/arguments.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/arguments.c > CMakeFiles/reveal.dir/src/arguments.c.i

CMakeFiles/reveal.dir/src/arguments.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/arguments.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/arguments.c -o CMakeFiles/reveal.dir/src/arguments.c.s

CMakeFiles/reveal.dir/src/arguments.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/arguments.c.o.requires

CMakeFiles/reveal.dir/src/arguments.c.o.provides: CMakeFiles/reveal.dir/src/arguments.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/arguments.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/arguments.c.o.provides

CMakeFiles/reveal.dir/src/arguments.c.o.provides.build: CMakeFiles/reveal.dir/src/arguments.c.o


CMakeFiles/reveal.dir/src/validateArguments.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/validateArguments.c.o: src/validateArguments.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/reveal.dir/src/validateArguments.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/validateArguments.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/validateArguments.c

CMakeFiles/reveal.dir/src/validateArguments.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/validateArguments.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/validateArguments.c > CMakeFiles/reveal.dir/src/validateArguments.c.i

CMakeFiles/reveal.dir/src/validateArguments.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/validateArguments.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/validateArguments.c -o CMakeFiles/reveal.dir/src/validateArguments.c.s

CMakeFiles/reveal.dir/src/validateArguments.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/validateArguments.c.o.requires

CMakeFiles/reveal.dir/src/validateArguments.c.o.provides: CMakeFiles/reveal.dir/src/validateArguments.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/validateArguments.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/validateArguments.c.o.provides

CMakeFiles/reveal.dir/src/validateArguments.c.o.provides.build: CMakeFiles/reveal.dir/src/validateArguments.c.o


CMakeFiles/reveal.dir/src/pattern/reveal.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/pattern/reveal.c.o: src/pattern/reveal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/reveal.dir/src/pattern/reveal.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/pattern/reveal.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/reveal.c

CMakeFiles/reveal.dir/src/pattern/reveal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/pattern/reveal.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/reveal.c > CMakeFiles/reveal.dir/src/pattern/reveal.c.i

CMakeFiles/reveal.dir/src/pattern/reveal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/pattern/reveal.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/reveal.c -o CMakeFiles/reveal.dir/src/pattern/reveal.c.s

CMakeFiles/reveal.dir/src/pattern/reveal.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/pattern/reveal.c.o.requires

CMakeFiles/reveal.dir/src/pattern/reveal.c.o.provides: CMakeFiles/reveal.dir/src/pattern/reveal.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/pattern/reveal.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/pattern/reveal.c.o.provides

CMakeFiles/reveal.dir/src/pattern/reveal.c.o.provides.build: CMakeFiles/reveal.dir/src/pattern/reveal.c.o


CMakeFiles/reveal.dir/src/pattern/direct.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/pattern/direct.c.o: src/pattern/direct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/reveal.dir/src/pattern/direct.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/pattern/direct.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/direct.c

CMakeFiles/reveal.dir/src/pattern/direct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/pattern/direct.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/direct.c > CMakeFiles/reveal.dir/src/pattern/direct.c.i

CMakeFiles/reveal.dir/src/pattern/direct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/pattern/direct.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/direct.c -o CMakeFiles/reveal.dir/src/pattern/direct.c.s

CMakeFiles/reveal.dir/src/pattern/direct.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/pattern/direct.c.o.requires

CMakeFiles/reveal.dir/src/pattern/direct.c.o.provides: CMakeFiles/reveal.dir/src/pattern/direct.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/pattern/direct.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/pattern/direct.c.o.provides

CMakeFiles/reveal.dir/src/pattern/direct.c.o.provides.build: CMakeFiles/reveal.dir/src/pattern/direct.c.o


CMakeFiles/reveal.dir/src/pattern/reverse.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/pattern/reverse.c.o: src/pattern/reverse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/reveal.dir/src/pattern/reverse.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/pattern/reverse.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/reverse.c

CMakeFiles/reveal.dir/src/pattern/reverse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/pattern/reverse.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/reverse.c > CMakeFiles/reveal.dir/src/pattern/reverse.c.i

CMakeFiles/reveal.dir/src/pattern/reverse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/pattern/reverse.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/pattern/reverse.c -o CMakeFiles/reveal.dir/src/pattern/reverse.c.s

CMakeFiles/reveal.dir/src/pattern/reverse.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/pattern/reverse.c.o.requires

CMakeFiles/reveal.dir/src/pattern/reverse.c.o.provides: CMakeFiles/reveal.dir/src/pattern/reverse.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/pattern/reverse.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/pattern/reverse.c.o.provides

CMakeFiles/reveal.dir/src/pattern/reverse.c.o.provides.build: CMakeFiles/reveal.dir/src/pattern/reverse.c.o


CMakeFiles/reveal.dir/src/decompress/decompress.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/decompress/decompress.c.o: src/decompress/decompress.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/reveal.dir/src/decompress/decompress.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/decompress/decompress.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/decompress/decompress.c

CMakeFiles/reveal.dir/src/decompress/decompress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/decompress/decompress.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/decompress/decompress.c > CMakeFiles/reveal.dir/src/decompress/decompress.c.i

CMakeFiles/reveal.dir/src/decompress/decompress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/decompress/decompress.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/decompress/decompress.c -o CMakeFiles/reveal.dir/src/decompress/decompress.c.s

CMakeFiles/reveal.dir/src/decompress/decompress.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/decompress/decompress.c.o.requires

CMakeFiles/reveal.dir/src/decompress/decompress.c.o.provides: CMakeFiles/reveal.dir/src/decompress/decompress.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/decompress/decompress.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/decompress/decompress.c.o.provides

CMakeFiles/reveal.dir/src/decompress/decompress.c.o.provides.build: CMakeFiles/reveal.dir/src/decompress/decompress.c.o


CMakeFiles/reveal.dir/src/decompress/dictionary.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/decompress/dictionary.c.o: src/decompress/dictionary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/reveal.dir/src/decompress/dictionary.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/decompress/dictionary.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/decompress/dictionary.c

CMakeFiles/reveal.dir/src/decompress/dictionary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/decompress/dictionary.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/decompress/dictionary.c > CMakeFiles/reveal.dir/src/decompress/dictionary.c.i

CMakeFiles/reveal.dir/src/decompress/dictionary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/decompress/dictionary.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/decompress/dictionary.c -o CMakeFiles/reveal.dir/src/decompress/dictionary.c.s

CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.requires

CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.provides: CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.provides

CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.provides.build: CMakeFiles/reveal.dir/src/decompress/dictionary.c.o


CMakeFiles/reveal.dir/src/utils/utilBit.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/utilBit.c.o: src/utils/utilBit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/reveal.dir/src/utils/utilBit.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/utilBit.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/utilBit.c

CMakeFiles/reveal.dir/src/utils/utilBit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/utilBit.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/utilBit.c > CMakeFiles/reveal.dir/src/utils/utilBit.c.i

CMakeFiles/reveal.dir/src/utils/utilBit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/utilBit.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/utilBit.c -o CMakeFiles/reveal.dir/src/utils/utilBit.c.s

CMakeFiles/reveal.dir/src/utils/utilBit.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/utilBit.c.o.requires

CMakeFiles/reveal.dir/src/utils/utilBit.c.o.provides: CMakeFiles/reveal.dir/src/utils/utilBit.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/utilBit.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/utilBit.c.o.provides

CMakeFiles/reveal.dir/src/utils/utilBit.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/utilBit.c.o


CMakeFiles/reveal.dir/src/utils/hexa.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/hexa.c.o: src/utils/hexa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/reveal.dir/src/utils/hexa.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/hexa.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/hexa.c

CMakeFiles/reveal.dir/src/utils/hexa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/hexa.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/hexa.c > CMakeFiles/reveal.dir/src/utils/hexa.c.i

CMakeFiles/reveal.dir/src/utils/hexa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/hexa.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/hexa.c -o CMakeFiles/reveal.dir/src/utils/hexa.c.s

CMakeFiles/reveal.dir/src/utils/hexa.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/hexa.c.o.requires

CMakeFiles/reveal.dir/src/utils/hexa.c.o.provides: CMakeFiles/reveal.dir/src/utils/hexa.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/hexa.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/hexa.c.o.provides

CMakeFiles/reveal.dir/src/utils/hexa.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/hexa.c.o


CMakeFiles/reveal.dir/src/utils/file.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/file.c.o: src/utils/file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/reveal.dir/src/utils/file.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/file.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/file.c

CMakeFiles/reveal.dir/src/utils/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/file.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/file.c > CMakeFiles/reveal.dir/src/utils/file.c.i

CMakeFiles/reveal.dir/src/utils/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/file.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/file.c -o CMakeFiles/reveal.dir/src/utils/file.c.s

CMakeFiles/reveal.dir/src/utils/file.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/file.c.o.requires

CMakeFiles/reveal.dir/src/utils/file.c.o.provides: CMakeFiles/reveal.dir/src/utils/file.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/file.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/file.c.o.provides

CMakeFiles/reveal.dir/src/utils/file.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/file.c.o


CMakeFiles/reveal.dir/src/utils/formatDetector.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/formatDetector.c.o: src/utils/formatDetector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/reveal.dir/src/utils/formatDetector.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/formatDetector.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/formatDetector.c

CMakeFiles/reveal.dir/src/utils/formatDetector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/formatDetector.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/formatDetector.c > CMakeFiles/reveal.dir/src/utils/formatDetector.c.i

CMakeFiles/reveal.dir/src/utils/formatDetector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/formatDetector.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/formatDetector.c -o CMakeFiles/reveal.dir/src/utils/formatDetector.c.s

CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.requires

CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.provides: CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.provides

CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/formatDetector.c.o


CMakeFiles/reveal.dir/src/utils/validateFormat.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/validateFormat.c.o: src/utils/validateFormat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/reveal.dir/src/utils/validateFormat.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/validateFormat.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validateFormat.c

CMakeFiles/reveal.dir/src/utils/validateFormat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/validateFormat.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validateFormat.c > CMakeFiles/reveal.dir/src/utils/validateFormat.c.i

CMakeFiles/reveal.dir/src/utils/validateFormat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/validateFormat.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validateFormat.c -o CMakeFiles/reveal.dir/src/utils/validateFormat.c.s

CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.requires

CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.provides: CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.provides

CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/validateFormat.c.o


CMakeFiles/reveal.dir/src/utils/validateChannels.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/validateChannels.c.o: src/utils/validateChannels.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/reveal.dir/src/utils/validateChannels.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/validateChannels.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validateChannels.c

CMakeFiles/reveal.dir/src/utils/validateChannels.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/validateChannels.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validateChannels.c > CMakeFiles/reveal.dir/src/utils/validateChannels.c.i

CMakeFiles/reveal.dir/src/utils/validateChannels.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/validateChannels.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validateChannels.c -o CMakeFiles/reveal.dir/src/utils/validateChannels.c.s

CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.requires

CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.provides: CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.provides

CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/validateChannels.c.o


CMakeFiles/reveal.dir/src/utils/validatePattern.c.o: CMakeFiles/reveal.dir/flags.make
CMakeFiles/reveal.dir/src/utils/validatePattern.c.o: src/utils/validatePattern.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/reveal.dir/src/utils/validatePattern.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reveal.dir/src/utils/validatePattern.c.o   -c /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validatePattern.c

CMakeFiles/reveal.dir/src/utils/validatePattern.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reveal.dir/src/utils/validatePattern.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validatePattern.c > CMakeFiles/reveal.dir/src/utils/validatePattern.c.i

CMakeFiles/reveal.dir/src/utils/validatePattern.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reveal.dir/src/utils/validatePattern.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Raquel/Desktop/NSA/private/revelation/src/utils/validatePattern.c -o CMakeFiles/reveal.dir/src/utils/validatePattern.c.s

CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.requires:

.PHONY : CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.requires

CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.provides: CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.requires
	$(MAKE) -f CMakeFiles/reveal.dir/build.make CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.provides.build
.PHONY : CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.provides

CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.provides.build: CMakeFiles/reveal.dir/src/utils/validatePattern.c.o


# Object files for target reveal
reveal_OBJECTS = \
"CMakeFiles/reveal.dir/src/main.c.o" \
"CMakeFiles/reveal.dir/src/utils/image.c.o" \
"CMakeFiles/reveal.dir/src/arguments.c.o" \
"CMakeFiles/reveal.dir/src/validateArguments.c.o" \
"CMakeFiles/reveal.dir/src/pattern/reveal.c.o" \
"CMakeFiles/reveal.dir/src/pattern/direct.c.o" \
"CMakeFiles/reveal.dir/src/pattern/reverse.c.o" \
"CMakeFiles/reveal.dir/src/decompress/decompress.c.o" \
"CMakeFiles/reveal.dir/src/decompress/dictionary.c.o" \
"CMakeFiles/reveal.dir/src/utils/utilBit.c.o" \
"CMakeFiles/reveal.dir/src/utils/hexa.c.o" \
"CMakeFiles/reveal.dir/src/utils/file.c.o" \
"CMakeFiles/reveal.dir/src/utils/formatDetector.c.o" \
"CMakeFiles/reveal.dir/src/utils/validateFormat.c.o" \
"CMakeFiles/reveal.dir/src/utils/validateChannels.c.o" \
"CMakeFiles/reveal.dir/src/utils/validatePattern.c.o"

# External object files for target reveal
reveal_EXTERNAL_OBJECTS =

reveal: CMakeFiles/reveal.dir/src/main.c.o
reveal: CMakeFiles/reveal.dir/src/utils/image.c.o
reveal: CMakeFiles/reveal.dir/src/arguments.c.o
reveal: CMakeFiles/reveal.dir/src/validateArguments.c.o
reveal: CMakeFiles/reveal.dir/src/pattern/reveal.c.o
reveal: CMakeFiles/reveal.dir/src/pattern/direct.c.o
reveal: CMakeFiles/reveal.dir/src/pattern/reverse.c.o
reveal: CMakeFiles/reveal.dir/src/decompress/decompress.c.o
reveal: CMakeFiles/reveal.dir/src/decompress/dictionary.c.o
reveal: CMakeFiles/reveal.dir/src/utils/utilBit.c.o
reveal: CMakeFiles/reveal.dir/src/utils/hexa.c.o
reveal: CMakeFiles/reveal.dir/src/utils/file.c.o
reveal: CMakeFiles/reveal.dir/src/utils/formatDetector.c.o
reveal: CMakeFiles/reveal.dir/src/utils/validateFormat.c.o
reveal: CMakeFiles/reveal.dir/src/utils/validateChannels.c.o
reveal: CMakeFiles/reveal.dir/src/utils/validatePattern.c.o
reveal: CMakeFiles/reveal.dir/build.make
reveal: /usr/local/lib/libopencv_videostab.3.0.0.dylib
reveal: /usr/local/lib/libopencv_superres.3.0.0.dylib
reveal: /usr/local/lib/libopencv_stitching.3.0.0.dylib
reveal: /usr/local/lib/libopencv_shape.3.0.0.dylib
reveal: /usr/local/lib/libopencv_photo.3.0.0.dylib
reveal: /usr/local/lib/libopencv_objdetect.3.0.0.dylib
reveal: /usr/local/lib/libopencv_hal.a
reveal: /usr/local/lib/libopencv_calib3d.3.0.0.dylib
reveal: /usr/local/lib/libopencv_features2d.3.0.0.dylib
reveal: /usr/local/lib/libopencv_ml.3.0.0.dylib
reveal: /usr/local/lib/libopencv_highgui.3.0.0.dylib
reveal: /usr/local/lib/libopencv_videoio.3.0.0.dylib
reveal: /usr/local/lib/libopencv_imgcodecs.3.0.0.dylib
reveal: /usr/local/lib/libopencv_flann.3.0.0.dylib
reveal: /usr/local/lib/libopencv_video.3.0.0.dylib
reveal: /usr/local/lib/libopencv_imgproc.3.0.0.dylib
reveal: /usr/local/lib/libopencv_core.3.0.0.dylib
reveal: /usr/local/lib/libopencv_hal.a
reveal: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
reveal: CMakeFiles/reveal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable reveal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reveal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reveal.dir/build: reveal

.PHONY : CMakeFiles/reveal.dir/build

CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/main.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/image.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/arguments.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/validateArguments.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/pattern/reveal.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/pattern/direct.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/pattern/reverse.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/decompress/decompress.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/decompress/dictionary.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/utilBit.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/hexa.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/file.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/formatDetector.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/validateFormat.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/validateChannels.c.o.requires
CMakeFiles/reveal.dir/requires: CMakeFiles/reveal.dir/src/utils/validatePattern.c.o.requires

.PHONY : CMakeFiles/reveal.dir/requires

CMakeFiles/reveal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reveal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reveal.dir/clean

CMakeFiles/reveal.dir/depend:
	cd /Users/Raquel/Desktop/NSA/private/revelation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Raquel/Desktop/NSA/private/revelation /Users/Raquel/Desktop/NSA/private/revelation /Users/Raquel/Desktop/NSA/private/revelation /Users/Raquel/Desktop/NSA/private/revelation /Users/Raquel/Desktop/NSA/private/revelation/CMakeFiles/reveal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reveal.dir/depend

