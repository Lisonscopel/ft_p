# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/10 15:14:03 by ghilbert          #+#    #+#              #
#    Updated: 2015/05/20 14:42:12 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libnetwork.a

SRC = serv_create_tcp.c \
	  client_create_tcp.c \
	  trans_file.c \
	  last_error.c \

OBJDIR = obj/

NO_COLOR = "\033[0;0m"
CC_COLOR = "\033[0;33m"
EX_COLOR = "\033[0;32m"
PX_COLOR = "\033[4;37m"
DE_COLOR = "\033[0;31m"

CC_STR = $(CC_COLOR)[CC]$(NO_COLOR)
EX_STR = $(EX_COLOR)$(NAME)$(NO_COLOR)
PX_STR = $(PX_COLOR)Library compiled successfully$(NO_COLOR)
DE_STR = $(DE_COLOR)Remove$(NO_COLOR)

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

INC_PATH	= includes/
INC	= -I $(INC_PATH) -I ../libft/includes

HEADER = $(INC_PATH)libnetwork.h

CC = gcc

CFLAGS += -Wall -Wextra -Werror

RM = rm -rf

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo ""
	@echo $(PX_STR) : $(EX_STR)
	@echo ""

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@echo $(CC_STR) $*

clean:
	@$(RM) $(OBJDIR)
	@echo $(DE_STR) libnetwork objects

fclean: clean
	@$(RM) $(NAME)
	@echo $(DE_STR) $(NAME)

re: fclean all
