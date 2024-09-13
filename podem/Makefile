.PHONY: all clean

CXX = g++
LINKER = g++
CXX_FLAG = -O2 -Wall -DDEBUG -DDEBUG_ATPG -g
INCLUDE_PATH =
LIBRARY = -lreadline -lcurses

####### Files

HEADERS = gate.h fault.h circuit.h GetLongOpt.h typeemu.h readcircuit.tab.h ReadPattern.h hash.h tfault.h

SOURCES = readcircuit.tab.cc lex.yy.cc circuit.cc main.cc GetLongOpt.cc atpg.cc fsim.cc sim.cc psim.cc stfsim.cc tfatpg.cc

OBJECTS = readcircuit.tab.o lex.yy.o circuit.o main.o GetLongOpt.o atpg.o fsim.o sim.o psim.o stfsim.o tfatpg.o

TARGET = atpg

####### Implicit rules

.SUFFIXES: .o .cpp .cc .cxx

.cpp.o:
	$(CXX) -c $(CXX_FLAG) $(INCLUDE_PATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXX_FLAG) $(INCLUDE_PATH) -o $@ $<

####### Build rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINKER) $(CXX_FLAG) -o $(TARGET) $(OBJECTS) $(LIBRARY) $(INCLUDE_PATH)

$(OBJECTS): $(HEADERS) Makefile

readcircuit.tab.cc: readcircuit.y gate.h circuit.h
	bison -d -t readcircuit.y
	mv readcircuit.tab.c readcircuit.tab.cc

lex.yy.cc: readcircuit.l readcircuit.y
	flex readcircuit.l 
	mv lex.yy.c lex.yy.cc

clean:
	rm -rf $(OBJECTS) $(TARGET)
	rm -rf readcircuit.tab.cc readcircuit.tab.h lex.yy.cc


