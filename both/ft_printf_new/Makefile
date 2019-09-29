#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:15:02 by ochayche          #+#    #+#              #
#    Updated: 2017/01/18 18:15:03 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = gcc

F = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJECT = ./ft_printf.o \
	./parse_continue.o \
	./parse.o \
	./parse_format.o \
	./handle_s.o \
	./handle_c.o \
	./handle_percent.o \
	./handle_d.o \
	./handle_u.o \
	./handle_x.o \
	./handle_o.o \
	./handle_p.o \
	./handle_f.o \

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
		ar rc $(NAME) $(OBJECT)
		ranlib $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

ft_printf.o: ft_printf.c
	$(GCC) $(F) -c ft_printf.c

parse_continue.o: parse_continue.c
	$(GCC) $(F) -c parse_continue.c

parse_format.o: parse_format.c
	$(GCC) $(F) -c parse_format.c

handle_s.o: handle_s.c
	$(GCC) $(F) -c handle_s.c

handle_c.o: handle_c.c
	$(GCC) $(F) -c handle_c.c

handle_percent.o: handle_percent.c
	$(GCC) $(F) -c handle_percent.c

handle_d.o: handle_d.c
	$(GCC) $(F) -c handle_d.c

handle_u.o: handle_u.c
	$(GCC) $(F) -c handle_u.c

handle_x.o: handle_x.c
	$(GCC) $(F) -c handle_x.c

handle_o.o: handle_o.c
	$(GCC) $(F) -c handle_o.c

handle_p.o: handle_p.c
	$(GCC) $(F) -c handle_p.c

parse.o: parse.c
	$(GCC) $(F) -c parse.c

handle_f.o: handle_f.c
	$(GCC) $(F) -c handle_f.c
