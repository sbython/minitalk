# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msbai <msbai@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:34:46 by msbai             #+#    #+#              #
#    Updated: 2024/01/29 22:33:17 by msbai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AFILE = libft/libft.a ft_printf/libftprintf.a
NAME = server client
CFILE = server.c client.c

NAMEB = server_bonus client_bonus
CFILEB = server_bonus.c client_bonus.c

all:$(NAME)

$(NAME): $(CFILE) $(AFILE)
	$(CC) $(CFLAGS) server.c $(AFILE) -o server
	$(CC) $(CFLAGS) client.c $(AFILE) -o client

$(AFILE):
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf

clean:
	$(MAKE) -C ./libft clean 
	$(MAKE) -C ./ft_printf clean

fclean: clean
	rm -rf $(NAME) $(NAMEB) 
	$(MAKE) -C ./libft fclean 
	$(MAKE) -C ./ft_printf fclean

re: fclean all

bonus:$(NAMEB)

$(NAMEB): $(CFILEB) $(AFILE)
	$(CC) $(CFLAGS) server_bonus.c $(AFILE) -o server_bonus
	$(CC) $(CFLAGS) client_bonus.c $(AFILE) -o client_bonus
