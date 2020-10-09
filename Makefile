BUILDDIR = ./build
INCDIR = ./include
SRCDIR = ./src
TESTDIR = ./tests

TEST_INCPATH = /usr/local/Cellar/unittest-cpp/2.0.0/include/UnitTest++/
TEST_LIBPATH = /usr/local/Cellar/unittest-cpp/2.0.0/lib/
TEST_LIB = UnitTest++

SRCS = $(shell find $(SRCDIR) -name '*.cpp')
TESTS = $(shell find . -name '*.cpp' | grep -v "src/main.cpp")

CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -I$(INCDIR)
TEST_LIB_FLAGS = -L$(TEST_LIBPATH) -I$(TEST_INCPATH) -l$(TEST_LIB)

CXX = g++

artbot: $(SRCS)
	$(shell mkdir -p $(BUILDDIR))
	$(CXX) $^ $(CXXFLAGS) -o $(BUILDDIR)/$@

test: $(TESTS)
	$(shell mkdir -p $(BUILDDIR))
	$(CXX) $^ $(CXXFLAGS) $(TEST_LIB_FLAGS) -o $(BUILDDIR)/$@

.PHONY: clean
clean:
	$(RM) $(BUILDDIR)/artbot
