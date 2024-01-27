# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msbai <msbai@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:34:46 by msbai             #+#    #+#              #
#    Updated: 2024/01/27 14:12:11 by msbai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AFILE = libft/libft.a ft_printf/libftprintf.a
NAME = server client
CFILE = server.c client.c

NAMEB = server_bouns client_bouns
CFILEB = server_bouns.c client_bouns.c

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

bouns:$(NAMEB)

$(NAMEB): $(CFILEB) $(AFILE)
	$(CC) $(CFLAGS) server_bouns.c $(AFILE) -o server_bouns
	$(CC) $(CFLAGS) client_bouns.c $(AFILE) -o client_bouns
