# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 11:54:51 by emohamed          #+#    #+#              #
#    Updated: 2023/01/01 16:00:32 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=   \033[0;31m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_WARNING		=[$(RED)WARNING$(RESET)]

all: $(CLIENT) $(SERVER)
	
$(CLIENT):
	cd libft && make all
	cd ft_printf && make all
	cc $(FLAGS) libft/libft.a ft_printf/libftprintf.a client.c -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"
$(SERVER):
	cd libft && make all
	cd ft_printf && make all
	cc $(FLAGS) libft/libft.a ft_printf/libftprintf.a server.c -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

clean:
	cd libft && make clean
	cd ft_printf && make clean
	cc $(FLAGS) libft/libft.a ft_printf/libftprintf.a client.c -o $(CLIENT)
	cc $(FLAGS) libft/libft.a ft_printf/libftprintf.a server.c -o $(SERVER)
	@printf "$(_WARNING) object files removed.\n"
	
fclean:
	cd libft && make fclean
	cd  ft_printf && make fclean
	$(RM) client
	$(RM) server
	@printf "$(_WARNING) client removed.\n"
	@printf "$(_WARNING) server removed.\n"


re:
	cd libft && make re
	cd ft_printf && make re
	cc $(FLAGS) libft/libft.a ft_printf/libftprintf.a client.c -o $(CLIENT)
	cc $(FLAGS) libft/libft.a ft_printf/libftprintf.a server.c -o $(SERVER)
	@printf "$(_SUCCESS) client has been updated.\n"
	@printf "$(_SUCCESS) server  has been updated.\n"

.PHONY: all clean fclean re
	
