# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 16:43:44 by mklotz            #+#    #+#              #
#    Updated: 2020/10/21 18:15:00 by mklotz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FILES = ft_atoi.c  ft_bzero.c ft_calloc.c ft_memset.c ft_memcpy.c\
ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c\
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c\
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_C_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

ifdef COMPILE_BONUS
	O_FILES = $(C_FILES:.c=.o) $(BONUS_C_FILES:.c=.o)
else
	O_FILES = $(C_FILES:.c=.o)
endif

HEADER = libft.h

.PHONY: all clean fclean bonus re

all: $(NAME)

$(NAME): $(O_FILES)
	ar -rcs $(NAME) $(O_FILES)

%.o: %.c $(HEADER)
	gcc -Wall -Werror -Wextra -c $<

bonus:
	$(MAKE) COMPILE_BONUS=1 all

clean:
	@rm -f $(O_FILES) $(BONUS_C_FILES:.c=.o)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
