XX = g++
CXXFLAGS = `root-config --cflags` -I./header -g
LDFLAGS = `root-config --glibs`

#target and source file
TARGET = ./bin/Analysis
SOURCES = $(wildcard ./src/*.cpp)
OBJDIR = ./obj
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

#defualt target
all: $(TARGET)

#Link step
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

#compilestep
$(OBJDIR)/%.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@mkdir -p $(dir $@)  
		$(XX) $(CXXFLAGS) -c -o $@ $<

#clean up
clean:
	rm -f $(TARGET) $(OBJDIR)/*.o ./bin/Analysis

