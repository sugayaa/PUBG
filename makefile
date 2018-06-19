CXX = gcc
OUT = PUBG

src = *.c src/*.c
incl = *.h include/*.h

CXXFLAGS = -Wall
LIBS = -lallegro

install: compile

compile: depend
	$(CXX) -o $(OUT) $^ $(CXXFLAGS) $(LIBS)

depend:
	$(CXX) $(src) $(CXXFLAGS) $(LIBS)

remove:
	@rm -f $(OUT)
