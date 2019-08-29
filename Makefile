# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 11:56:39 by amartino          #+#    #+#              #
#    Updated: 2019/08/28 18:45:42 by fkante           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIB_DIR = libft

LIB = libft.a #to be changed

LIB_PATH = $(LIB_DIR)/$(LIB)

SRC = 	statemachine/statemachine
		statemachine/main

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FFLAG =  -Wall -Wextra -Werror -fsanitize=address,undefined -g3

OBJ = $(patsubst %, %.o, $(SRC))

INCLUDES = -I.

HEAD = ./header/*.h #to be changed

T ?= sample

VAL ?= no

REQUEST = 'read -p "Enter a commit message:" pwd; echo $$pwd'

COMMIT_MESSAGE ?= $(shell bash -c $(REQUEST))

all: $(NAME)

$(NAME): $(OBJ) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH)
	@echo "\n$(CYAN)MAKE COMPLETE$(END)"

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< $(INCLUDES)
	@echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

libft: FORCE
	@echo  "\n$(CYAN)Makefile libft$(END)\n"
	@make -C $(LIB_DIR)

t: all $(VAL)
	$(VALGRIND) ./ft_printf examples/$(T) #to be changed

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)OBJ$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(NAME)$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: clean fclean all re libft t FORCE git

FORCE:

                             #####################
                             #                   #
                             #       IFEQ        #
                             #                   #
                             #####################
ifeq ($(f), no)
CFLAGS = -g
else ifeq ($(f), f)
CFLAGS = $(FFLAG)
endif

$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
CFLAGS += -g
SHOW_LEAK = --show-leak-kinds=definite
VALGRIND = valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
endif
                             #####################
                             #                   #
                             #        GIT        #
                             #                   #
                             #####################
git:
	@git add -f -A
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push

                             #####################
                             #                   #
                             #       COLOR       #
                             #                   #
                             #####################
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
MAGENTA = \x1b[35m
CYAN = \x1b[36m
END = \x1b[0m
