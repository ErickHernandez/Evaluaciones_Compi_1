# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build"

# Include any dependencies generated for this target.
include CMakeFiles/test_parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_parser.dir/flags.make

expr_slr_table.cpp: /home/alxhdz/Documents/Universidad/Compiladores\ I/Evaluaciones_Compi_1/Prueba3_P2_2020/grammar_slr.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Generating expr_slr_table.cpp, expr_slr_table.h"
	ecc --hdr expr_slr_table.h --src expr_slr_table.cpp -g /home/alxhdz/Documents/Universidad/Compiladores\ I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests/../grammar_slr.txt --alg slr

expr_slr_table.h: expr_slr_table.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate expr_slr_table.h

CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.o: CMakeFiles/test_parser.dir/flags.make
CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.o: /home/alxhdz/Documents/Universidad/Compiladores\ I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.o -c "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp"

CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp" > CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.i

CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp" -o CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.s

CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.o: CMakeFiles/test_parser.dir/flags.make
CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.o: /home/alxhdz/Documents/Universidad/Compiladores\ I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.o -c "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp"

CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp" > CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.i

CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp" -o CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.s

CMakeFiles/test_parser.dir/expr_slr_table.cpp.o: CMakeFiles/test_parser.dir/flags.make
CMakeFiles/test_parser.dir/expr_slr_table.cpp.o: expr_slr_table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test_parser.dir/expr_slr_table.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parser.dir/expr_slr_table.cpp.o -c "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/expr_slr_table.cpp"

CMakeFiles/test_parser.dir/expr_slr_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parser.dir/expr_slr_table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/expr_slr_table.cpp" > CMakeFiles/test_parser.dir/expr_slr_table.cpp.i

CMakeFiles/test_parser.dir/expr_slr_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parser.dir/expr_slr_table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/expr_slr_table.cpp" -o CMakeFiles/test_parser.dir/expr_slr_table.cpp.s

CMakeFiles/test_parser.dir/test_parser.cpp.o: CMakeFiles/test_parser.dir/flags.make
CMakeFiles/test_parser.dir/test_parser.cpp.o: /home/alxhdz/Documents/Universidad/Compiladores\ I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests/test_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test_parser.dir/test_parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parser.dir/test_parser.cpp.o -c "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests/test_parser.cpp"

CMakeFiles/test_parser.dir/test_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parser.dir/test_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests/test_parser.cpp" > CMakeFiles/test_parser.dir/test_parser.cpp.i

CMakeFiles/test_parser.dir/test_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parser.dir/test_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests/test_parser.cpp" -o CMakeFiles/test_parser.dir/test_parser.cpp.s

# Object files for target test_parser
test_parser_OBJECTS = \
"CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.o" \
"CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.o" \
"CMakeFiles/test_parser.dir/expr_slr_table.cpp.o" \
"CMakeFiles/test_parser.dir/test_parser.cpp.o"

# External object files for target test_parser
test_parser_EXTERNAL_OBJECTS =

test_parser: CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_parser.cpp.o
test_parser: CMakeFiles/test_parser.dir/home/alxhdz/Documents/Universidad/Compiladores_I/Evaluaciones_Compi_1/Prueba3_P2_2020/expr_lexer.cpp.o
test_parser: CMakeFiles/test_parser.dir/expr_slr_table.cpp.o
test_parser: CMakeFiles/test_parser.dir/test_parser.cpp.o
test_parser: CMakeFiles/test_parser.dir/build.make
test_parser: CMakeFiles/test_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable test_parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_parser.dir/build: test_parser

.PHONY : CMakeFiles/test_parser.dir/build

CMakeFiles/test_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_parser.dir/clean

CMakeFiles/test_parser.dir/depend: expr_slr_table.cpp
CMakeFiles/test_parser.dir/depend: expr_slr_table.h
	cd "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests" "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/tests" "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build" "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build" "/home/alxhdz/Documents/Universidad/Compiladores I/Evaluaciones_Compi_1/Prueba3_P2_2020/build/CMakeFiles/test_parser.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_parser.dir/depend
