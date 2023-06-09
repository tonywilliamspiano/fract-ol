# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 11:45:00 by awilliam          #+#    #+#              #
#    Updated: 2023/05/05 17:44:55 by awilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c src/input_check.c src/utils.c src/key_protocol.c src/mouse_protocol.c \
	src/make_img.c src/inits.c src/fractal_check.c src/get_color.c \
	src/utils_2.c src/help.c src/ft_atoi_base.c

INCLUDE = /usr/X11/include

LIBFT = libft.a

MLX = libmlx.a

FLAGS = -Wall -Wextra -Werror

LIBFLAGS = /usr/X11/lib -lX11 -lXext

LIBS = libft.a libmlx.a

NAME = fractol

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(SRCS)
	@cc $(FLAGS) -o $(NAME) -I $(INCLUDE) -Ofast -L $(LIBFLAGS) $(LIBS) $(SRCS) $(LIBFT) $(PRINTF) $(MLX)
	echo "Compiling fractol..."

quick: $(MLX) $(LIBFT)
	@cc $(FLAGS) -o $(NAME) -I $(INCLUDE) -Ofast -L $(LIBFLAGS) $(LIBS) $(SRCS) $(LIBFT) $(PRINTF) $(MLX)
	
$(MLX): minilibx-linux/
	@cd minilibx-linux && make all && mv $(MLX) ../ && make clean
	echo "Compiling MLX..."

$(LIBFT): libft/
	@cd libft/ && make && mv libft.a ../ && make fclean
	@echo "Compiling libft..."

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all clean

.PHONY: all clean fclean re
