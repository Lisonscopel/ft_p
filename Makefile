# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/10 15:43:41 by ghilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S		= server
NAME_C		= client

BIN_PATH	= bin/

SRC_PATH	= src/
SRC_S_PATH	= $(NAME_S)/
SRC_C_PATH	= $(NAME_C)/

OBJ_PATH	= obj/

INC_PATH	= includes/
INCLUDES	= -I $(INC_PATH) -I libft/includes -I libnetwork/includes

SRC_S_NAME	=	server.c \
				password.c

SRC_C_NAME	=	client.c
				
HEADER 		=	$(INC_PATH)ft_p.h \
				$(INC_PATH)server.h \
				$(INC_PATH)client.h

LIBFT_PATH	= libft
LIBFT_NAME	= -lft
LIBFT		= -L$(LIBFT_PATH) $(LIBFT_NAME)

LIBNET_PATH	= libnetwork
LIBNET_NAME	= -lnetwork
LIBNET		= -L$(LIBNET_PATH) $(LIBNET_NAME)


LIBS		= $(LIBFT) $(LIBNET)

CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra

SRC_S		= $(addprefix $(SRC_S_PATH),$(SRC_S_NAME))
SRC_C		= $(addprefix $(SRC_C_PATH),$(SRC_C_NAME))

OBJS_S 		= $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_S)))
OBJS_C 		= $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_C)))

BIN_S		= $(addprefix $(BIN_PATH),$(NAME_S))
BIN_C		= $(addprefix $(BIN_PATH),$(NAME_C))


.PHONY: all clean fclean re proper debug debugall

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(BIN_S)
$(NAME_C): $(BIN_C)

$(BIN_S): libft/libft.a libnetwork/libnetwork.a $(OBJS_S) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_S) -o $(BIN_S) $(LIBS)

$(BIN_C): libft/libft.a libnetwork/libnetwork.a $(OBJS_C) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_C) -o $(BIN_C) $(LIBS)

libft/libft.a:
	make -C libft

libnetwork/libnetwork.a:
	make -C libnetwork

$(OBJS_S): | $(OBJ_PATH)
$(OBJS_C): | $(OBJ_PATH)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)$(NAME_S)
	@mkdir -p $(OBJ_PATH)$(NAME_C)

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

clean:
	@make clean -C libft
	@make clean -C libnetwork
	rm -rf $(OBJS)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf libft/libft.a
	rm -rf libnetwork/libnetwork.a
	rm -rf $(BIN_PATH)

proper: all clean

re:	fclean all

debug:
	CFLAGS="-g" make

debugall:
	CFLAGS="-g" make re


