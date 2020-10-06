# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/22 14:31:11 by mklotz            #+#    #+#              #
#    Updated: 2020/10/06 03:12:12 by mklotz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT_NAME = libft.a

SCR_DIR = ./srcs
UTILS_DIR = ./utils
INCLUDES_DIR = ./includes

MANAGERS_DIR = $(SCR_DIR)/managers
HELPERS_DIR = $(SCR_DIR)/helpers
LIBFT_DIR = $(UTILS_DIR)/libft
GNL_DIR = $(UTILS_DIR)/gnl

CC = gcc
CFLAGS = -Wall -Wextra -Werror

C_FILES = $(SCR_DIR)/main.c\
		$(GNL_DIR)/get_next_line.c\
		$(HELPERS_DIR)/command_helper.c\
		$(HELPERS_DIR)/command_utils.c\
		$(MANAGERS_DIR)/error_manager.c\
		$(MANAGERS_DIR)/init_manager.c\
		$(MANAGERS_DIR)/invitation_manager.c\
		$(MANAGERS_DIR)/parser/parse_string.c\
		$(MANAGERS_DIR)/execute_manager.c\
		$(HELPERS_DIR)/env_helper.c\
		$(HELPERS_DIR)/custom_command_helper.c\
		$(MANAGERS_DIR)/custom_functions/my_custom_functions.c

O_FILES = $(C_FILES:.c=.o)

HEADER = $(INCLUDES_DIR)/minishell.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(LIBFT_DIR)/$(LIBFT_NAME) $(O_FILES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(O_FILES)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all