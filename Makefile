LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	pipex.c finish.c children.c get_next_line.c exits.c paths.c

SOURCES_DIR		=	./sources

SOURCES_DIR_B	=	./sources_bonus

HEADER			=	$(SOURCES_DIR)/pipex.h

BONUS_HEADER	=	$(SOURCES_DIR_B)/pipex.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

BONUS_SOURCES	=	$(addprefix $(SOURCES_DIR_B)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

BONUS_OBJECTS	= 	$(BONUS_SOURCES:.c=.o)

MAKE			=	make

NAME			=	pipex

BONUS			=	pipex_bonus

CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-g3 -Wall -Wextra -Werror -D BUFFER_SIZE=100

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

fclean:		clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	$(RM) outfile cat infile input dossier not out2 output dossier2 out out3 output2

re:			fclean all

.PHONY:		all clean fclean re libft
