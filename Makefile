# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javsanch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 18:09:27 by javsanch          #+#    #+#              #
#    Updated: 2022/11/08 15:01:15 by javsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
NAME = libftprintf.a
CC = gcc -c
INCLUDE = ft_printf.h \ ./libft/libft.h
FLAGS = -Wall -Wextra -Werror
AR = ar rc

SRCS = ft_printf.c  ft_printfdi.c  ft_printfp.c \
		ft_printfp.c ft_printfper.c ft_printfstr.c \
		ft_printfu.c ft_printfxx.c


OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	cp libft/libft.a $(NAME)
	$(CC)  $(FLAGS) $(SRCS)
	$(AR)  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
