EXENAME = finalproj
OBJS = graph.o readFromFile.o main.o prims.o landmark.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

landmark.o: landmark.cpp landmark.h
	$(CXX) $(CXXFLAGS) landmark.cpp

graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp

prims.o: prims.cpp prims.h
	$(CXX) $(CXXFLAGS) prims.cpp

main.o: main.cpp graph.h readFromFile.h prims.h landmark.h
	$(CXX) $(CXXFLAGS) main.cpp

readFromFile.o: readFromFile.h readFromFile.cpp
	$(CXX) $(CXXFLAGS) readFromFile.cpp

test: output_msg tests/catch/catchmain.cpp tests/tests.cpp readFromFile.cpp
	$(LD) tests/catch/catchmain.cpp tests/tests.cpp readFromFile.cpp $(LDFLAGS) -o test

tests.o: tests/tests.cpp tests/catch/catch.hpp readFromFile.cpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean:
	-rm -f *.o $(EXENAME) test