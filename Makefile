NAME		= 	pipex

SRCS		= 	pipex.c

HEADER		=	pipex.h

OBJS		= 	$(SRCS:.c=.o)

CC			= 	gcc

CCFLAGS 	= 	-Wall -Wextra -Werror

.c.o:
		$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(CCFLAGS) $(OBJS) $(HEADER) -o $(NAME) 

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
