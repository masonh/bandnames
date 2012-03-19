bn:
	g++ --std=c++0x -O2 -o bn bandnames.cpp
bn-debug:
	g++ --std=c++0x -g -o bn-debug bandnames.cpp
clean:
	rm -f bn bn-debug
.PHONY: clean
