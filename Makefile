LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	pipex.c finish.c children.c

BONUS_FILES		=	pipex_bonus.c finish_bonus.c children_bonus.c

SOURCES_DIR		=	./sources

BONUS_DIR		=	./bonus_srcs

HEADER			=	$(SOURCES_DIR)/pipex.h

BONUS_HEADER	=	$(BONUS_DIR)/pipex_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

BONUS_SOURCES	=	$(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

BONUS_OBJECTS	=	$(BONUS_SOURCES:.c=.o)

MAKE			=	make

NAME			=	pipex

BONUS			=	bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-g3 -fsanitize=address -Wall -Wextra -Werror -D BUFFER_SIZE=100

.c.o:		
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME) $(BONUS)

$(NAME):	$(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(HEADER) -o $(NAME)

$(BONUS):	$(LIBFT) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) $(BONUS_HEADER) -o $(BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJECTS)
	$(RM) $(BONUS_OBJECTS)

fclean:		clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	$(RM) outfile

re:			fclean all

.PHONY:		all clean fclean re libft
