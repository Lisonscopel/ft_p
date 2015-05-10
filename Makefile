# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/10 02:07:11 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME_S= server

NAME_C= client

SRC_S=  server.c \

SRC_C= client.c \
	   get_next_line.c \

OBJDIR_C= OBJ_C/

OBJDIR_S= OBJ_S/

OBJ_S= $(SRC_S:%.c=$(OBJDIR_S)%.o)

OBJ_C= $(SRC_C:%.c=$(OBJDIR_C)%.o)

CC= gcc

CFLAGS= -Wextra -Wall -Werror

RM= rm -rf

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJ_S)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME_S) $(OBJ_S) -L libft/ -lft

$(NAME_C): $(OBJ_C)
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJ_C) -L libft/ -lft

$(OBJDIR_S)%.o:%.c
	@mkdir -p $(OBJDIR_S)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

$(OBJDIR_C)%.o:%.c
	@mkdir -p $(OBJDIR_C)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJDIR_S)
	$(RM) $(OBJDIR_C)

fclean: clean
	$(RM) $(NAME_S)
	$(RM) $(NAME_C)
	make -C libft/ fclean

re: fclean all
