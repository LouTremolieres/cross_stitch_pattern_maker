# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\loutr\OneDrive\Desktop\code point de croix"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\loutr\OneDrive\Desktop\code point de croix\build"

# Include any dependencies generated for this target.
include dep/glm/glm/CMakeFiles/glm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dep/glm/glm/CMakeFiles/glm.dir/compiler_depend.make

# Include the progress variables for this target.
include dep/glm/glm/CMakeFiles/glm.dir/progress.make

# Include the compile flags for this target's objects.
include dep/glm/glm/CMakeFiles/glm.dir/flags.make

dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.obj: dep/glm/glm/CMakeFiles/glm.dir/flags.make
dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.obj: dep/glm/glm/CMakeFiles/glm.dir/includes_CXX.rsp
dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.obj: C:/Users/loutr/OneDrive/Desktop/code\ point\ de\ croix/dep/glm/glm/detail/glm.cpp
dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.obj: dep/glm/glm/CMakeFiles/glm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\loutr\OneDrive\Desktop\code point de croix\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.obj"
	cd /d C:\Users\loutr\OneDrive\Desktop\CODEPO~1\build\dep\glm\glm && C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.obj -MF CMakeFiles\glm.dir\detail\glm.cpp.obj.d -o CMakeFiles\glm.dir\detail\glm.cpp.obj -c "C:\Users\loutr\OneDrive\Desktop\code point de croix\dep\glm\glm\detail\glm.cpp"

dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/glm.dir/detail/glm.cpp.i"
	cd /d C:\Users\loutr\OneDrive\Desktop\CODEPO~1\build\dep\glm\glm && C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\loutr\OneDrive\Desktop\code point de croix\dep\glm\glm\detail\glm.cpp" > CMakeFiles\glm.dir\detail\glm.cpp.i

dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/glm.dir/detail/glm.cpp.s"
	cd /d C:\Users\loutr\OneDrive\Desktop\CODEPO~1\build\dep\glm\glm && C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\loutr\OneDrive\Desktop\code point de croix\dep\glm\glm\detail\glm.cpp" -o CMakeFiles\glm.dir\detail\glm.cpp.s

# Object files for target glm
glm_OBJECTS = \
"CMakeFiles/glm.dir/detail/glm.cpp.obj"

# External object files for target glm
glm_EXTERNAL_OBJECTS =

dep/glm/glm/libglm.a: dep/glm/glm/CMakeFiles/glm.dir/detail/glm.cpp.obj
dep/glm/glm/libglm.a: dep/glm/glm/CMakeFiles/glm.dir/build.make
dep/glm/glm/libglm.a: dep/glm/glm/CMakeFiles/glm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\loutr\OneDrive\Desktop\code point de croix\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libglm.a"
	cd /d C:\Users\loutr\OneDrive\Desktop\CODEPO~1\build\dep\glm\glm && $(CMAKE_COMMAND) -P CMakeFiles\glm.dir\cmake_clean_target.cmake
	cd /d C:\Users\loutr\OneDrive\Desktop\CODEPO~1\build\dep\glm\glm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dep/glm/glm/CMakeFiles/glm.dir/build: dep/glm/glm/libglm.a
.PHONY : dep/glm/glm/CMakeFiles/glm.dir/build

dep/glm/glm/CMakeFiles/glm.dir/clean:
	cd /d C:\Users\loutr\OneDrive\Desktop\CODEPO~1\build\dep\glm\glm && $(CMAKE_COMMAND) -P CMakeFiles\glm.dir\cmake_clean.cmake
.PHONY : dep/glm/glm/CMakeFiles/glm.dir/clean

dep/glm/glm/CMakeFiles/glm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\loutr\OneDrive\Desktop\code point de croix" "C:\Users\loutr\OneDrive\Desktop\code point de croix\dep\glm\glm" "C:\Users\loutr\OneDrive\Desktop\code point de croix\build" "C:\Users\loutr\OneDrive\Desktop\code point de croix\build\dep\glm\glm" "C:\Users\loutr\OneDrive\Desktop\code point de croix\build\dep\glm\glm\CMakeFiles\glm.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : dep/glm/glm/CMakeFiles/glm.dir/depend

