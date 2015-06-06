# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#              #
#    Updated: 2015/06/06 13:15:04 by lscopel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c \
	  ft_lstdel.c ft_lstdelone.c ft_lstend.c ft_lstiter.c ft_lstmap.c \
	  ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c \
	  ft_putchar.c ft_putchar_fd.c ft_putcolor.c ft_putcolorendl.c \
	  ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	  ft_putstr_fd.c ft_realloc.c ft_strcat.c ft_strchr.c ft_strclr.c \
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strreplace.c \
	  ft_strsplit.c ft_strssplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_tolower.c ft_toupper.c ft_usage.c get_next_line.c ft_free_tab.c \
	  ft_strsplit_blank.c ft_how_many.c ft_strnchr.c get_path.c \

NO_COLOR = "\033[0;0m"
CC_COLOR = "\033[0;33m"
EX_COLOR = "\033[0;32m"
PX_COLOR = "\033[4;37m"
DE_COLOR = "\033[0;31m"

CC_STR = $(CC_COLOR)[CC]$(NO_COLOR)
EX_STR = $(EX_COLOR)$(NAME)$(NO_COLOR)
PX_STR = $(PX_COLOR)Library compiled successfully$(NO_COLOR)
DE_STR = $(DE_COLOR)Remove$(NO_COLOR)

OBJDIR = obj/

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

HEADER = libft.h

CC = gcc

INC = -I ./includes

CFLAGS += -Wall -Wextra -Werror

RM = rm -rf

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@echo ""
	@echo $(PX_STR) : $(EX_STR)
	@echo ""

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@echo $(CC_STR) $*

clean:
	@$(RM) $(OBJDIR)
	@echo $(DE_STR) libft objects

fclean: clean
	@$(RM) $(NAME)
	@echo $(DE_STR) $(NAME)

re: fclean all
