

CC = gcc
CFLAGS = -g -O0
RM = rm

OBJS = rbtree.o rbtree_main.o
TARGET = rbtree_main.exe

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

clean: 	
	$(RM) -rf *.o *.exe
