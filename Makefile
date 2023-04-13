# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 20:50:19 by rugoncal          #+#    #+#              #
#    Updated: 2023/02/11 20:52:03 by rugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c ft_printf_utils.c ft_put_hex.c

OBJ = $(FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -I

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
