XX = g++
CXXFLAGS = `root-config --cflags` -I./header -g
LDFLAGS = `root-config --glibs`

#target and source file
TARGET = analysis
SOURCES = main.cpp src/makeGate.cpp src/makeGraph.cpp src/save.cpp
OBJECTS = $(SOURCES:.cpp=.o)

#defualt target
all: $(TARGET)

#Link step
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

#compilestep
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#clean up
clean:
	rm -f $(TARGET) $(OBJECTS)

