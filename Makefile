all: linux linux32 windows windows32
all64: linux windows
all32: linux32 windows32
linux: bn
linux32: bn32
linux64: linux
windows: bn.exe
windows32: bn32.exe
windows64: windows

bn: bandnames.cpp
	g++ --std=c++0x -O2 -o $@ bandnames.cpp
bn-debug: bandnames.cpp
	g++ --std=c++0x -g -o $@ bandnames.cpp
bn32: bandnames.cpp
	g++ -m32 --std=c++0x -O2 -o $@ bandnames.cpp
bn.exe: bandnames.cpp
	x86_64-w64-mingw32-g++ --std=c++0x -O2 -static -DWIN32 -o $@ bandnames.cpp
bn32.exe: bandnames.cpp
	i686-w64-mingw32-g++ --std=c++0x -O2 -static -DWIN32 -o $@ bandnames.cpp
clean:
	rm -f bn bn-debug bn.exe bn32.exe bn32
.PHONY: clean all all32 all64 windows windows32 windows64 linux linux32 linux64

