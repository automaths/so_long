SRCS			=	./srcs/so_long.c \
					./srcs/get_next_line.c \
 					./srcs/get_next_line_utils.c \
					./srcs/check_errors.c \
					./srcs/check_map.c \
					./srcs/init.c \
					./srcs/parsing.c \
					./srcs/moving.c \
					./srcs/printing.c \
					./srcs/freeing.c \

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	-L ./srcs -lftprintf -L ./minilibx-linux -lmlx_Linux -lXext -lX11

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -g3 -I./srcs -I./minilibx-linux

NAME			= 	so_long

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C ./minilibx-linux
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
