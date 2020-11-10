BS = build/

S = src/

OG = bin/avltree

OBJS = $(BS)main.o $(BS)avl.o

.PHONY: all clean re

all: $(OG)
re: clean all
	
$(BS)main.o: $(S)main.c
	gcc $^ -c -o $@
	
$(BS)avl.o: $(S)avl.c
	gcc $^ -c -o $@
	
$(OG): $(OBJS)
	gcc $^ -o $(OG)
	
clean:
	rm -f $(BS)*.o $(OG) 
