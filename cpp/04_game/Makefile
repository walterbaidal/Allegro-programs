CXX = g++
CXXFLAGS = -g
LDLIBS = -lallegro -lallegro_image -lallegro_dialog

DEPS = mi_allegro.h 
OBJ = mi_allegro.o  bird.o

bird: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	$(RM) *.o *~
