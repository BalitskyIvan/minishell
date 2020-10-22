# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/22 14:31:11 by mklotz            #+#    #+#              #
#    Updated: 2020/10/20 19:30:38 by mklotz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT_NAME = libft.a

SCR_DIR = ./srcs
UTILS_DIR = ./utils
INCLUDES_DIR = ./includes

MANAGERS_DIR = $(SCR_DIR)/managers
PARSER_DIR = $(MANAGERS_DIR)/parser
HELPERS_DIR = $(SCR_DIR)/helpers
LIBFT_DIR = $(UTILS_DIR)/libft
GNL_DIR = $(UTILS_DIR)/gnl

CC = gcc
CFLAGS = -Wall -Wextra -Werror

C_FILES = $(SCR_DIR)/main.c\
		$(GNL_DIR)/get_next_line.c\
		$(HELPERS_DIR)/command_helper.c\
		$(HELPERS_DIR)/print_export.c\
		$(MANAGERS_DIR)/error_manager.c\
		$(MANAGERS_DIR)/init_manager.c\
		$(MANAGERS_DIR)/invitation_manager.c\
		$(PARSER_DIR)/tools/command_utils.c\
		$(PARSER_DIR)/tools/str_parser.c\
		$(PARSER_DIR)/tools/parser_tools.c\
		$(PARSER_DIR)/tools/args_parser.c\
		$(PARSER_DIR)/tools/brackets_parser.c\
		$(PARSER_DIR)/parse_commands_utils.c\
		$(PARSER_DIR)/parse_commands.c\
		$(MANAGERS_DIR)/execute_manager.c\
		$(HELPERS_DIR)/env_helper.c\
		$(HELPERS_DIR)/custom_command_helper.c\
		$(MANAGERS_DIR)/custom_functions/my_custom_functions.c\
		$(MANAGERS_DIR)/custom_functions/change_directory.c\
		$(MANAGERS_DIR)/redirect_manager.c\
		$(HELPERS_DIR)/files_helper.c\
		$(MANAGERS_DIR)/custom_functions/env_functions.c\
		$(PARSER_DIR)/tools/join_args.c

O_FILES = $(C_FILES:.c=.o)

HEADER = $(INCLUDES_DIR)/minishell.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT_NAME) $(O_FILES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(O_FILES)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
