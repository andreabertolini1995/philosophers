NAME = philo
SOURCES = main.c threads.c routine.c utils.c
OBJS = $(SOURCES:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
THREAD_FLAGS = -fsanitize=thread -pthread

all: $(NAME)	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREAD_FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)