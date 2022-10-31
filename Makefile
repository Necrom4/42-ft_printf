# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 14:08:02 by dferreir          #+#    #+#              #
#    Updated: 2022/10/31 10:05:38 by dferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = libftprintf.a

SRCS_DIR = srcs/

SOURCES = ft_printf.c ft_printchar.c ft_printhex.c ft_printnbr.c ft_printunbr.c ft_printstr.c ft_printptr.c

SRCS = $(addprefix $(SRCS_DIR), $(SOURCES))

OBJS = $(SRCS:.c=.o)

INCLUDE = includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C Libft
	cp Libft/libft.a $(NAME)
	$(CC) -c $(CFLAGS) -I $(INCLUDE) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) *.o
	make clean -C Libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C Libft

re:	fclean $(NAME)

.PHONY: all clean fclean re
