CC = gcc
CFLAGS = -g -Wall -Werror
target = main.c start.c moving.c

all: snake

snake: $(target)
	$(CC) $(CFLAGS) $(target) -o snake

clean:
	rm -f snake