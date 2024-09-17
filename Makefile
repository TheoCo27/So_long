# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 17:29:12 by tcohen            #+#    #+#              #
#    Updated: 2024/09/16 17:47:29 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

SRCS = srcs/main.c srcs/ft_check_arg.c srcs/ft_secure.c srcs/ft_set.c \
	srcs/ft_get_map.c srcs/ft_basic_check.c srcs/ft_error_msg.c \
	srcs/ft_basic_check2.c srcs/ft_clear.c srcs/ft_img_to_window.c \
	srcs/ft_movement.c srcs/ft_put.c srcs/ft_check_small.c srcs/ft_check_big.c
INCLUDES = ./srcs -I ./libft

LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
OBJ_DIR = obj
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = so_long

all: $(MINI_LIBX) $(LIBFT) $(NAME)

# Crée le dossier obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile chaque .o dans le dossier obj
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(MINI_LIBX):
	make -C $(MINI_LIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

clean:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C $(MINI_LIBX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make clean -C $(MINI_LIBX_DIR)

re: fclean all

cleanbis:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C $(MINI_LIBX_DIR)

go: re cleanbis
	clear

.PHONY: all clean fclean re cleanbis go
