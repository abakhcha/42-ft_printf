# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 09:25:34 by abakhcha          #+#    #+#              #
#    Updated: 2023/12/10 17:40:10 by abakhcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_putchar.c ft_putnbr.c ft_putstr.c ft_printf.c\
		ft_puthexa.c ft_putunsigned.c ft_putpointer.c ft_strchr.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)
 
$(NAME): $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re