# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 17:46:54 by jmartyn-          #+#    #+#              #
#    Updated: 2019/09/14 17:46:55 by jmartyn-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c \
ft_putnbr_long.c \
ft_putnbr_uint.c \
ft_putnbr.c \
ft_strlen_double.c \
is_digit.c \
is_upper.c

OBJ = $(SRC:.c=.o)
HEADER = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -I$(HEADER) $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
