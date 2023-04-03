NAME = fractal

CFLAGS		=	-g -Wall -Wextra -Werror

SOURCES		=   julia.c \
				mandelbrot.c \
				esc.c \
				main.c \
				render.c \
				ft_strncmp.c 
OBJECTS		=	${SOURCES:.c=.o} 	

COMPILER	=	cc
APPEND		=	ar -rc
DELETE		=	rm -f

%.o:	%.c fractal.h
	${COMPILER} ${CFLAGS}  -Imlx -c $< -o $@

all:	${NAME}

${NAME}:	${OBJECTS} fractal.h
	cc $(OBJECTS) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

clean:
	${DELETE} ${OBJECTS}

fclean: clean
	${DELETE} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
