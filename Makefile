

NAME		=	libtekgui.a

LIB		=	-I/home/${USER}/.froot/include \
			-L/home/${USER}/.froot/lib \
			-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
			-rdynamics

#FLAG		=	 -ggdb3 -I/home/${USER}/.froot/include/

CFLAGS		+=	-W -Wall  -ggdb3 -I/home/${USER}/.froot/include/ -lm

SRC		=	tcore/required.c \
			tcore/text.c \
			basic_nbr.c \
			basic_function.c \
			basic_functions.c \
			parse_item.c \
			parse_gui.c \
			graphics.c \
			graphics_action.c \
			graphics_action_s.c \
			graphics_text.c \
			graphics_basics.c \
			graphics_color.c \
			graphics_background.c \
			graphics_component.c \
			graphics_component_s.c \
			graphics_draw.c \

CC		=	gcc -c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME):		$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)
			rm -f *~
			rm -f *#

re		:	fclean all

.c.o		:
			gcc -c $< -o $@ $(CFLAGS)
