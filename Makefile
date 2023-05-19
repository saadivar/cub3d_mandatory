SRC = main.c parsing.c parsing1.c parsing2.c parsing3.c parsing4.c get_next_line.c get_next_line_utils.c \
  ft_split_libft.c ft_strncmp.c ft_atoi.c raycast1.c raycast2.c raycast3.c raycast4.c raycast5.c raycast6.c
OBJFILES = $(SRC:.c=.o)
CFLAGS =  -Wall -Wextra -Werror 
NAME = cub3D



all:  $(NAME) 

$(NAME): $(OBJFILES)
	cc   $(CFLAGS) $(OBJFILES) $(MLX)   -lmlx -framework OpenGl -framework Appkit -o $(NAME)

	
clean:
	rm -rf $(OBJFILES)


fclean: clean
	rm -rf $(NAME)
re:fclean all