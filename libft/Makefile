# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 15:58:46 by emohamed          #+#    #+#              #
#    Updated: 2023/01/01 23:26:40 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_atoi.c ft_strdup.c ft_strlen.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^
	
$(NAME): $(OBJS)
	ar rcs $(NAME) $^

all: $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all  clean fclean re 