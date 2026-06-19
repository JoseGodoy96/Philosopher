# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 16:11:36 by jgodoy-m          #+#    #+#              #
#    Updated: 2026/01/15 21:38:45 by jgodoy-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# File name
NAME = philo

# Define directories
INCLUDE_DIR 	= ./include
SRC_DIR 		= ./src
OBJ_DIR     	= ./obj

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDE_DIR)

# Source files
SRC_INIT        = $(SRC_DIR)/init.c
SRC_MONITOR     = $(SRC_DIR)/monitor.c
SRC_PARSING     = $(SRC_DIR)/parsing.c
SRC_PHILO       = $(SRC_DIR)/philosophers.c
SRC_ROUTINE     = $(SRC_DIR)/routine.c
SRC_UTILS       = $(SRC_DIR)/utils.c

# Object files (all inside obj/)
OBJ_INIT        = $(OBJ_DIR)/init.o
OBJ_MONITOR     = $(OBJ_DIR)/monitor.o
OBJ_PARSING     = $(OBJ_DIR)/parsing.o
OBJ_PHILO       = $(OBJ_DIR)/philosophers.o
OBJ_ROUTINE     = $(OBJ_DIR)/routine.o
OBJ_UTILS       = $(OBJ_DIR)/utils.o

OBJ = \
	$(OBJ_INIT) \
	$(OBJ_MONITOR) \
	$(OBJ_PARSING) \
	$(OBJ_PHILO) \
	$(OBJ_ROUTINE) \
	$(OBJ_UTILS)

# Create libraries and delete files
RM = rm -f

# Indicates that the following rules are not real files
.PHONY: all clean fclean re

# Default rule
all:
	@echo "⚠️	compiling...	⚠️"
	@@$(MAKE) --no-print-directory $(NAME)
	@echo "✅	done	✅"

# Link
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Create obj directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Explicit compilation rules
$(OBJ_INIT): $(SRC_INIT) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC_INIT) -o $(OBJ_INIT)

$(OBJ_MONITOR): $(SRC_MONITOR) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC_MONITOR) -o $(OBJ_MONITOR)

$(OBJ_PARSING): $(SRC_PARSING) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC_PARSING) -o $(OBJ_PARSING)

$(OBJ_PHILO): $(SRC_PHILO) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC_PHILO) -o $(OBJ_PHILO)

$(OBJ_ROUTINE): $(SRC_ROUTINE) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC_ROUTINE) -o $(OBJ_ROUTINE)

$(OBJ_UTILS): $(SRC_UTILS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC_UTILS) -o $(OBJ_UTILS)

# Clean rules
clean:
	@echo "🚮	cleaning...	🚮"
	@$(RM) $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "✅	done	✅"

fclean: clean
	@$(RM) $(NAME)

re: fclean all