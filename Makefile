CXX = g++
CXXFLAGS = -std=c++17 -Wall -pedantic -Wno-long-long -O0 -ggdb
EXECUTABLE = knapejar
SOURCES := $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
CHECK = valgrind
CHECKFLAGS = --leak-check=full --tool=memcheck
LDFLAGS = -lncursesw -lstdc++fs

## Colors

COLOR_DEFAULT = \033[0m
COLOR_STATUS = \033[1;33m
COLOR_INFO = \033[1;36m
COLOR_GOOD = \033[1;32m
COLOR_BAD = \033[1;31m
COLOR_WARN = \033[1;35m
COLOR_ERROR = \033[1;31m
COLOR_DEBUG = \033[1;34m
COLOR_HEADER = \033[1;37m
COLOR_UNDERLINE = \033[4m
COLOR_BLINK = \033[5m
COLOR_INVERT = \033[7m
COLOR_HIDDEN = \033[8m
COLOR_STRIKE = \033[9m

## Targets

%.o: %.cpp
	@echo "$(COLOR_STATUS)$^ -> $@$(COLOR_DEFAULT)"
	@$(CXX) $(CXXFLAGS) -c -o $@ -c $< $(LDFLAGS)
	@$(CXX) $(CXXFLAGS) -MM -MT $*.o $*.cpp $(LDFLAGS) > $*.d

all: doc compile

compile: $(SOURCES:.cpp=.o)
	@echo "$(COLOR_INFO)compiling with flags $(COLOR_DEFAULT)$(CXXFLAGS) $(LDFLAGS)"
	@$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE) $(LDFLAGS)
	@echo "$(COLOR_GOOD)COMPILE OK$(COLOR_DEFAULT)"

run: compile
	@echo "$(COLOR_INFO)$(COLOR_RESET)starting executable$(COLOR_DEFAULT)"
	@./$(EXECUTABLE)
	@echo "$(COLOR_GOOD)$(COLOR_INVERT)RUN OK$(COLOR_DEFAULT)"

## Documentation

doc:
	@echo "$(COLOR_INFO)$(COLOR_INVERT)generating documentation$(COLOR_DEFAULT)"
	doxygen Doxyfile
	@echo "$(COLOR_GOOD)$(COLOR_INVERT)DOC OK$(COLOR_DEFAULT)"

clean:
	@echo "$(COLOR_INFO)removing object files$(COLOR_DEFAULT)"
	@rm -f -- src/*.o src/*/*.o src/*/*/*.o
	@echo "$(COLOR_INFO)removing link files$(COLOR_DEFAULT)"
	@rm -f -- src/*.d src/*/*.d src/*/*/*.d
	@echo "$(COLOR_INFO)removing executable files$(COLOR_DEFAULT)"
	@rm -f $(EXECUTABLE)
	@echo "$(COLOR_INFO)removing documentation files$(COLOR_DEFAULT)"
	@rm -rf -- doc/
	@echo "$(COLOR_GOOD)CLEAN OK$(COLOR_DEFAULT)"