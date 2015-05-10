# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscopel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/03 16:27:01 by lscopel           #+#    #+#              #
#    Updated: 2015/03/26 10:01:36 by lscopel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_itoa.c ft_bzero.c ft_memcmp.c ft_memcpy.c ft_memccpy.c \
	   ft_memchr.c ft_memmove.c ft_memset.c ft_memalloc.c ft_memdel.c \
	   ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putstr.c \
	   ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strcat.c ft_strncat.c \
	   ft_strcpy.c ft_strncpy.c ft_strstr.c ft_strnstr.c ft_strchr.c \
	   ft_strrchr.c	ft_strdup.c	ft_strnew.c ft_strmap.c ft_strmapi.c \
	   ft_strjoin.c ft_strsub.c ft_strtrim.c ft_strsplit.c ft_strcmp.c \
	   ft_strncmp.c ft_strequ.c ft_strnequ.c ft_strlcat.c ft_strlen.c \
	   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_isalpha.c \
	   ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c \
	   ft_toupper.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	   ft_lstmap.c ft_lstnew.c get_next_line.c

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

CC = gcc

CFLAGS += -Wall -Wextra -Werror

RM = /bin/rm -f

all : $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS)  -c -I includes/
	@ar rc libft.a $(OBJS)
	@echo "LIBFT: Compilation done"

clean:
	@$(RM) $(OBJS)
	@echo "LIBFT: Objects destroyed"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) a.out
	@echo "LIBFT: Folder cleaned"

re: fclean all
