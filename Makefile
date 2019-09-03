# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 11:56:39 by amartino          #+#    #+#              #
#    Updated: 2019/09/03 09:25:55 by fkante           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
                     ####################################
                     #                   				#
                     #       	MAIN VARIABLES 			#
                     #                   				#
                     ####################################
NAME = ft_printf
LIB_DIR = libftprintf
LIB = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS =  -Wall -Wextra -Werror -fsanitize=address,undefined -g3
INCLUDES += -I./includes
INCLUDES += -I./libftprintf/includes
HEAD += ./includes/define.h
HEAD += ./includes/ft_printf.h

                     ####################################
                     #                   				#
                     #       		PATHS     			#
                     #                   				#
                     ####################################
# LIB
LIB_PATH = $(LIB_DIR)/$(LIB)

# SRCS
PATH_SRC += statemachine/
PATH_SRC += conversion/
PATH_SRC += init/

vpath %.c $(PATH_SRC)

                     ####################################
                     #                   				#
                     #       	   SOURCE      			#
                     #                   				#
                     ####################################
# main
SRCS += main
SRCS += ft_printf

# initialize
SRCS += init_printf

# State Machine
SRCS += statemachine
SRCS += states

# Conversion
SRCS += check_flag
SRCS += conv_to_char
SRCS += conv_to_string
SRCS += conv_to_ptr
SRCS += conv_to_nbr
SRCS += conv_to_u_decimal
SRCS += conv_to_hexa_maj
SRCS += conv_to_float

                     ####################################
                     #                   				#
                     #       	  VARIABLES    			#
                     #                   				#
                     ####################################
T ?= sample
VAL ?= no
REQUEST = 'read -p "Enter a commit message:" pwd; echo $$pwd'
COMMIT_MESSAGE ?= $(shell bash -c $(REQUEST))

                     ####################################
                     #                   				#
                     #              OBJS	   			#
                     #                   				#
                     ####################################
BUILD_DIR = build/

OBJS = $(patsubst %, $(BUILD_DIR)%.o, $(SRCS))

                     ####################################
                     #                   				#
                     #       	   RULES      			#
                     #                   				#
                     ####################################
all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS) libft
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB_PATH)
	echo "\n$(CYAN)MAKE COMPLETE$(END)"

$(BUILD_DIR):
	mkdir $@

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

libft: FORCE
	echo  "\n$(CYAN)Makefile libft$(END)\n"
	make -C $(LIB_DIR)

t: all $(VAL)
	$(VALGRIND) ./ft_printf examples/$(T) #to be changed

clean:
	rm -f $(OBJS)
	rm -rf ./build
	echo "$(YELLOW)OBJS$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)
	echo "$(YELLOW)$(NAME)$(END) \t were \t $(GREEN)clean$(END)\n"
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: clean fclean all re libft t FORCE git
.SILENT:
FORCE:

					 ####################################
					 #                   				#
					 #       	  	IFEQ	   			#
					 #                   				#
					 ####################################
# FLAGS
ifeq ($(f), no)
CFLAGS = -g
else ifeq ($(f), f)
CFLAGS = $(DFLAGS)
endif

# VALGRIND
$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
CFLAGS += -g
SHOW_LEAK = --show-leak-kinds=definite
VALGRIND = valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
endif

                     ####################################
                     #                   				#
                     #       	  	IFEQ	   			#
                     #                   				#
                     ####################################

# FLAGS
ifeq ($(f), no)
CFLAGS = -g
else ifeq ($(f), f)
CFLAGS = $(DFLAGS)
endif

# VALGRIND
$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
CFLAGS += -g
SHOW_LEAK = --show-leak-kinds=definite
VALGRIND = valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
endif

                     ####################################
                     #                   				#
                     #        		GIT       			#
                     #                   				#
                     ####################################
git:
	@git add -f -A
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push

                     ####################################
                     #                   				#
                     #       		COLOR     			#
                     #                  				#
                     ####################################
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
MAGENTA = \x1b[35m
CYAN = \x1b[36m
END = \x1b[0m
