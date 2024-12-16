# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:34:07 by saroca-f          #+#    #+#              #
#    Updated: 2024/11/24 14:42:19 by saroca-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
RM = rm -f
SRC = 	main.cpp \

OBJ = $(SRC:.cpp=.o)

RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n"; \
	printf "$(GREEN)            ___  _       ___    _____    _     _      ___ ___ \n$(RESET)"; \
	printf "$(GREEN) ___ _ _   |   |/ |  ___|  _|  |    _| _| |_ _| |_   |   |__ |\n$(RESET)"; \
	printf "$(GREEN)| -_|_'_|  | | || | | . |  _|  |   |_ |_   _|_   _|  | | | | |\n$(RESET)"; \
	printf "$(GREEN)|___|_,_|  |___|/_| |___|_|    |_____|  |_|   |_|    |___| |_|\n$(RESET)"; \
	printf "$(GREEN)                                                                \n$(RESET)"; \
	printf "\n";
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CLFAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@if ls $(OBJ) 1> /dev/null 2>&1; then \
		$(RM) $(OBJ); \
		echo "$(BLUE)Deleting all objects from /ex03...$(RESET)"; \
	else \
		echo "$(RED)No objects to remove from /ex03.$(RESET)"; \
	fi;

fclean: clean
	@if ls $(NAME) 1> /dev/null 2>&1; then \
		$(RM) $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /ex03...$(RESET)"; \
	else \
		echo "$(RED)No executable to remove from /ex03.$(RESET)"; \
	fi;

re: fclean all

.PHONY: all clean fclean re