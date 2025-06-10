# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrik <patrik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 10:38:00 by patrik            #+#    #+#              #
#    Updated: 2025/06/10 12:31:11 by patrik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Source files
SOURCES = $(wildcard src/*.c)
BONUS_SOURCES = $(wildcard src/*_bonus.c)
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

# Headers
HEADERS = ft_printf.h src/parser.h
BONUS_HEADERS = $(wildcard src/*_bonus.h)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

src/%.o: src/%.c $(HEADERS) $(BONUS_HEADERS)
	cc -Wall -Wextra -Werror -I. -I src -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re