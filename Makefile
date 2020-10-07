BUILDDIR = ./build
INCDIR = ./include
INCPATH = /usr/local/Cellar/unittest-cpp/2.0.0/include/UnitTest++/
SRCDIR = ./src
LIBPATH = /usr/local/Cellar/unittest-cpp/2.0.0/lib/
LIB = UnitTest++

SRCS = $(shell find . -name '*.cpp')

CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -L$(LIBPATH) -I$(INCPATH) -l$(LIB) -I$(INCDIR)

CXX = g++

artbot: $(SRCS)
	$(shell mkdir -p $(BUILDDIR))
	$(CXX) $^ $(CXXFLAGS) -o $(BUILDDIR)/$@

.PHONY: clean
clean:
	$(RM) $(BUILDDIR)/artbot
