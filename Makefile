NAME = get_next_line.a
SRCS = $(shell find . -name "g*.c")
OBJS = $(SRCS:.c=.o)
all:

	gcc -D BUFFER_SIZE=42 -c -g $(SRCS)
	ar rc $(NAME) $(OBJS)
fclean :
	rm -rf *.o $(NAME)