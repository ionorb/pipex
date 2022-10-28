LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	pipex.c finish.c children.c get_next_line.c

SOURCES_DIR		=	./sources

HEADER			=	$(SOURCES_DIR)/pipex.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

MAKE			=	make

NAME			=	pipex

BONUS			=	bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-g3 -Wall -Wextra -Werror -D BUFFER_SIZE=100

.c.o:		
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME) $(BONUS)

$(NAME):	$(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(HEADER) -o $(NAME)

$(BONUS):	$(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(HEADER) -o $(BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJECTS)

fclean:		clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	$(RM) outfile

re:			fclean all

.PHONY:		all clean fclean re libft
