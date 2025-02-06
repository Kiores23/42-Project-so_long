# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06                                #+#    #+#              #
#    Updated: 2024/02/06                                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = so_long

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Suppression de fichiers
RM = rm -rf

# Libs MiniLibX
MLX_LIB = minilibx-linux
MLX_SRC = minilibx-linux.tgz

# Dossiers des fichiers sources et objets
SRCS_DIR = srcs
OBJS_DIR = objs
UTILS_DIR = $(SRCS_DIR)/utils
GNL_DIR = $(UTILS_DIR)/get_next_line
PRINTF_DIR = $(UTILS_DIR)/printf

# Fichiers sources
SRCS = $(SRCS_DIR)/create_map.c \
	   $(SRCS_DIR)/verif_map.c \
	   $(SRCS_DIR)/input.c \
	   $(SRCS_DIR)/check_coordinates.c \
	   $(SRCS_DIR)/verif_map_utils.c \
	   $(SRCS_DIR)/so_long.c \
	   $(SRCS_DIR)/main.c \
	   $(UTILS_DIR)/ft_len.c \
	   $(UTILS_DIR)/ft_strchr.c \
	   $(UTILS_DIR)/rerror.c \
	   $(GNL_DIR)/get_next_line.c \
	   $(GNL_DIR)/get_next_line_utils.c \
	   $(PRINTF_DIR)/ft_printf.c \
	   $(PRINTF_DIR)/ft_putchar_fd.c \
	   $(PRINTF_DIR)/ft_putnbr_base_fd.c \
	   $(PRINTF_DIR)/ft_putptr_fd.c \
	   $(PRINTF_DIR)/ft_putstr_fd.c

# Fichiers objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Dépendances de la MiniLibX (Linux)
MLX_FLAGS = -L$(MLX_LIB) -lmlx -lXext -lX11 -lm -lbsd

# Commande par défaut
all: $(MLX_LIB) $(NAME)

# Compilation principale
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $@

# Compilation des fichiers .c en .o
$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(SRCS_DIR) -I$(UTILS_DIR) -I$(MLX_LIB) -c $< -o $@

# Décompression et compilation de la MiniLibX si nécessaire
$(MLX_LIB):
	tar -xzf $(MLX_SRC)
	make -C $(MLX_LIB)

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS_DIR)

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)

fclean-all: fclean
	$(RM) $(MLX_LIB)

# Recompilation complète
re: fclean all

# Cibles phony
.PHONY: all clean fclean re
