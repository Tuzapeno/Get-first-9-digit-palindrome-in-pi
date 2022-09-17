CC = g++
CFLAGS = -g -Wall -Wextra -O3

# ---------------------------------------

source = $(wildcard *.cpp)
objects = $(source:.cpp=.o)
exec = palindrome

# ---------------------------------------

.PHONY: clean purge

# ---------------------------------------

$(exec): $(objects)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(objects)

purge:
	rm -f $(objects) $(exec)