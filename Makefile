# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrik <patrik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 10:38:00 by patrik            #+#    #+#              #
#    Updated: 2025/06/10 13:15:41 by patrik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Mandatory source files
SOURCES = src/ft_printf.c \
          src/parser.c \
          src/dispatcher.c \
          src/handlers.c \
          src/utils.c

# Object files
OBJECTS = src/ft_printf.o \
          src/parser.o \
          src/dispatcher.o \
          src/handlers.o \
          src/utils.o

# Header files
HEADERS = ft_printf.h src/parser.h

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

# For now, bonus just rebuilds the mandatory part
bonus: $(LIBFT) $(NAME)

# Compilation rule
src/%.o: src/%.c $(HEADERS)
	cc -Wall -Wextra -Werror -I. -I src -I $(LIBFT_DIR) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re