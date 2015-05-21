# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 22:37:19 by tlepeche          #+#    #+#              #
#    Updated: 2015/05/21 16:19:42 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S		= server
NAME_SERV	= serveur
NAME_C		= client

INC_PATH	= includes/
INC = -I $(INC_PATH) -I libft/includes -I libnetwork/includes

SRC_S_NAME	=	server.c \
				dial_client.c \
				password.c \
				init.c \
				server_ask_cd.c \
				server_ask_ls.c \
				server_ask_pwd.c \
				server_ask_put.c \
				ft_how_many.c \
				ft_strnchr.c \

SRC_C_NAME	=	client.c \
				ft_how_many.c \
				init.c \
				dial_server.c \
				ask_quit.c \
				client_ask_put.c \

NO_COLOR = "\033[0;0m"
CC_COLOR = "\033[0;33m"
EX_COLOR = "\033[0;32m"
PX_COLOR = "\033[4;37m"
DE_COLOR = "\033[0;31m"

CC_STR = $(CC_COLOR)[CC]$(NO_COLOR)
EX_STR_C = $(EX_COLOR)$(NAME_C)$(NO_COLOR)
EX_STR_S = $(EX_COLOR)$(NAME_S)$(NO_COLOR)
PX_STR = $(PX_COLOR)Binary compiled successfully$(NO_COLOR)
DE_STR = $(DE_COLOR)Remove$(NO_COLOR)

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
RM = rm -rf

OBJ_S = $(SRC_S_NAME:%.c=$(OBJDIR_S)%.o)
OBJ_C = $(SRC_C_NAME:%.c=$(OBJDIR_C)%.o)

OBJDIR = obj/
OBJDIR_C = $(OBJDIR)client/
OBJDIR_S = $(OBJDIR)server/

SRCDIR = src/
SRCDIR_C = $(SRCDIR)client/
SRCDIR_S = $(SRCDIR)server/

BINDIR = bin/
BIN_S = $(addprefix $(BINDIR), $(NAME_S))
BIN_C = $(addprefix $(BINDIR), $(NAME_C))

.PHONY: all clean fclean re proper debug debugall

all: lft lnw $(NAME_C) $(NAME_S)

$(NAME_S): $(BIN_S)
$(NAME_C): $(BIN_C)

$(BIN_S): $(OBJ_S)
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) -o $(BIN_S) $(LIBS) $^
	@echo ""
	@echo $(PX_STR) : $(EX_STR_S)
	@echo ""

$(OBJDIR_S)%.o: $(SRCDIR_S)%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR_S)
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@echo $(CC_STR) $*

$(BIN_C): $(OBJ_C)
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) -o $(BIN_C) $(LIBS) $^
	@echo ""
	@echo $(PX_STR) : $(EX_STR_C)
	@echo ""

$(OBJDIR_C)%.o: $(SRCDIR_C)%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR_C)
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@echo $(CC_STR) $*

lft:
	@make -C libft

lnw:
	@make -C libnetwork

clean:
	@make clean -C libft
	@make clean -C libnetwork
	@$(RM) $(OBJDIR)

fclean: clean
	@make fclean -C libft
	@make fclean -C libnetwork
	@$(RM) $(BINDIR)

proper: all clean

re:	fclean all

debug:
	CFLAGS="-g" make

debugall:
	CFLAGS="-g" make re
