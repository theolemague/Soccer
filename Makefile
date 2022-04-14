CXX 	 := c++

SRCDIR   := ./src
BUILDDIR := ./build
OBJDIR   := $(BUILDDIR)/objects
APPDIR   := $(BUILDDIR)/app
INCLUDE  := -Iinclude/


SRCFILES := $(wildcard src/*.cpp)
OBJFILES := $(SRCFILES:%.cpp=$(OBJDIR)/%.o)
OUT      := main

CFLAGS = -Wall
LDLIBS = -lstdc++ -lm -lsfml-window -lsfml-graphics -lsfml-network -lsfml-system -lsfml-audio

all: build $(APPDIR)/$(OUT)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APPDIR)/$(OUT): $(OBJFILES)
	mkdir -p $(@D)
	$(CXX) $(CFLAGS) $^ -o $(APPDIR)/$(OUT) $(LDLIBS) 

build:
	mkdir -p $(BUILDDIR)
	mkdir -p $(APPDIR)
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: run
run:
	./build/app/main