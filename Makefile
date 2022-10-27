# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 21:23:18 by sopopa            #+#    #+#              #
#    Updated: 2022/10/27 21:35:15 by sopopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
	ft_printf_utils.c \
	ft_print_unsigned.c \
	ft_print_pointaddress.c \
	ft_print_number.c \
	ft_print_hexadecimal.c 

LIBFT = ./libft

FLAGS = -Wall -Werror -Wextra -c
CC = gcc
OBJS = $(SRCS:.c=.o)
	
OBJS_BONUS = $(BONUS:.c=.o)

$(NAME):
	$(CC) $(FLAGS) $(SRCS)
	ar rcs libftprintf.a $(OBJS)
all: $(NAME)
clean:
	rm -f $(OBJS) 

fclean:		clean
	rm -f $(NAME)
re: fclean all
bonus:
	$(CC) $(FLAGS) $(BONUS)
	ar rcs libft.a $(OBJS_BONUS)
