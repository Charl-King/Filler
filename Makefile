# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cking <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 18:23:40 by cking             #+#    #+#              #
#    Updated: 2018/08/01 08:23:01 by cking            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=filler.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -O3

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

SRC=placement.c readmap.c readtoken.c

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
