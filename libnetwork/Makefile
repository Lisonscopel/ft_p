# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/10 15:14:03 by ghilbert          #+#    #+#              #
#    Updated: 2015/05/17 15:09:48 by tlepeche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libnetwork.a

SRCS = serv_create_tcp.c \
		client_create_tcp.c \
		trans_file.c \
		last_error.c \

OBJS = $(SRCS:.c=.o)

INC_PATH	= includes/
INCLUDES	= -I $(INC_PATH) -I ../libft/includes

HEADER = $(INC_PATH)libnetwork.h

CC = gcc

CFLAGS += -Wall -Wextra -Werror

RM = /bin/rm -f

all : $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(INCLUDES) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIBNETWORK: Compilation done"

clean:
	@$(RM) $(OBJS)
	@echo "LIBNETWORK: Objects destroyed"

fclean: clean
	@$(RM) $(NAME)
	@echo "LIBNETWORK: Folder cleaned"

re: fclean all
