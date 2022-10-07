CC = gcc
CFLAGS = -g
DEPS = header.h
OBJ = main.o functions.o
    
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
      
bard: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f bard