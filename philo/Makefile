NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm -rf

SRCS =	./src/main.c \
		./src/itoa.c \
		./src/parsing.c \
		./src/error.c \
		./src/init.c \
		./src/routine.c \

SRCDIR = src/
OBJS = $(SRCS:$(SRCDIR)%.c=%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all
