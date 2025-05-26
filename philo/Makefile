NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRCS =	./src/main.c \

SRCDIR = src/
OBJS = $(SRCS:$(SRCDIR)%.c=%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean

fclean:
	$(RM) $(NAME)

re: fclean all
