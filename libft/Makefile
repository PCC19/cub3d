# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 13:39:04 by pcunha            #+#    #+#              #
#    Updated: 2021/01/31 19:35:02 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

FLAG=-Wall -Wextra -Werror -g

HEADER = libft.h

SRCS=ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isdigit.c ft_isalnum.c \
	 ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	 ft_strlen.c ft_strlcpy.c ft_strchr.c ft_strlcat.c ft_strrchr.c \
	 ft_strnstr.c ft_strncmp.c ft_calloc.c ft_strdup.c ft_memset.c \
	 ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	 ft_memcmp.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	 ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putendl_fd.c \
	 ft_putnbr_fd.c ft_putstr_fd.c ft_strlcpy.c ft_calloc.c ft_strdup.c \
	 ft_substr.c ft_putchar.c ft_putnbr_base.c ft_itoa_base.c ft_print_bit.c\
	 ft_append_str.c ft_is_in.c ft_max.c ft_min.c ft_shift_left.c\
	 ft_shift_right.c ft_abs.c ft_get_bit.c

SRCSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS=ft_atoi.o ft_bzero.o ft_isalnum.o \
		ft_isalpha.o ft_isascii.o ft_isdigit.o ft_tolower.o ft_isprint.o \
		ft_toupper.o ft_itoa.o \
		ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
		ft_memmove.o ft_memset.o ft_putchar_fd.o \
		ft_putendl_fd.o ft_putnbr_fd.o \
		ft_putstr_fd.o ft_strchr.o \
		ft_strjoin.o \
		ft_strlcat.o ft_strlen.o ft_strmapi.o \
		ft_strncmp.o ft_strnstr.o \
		ft_strrchr.o ft_split.o \
		ft_strtrim.o ft_tolower.o ft_toupper.o ft_strlcpy.o ft_calloc.o \
		ft_strdup.o ft_substr.o ft_putchar.o ft_putnbr_base.o ft_itoa_base.o\
		ft_print_bit.o ft_append_str.o ft_is_in.o ft_max.o ft_min.o\
		ft_shift_left.o ft_shift_right.o ft_abs.o ft_get_bit.o


OBJBB = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o\
		ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

CC = clang

$(NAME): ./libft.h
		echo LIBFT
		$(CC) $(FLAG) -c $(SRCS) -I $(HEADER)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

bonus: ./libft.h
		@$(CC) $(FLAG) -c $(SRCS) $(SRCSB) -I $(HEADER)
		@ar rc $(NAME) $(OBJECTS) $(OBJBB)
		@ranlib $(NAME)
