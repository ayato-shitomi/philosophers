NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-lpthread
THDBG		=	-fsanitize=thread
ADDBG		=	-fsanitize=address -fsanitize=leak
CINC	=	./includes

SRCS	=	init.c \
			launcher.c \
			main.c \
			print.c \
			utils.c \
			header_usage.c

all:	$(NAME)

$(NAME)	:
	$(CC) -I$(CINC) $(SRCS) $(CFLAGS) $(INCLUDE) -o $(NAME)

clean	:
	rm -f $(NAME)

fclean	:	clean

re		:	fclean all

thread	:	fclean
	$(CC) -I$(CINC) $(SRCS) $(CFLAGS) $(THDBG) $(INCLUDE) -o $(NAME)

memory	:	fclean
	$(CC) -I$(CINC) $(SRCS) $(CFLAGS) $(ADDBG) $(INCLUDE) -o $(NAME)

.PHONY: clean fclean re thread memory