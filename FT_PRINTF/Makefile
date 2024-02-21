# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:11:55 by nadjemia          #+#    #+#              #
#    Updated: 2023/11/22 15:01:12 by nadjemia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putchar.c \
       ft_putstr.c \
       ft_printf.c \
       ft_putun.c \
       ft_putnbr_m.c \
       ft_strlen.c \
       ft_p.c \
       ft_putnbr.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

CC = cc

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -c

$(NAME): $(OBJS)
	ar -rsc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
