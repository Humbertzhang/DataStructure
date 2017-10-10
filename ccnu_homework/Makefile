TARGET = list-link
SRC = main.cpp list-link.cpp
OBJS = $(SRC:.c=.o)
CC = g++
INCLUDE = -l/usr/include/ -l/user/include/ncurses .
LINKPARAM = -lpthread -lncurses
CFLAGS = -ansi -g -Wall
all:$(TARGET)
$(TARGET):$(OBJS)
    $(CC) -o $(TARGET) $(LINKPARAM) $(OBJS)
.SUFFIXES:.c
.c.o:
$(CC)$(LINKPARAM)$(INCLUDE)$(CFLAGS)-c$<

clean:
rm$(OBJS)$(TARGET)
