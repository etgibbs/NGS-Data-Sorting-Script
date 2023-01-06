CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++11 -Wno-sign-compare -Wno-comment


# Compile the main executable
main.exe: Script.cpp Script.h
	$(CXX) $(CXXFLAGS) Script.cpp Script.h -o main.exe


# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
