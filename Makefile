# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 14:08:02 by dferreir          #+#    #+#              #
#    Updated: 2022/10/27 15:31:15 by dferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = libftprintf.a

SRCS_DIR = srcs/

SOURCES = ft_printf.c ft_printstr.c ft_printnbr.c #ft_printptr.c ft_printUnbr.c

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
