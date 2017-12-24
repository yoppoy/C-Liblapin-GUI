

NAME		=	tekgui

LIB		=	-rdynamic \
			-I/home/${USER}/.froot/include \
			-L../ -ltekgui \
			-L/home/${USER}/.froot/lib \
			-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \

#FLAG		=	 -ggdb3 -I/home/${USER}/.froot/include/

FLAG		+=	-W -Wall -ansi -pedantic -ggdb3 -I/home/${USER}/.froot/include/ -lm

SRC		=	main.c

CC		=	gcc -c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME):		$(OBJ)
			gcc -g $(OBJ) $(LIB) -o $(NAME) -I ./

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)
			rm -f *~
			rm -f *#
re		:	fclean all
.c.o		:
			gcc -c $< -o $@ $(FLAG)

