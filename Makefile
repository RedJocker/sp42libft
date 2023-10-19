#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 16:14:38 by maurodri          #+#    #+#              #
#    Updated: 2023/10/19 17:30:33 by maurodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB_NAME = libft.a
FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

DEP_FILES = $(patsubst %.c,%.d,$(FILES))
OBJS = $(patsubst %.c,%.o,$(FILES))
DEP_FLAGS =  -MP -MD
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $^

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o ./$@ $(DEP_FLAGS)

.Phony: clean

clean:
	rm -fr $(OBJS) $(DEP_FILES)

-include $(DEP_FILES)
