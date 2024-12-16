# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 10:42:34 by saroca-f          #+#    #+#              #
#    Updated: 2024/12/16 08:51:54 by saroca-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brainz
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
RM = rm -f
SRC = 	main.cpp \
		newZombie.cpp \
		randomchump.cpp \
		Zombie.cpp \

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
	printf "$(GREEN)            ___ ___       ___    _____    _     _      ___  _ \n$(RESET)"; \
	printf "$(GREEN) ___ _ _   |   |   |  ___|  _|  |    _| _| |_ _| |_   |   |/ | \n$(RESET)"; \
	printf "$(GREEN)| -_|_'_|  | | | | | | . |  _|  |   |_ |_   _|_   _|  | | || | \n$(RESET)"; \
	printf "$(GREEN)|___|_,_|  |___|___| |___|_|    |_____|  |_|   |_|    |___|___|\n$(RESET)"; \
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