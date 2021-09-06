CXXFLAGS += -std=c++14

CPPFLAGS += 


SOURCES := $(shell find . -name '*.cpp')

# find headers
HEADERS := $(shell find . -name '*.h')

OUTPUT := vradiboh

all: $(OUTPUT)
$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	$(RM) $(OUTPUT)
doc:
	@doxygen Doxyfile
compile: $(OUTPUT)
$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(OUTPUT) $(SOURCES)

run: $(OUTPUT)
	./$(OUTPUT)