#Documented to demonstrate use of unit testing in cpp.
#@Author Halil Sen

#Compile options
CXXFLAGS ?=
CCFLAGS ?= 
#variables
objects = unit_testing

#If there is no option given with make command, first method runs.
#make
#In this case all: will execute
all: executable

#new option method for debug
#example use
#make debug
debug: CXXFLAGS += -g -DDEBUG
debug: CCFLAGS += -g -DDEBUG
debug: executable

executable: $(objects)
	g++ $(CXXFLAGS) -o $(objects) unit_testing.cpp -I.

# @ operator is using for silent mode while makefile run commands.
clean: 
	@rm $(objects)
	@echo Clean done.
	

