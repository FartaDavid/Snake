CC = gcc
CFLAGS = -g -Wall -Werror
target = main.c printing.c moving.c others.c
name = snake

all: snake

snake: $(target)
	$(CC) $(CFLAGS) $(target) -o $(name)

clean:
	rm -f $(name)