# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 11:39:22 by jbrown            #+#    #+#              #
#    Updated: 2022/01/24 18:36:00 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I . -c
RM = rm -f

SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c

BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus:
	$(CC) $(CFLAGS) $(SRCS) $(BONUS_SRCS)
	ar rc $(NAME) $(SRCS) $(BONUS_OBJS)
	ranlib $(NAME)

clean: 
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean $(NAME)

.phony: all clean fclean re
