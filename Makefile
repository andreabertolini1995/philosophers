NAME = philo
SOURCES = main.c
OBJS = $(SOURCES:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	make -C clean
	$(RM) $(OBJS)

fclean: clean
	make -C clean
	$(RM) $(NAME)

re: fclean $(NAME)