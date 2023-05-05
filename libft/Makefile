# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 19:36:10 by awilliam          #+#    #+#              #
#    Updated: 2023/02/21 10:38:50 by awilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_strchr.c \
			ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_conv_cases.c ft_printf.c ft_putstr.c ft_putnbr_b.c \
			get_next_line.c get_next_line_utils.c ft_putnbr_ret.c

OBJECTS = $(SOURCES:.c=.o)

BONUS = ft_lstnew.c ft_lstdelone.c ft_lstclear.c \
		ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
		ft_lstmap.c ft_lstlast.c ft_lstiter.c

BONUS_OBJECTS = $(BONUS:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: $(NAME) all clean fclean re bonus