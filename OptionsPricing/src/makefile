# Last updated: 06/06/2020

CC = g++
CPPFLAGS = -g -Wall -std=c++11


SOURCES = main.cpp Option.cpp pricingFunctions.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = TARGET

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	make clean

.PHONY: clean

clean:
	rm -f $(OBJECTS) core
