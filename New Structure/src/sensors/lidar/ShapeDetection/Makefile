#the name of the output file (withoud .exe)

PROG = main
# the needed cpp files (withoud .cpp)
MODULES := main shapedetector

# the deps directory
DEPS_DIR_WIN:= ..\..\deps
DEPS_DIR_LINUX:= ../../deps

HEADER := $(patsubst %,%.h,$(MODULES))

OBJECTS := $(patsubst %,%.o,$(MODULES))


ifeq ($(OS),Windows_NT)
	gcc = g++
	LINKFLAGS = -L$(DEPS_DIR_WIN)\libs\opencv\windows  -lopencv_core2410 -lopencv_highgui2410 -lopencv_imgproc2410
	rm = del
	TARGET := $(PROG).exe
	CFLAGS = -std=c++11   -I$(DEPS_DIR_WIN)\files\opencv

else
	ARCH := $(shell getconf LONG_BIT)
	CPP_FLAGS_32 := $(DEPS_DIR_LINUX)/libs/Linux/x86	
	CPP_FLAGS_64 := $(DEPS_DIR_LINUX)/libs/Linux/x64
	LINKFLAGS := -L$(CPP_FLAGS_$(ARCH)) -lopencv_core -lopencv_highgui -lopencv_imgproc -Wl,-rpath=$(CPP_FLAGS_$(ARCH))	
	gcc := /usr/bin/g++
	CFLAGS = -std=c++11   -I$(DEPS_DIR_LINUX)/files/opencv
	rm := rm -f
	TARGET := $(PROG)
endif
.PHONY: build clean

build:	$(TARGET) 
	
clean:		
	$(rm) $(TARGET) $(OBJECTS)

$(OBJECTS): %.o : $(HEADERS) %.cpp
	$(gcc) -c  -o  $@  $< $(CFLAGS)
$(TARGET): $(OBJECTS) 
	$(gcc)  $(OBJECTS) -o $@ $(LINKFLAGS) $(CFLAGS)  

