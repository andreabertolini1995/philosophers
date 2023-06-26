NAME = philo
SOURCES = main.c init.c threads.c routines.c utils.c philo_actions.c philo_actions_2.c
OBJS = $(SOURCES:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
THREAD_FLAGS = -fsanitize=thread -pthread
LEAKS_FLAGS =  -fsanitize=address -fno-omit-frame-pointer

all: $(NAME)	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LEAKS_FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)