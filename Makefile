# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 14:24:41 by mchanlia          #+#    #+#              #
#    Updated: 2025/07/31 14:24:41 by mchanlia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                Target                                        #
# **************************************************************************** #

NAME = fdf
NAME_BONUS = fdf_bonus

# **************************************************************************** #
#                                Compiler + Flags                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -O0 
MLX_FLAG = -L$(SHARED_DIR) -lmlx -lXext -lX11 -lm -lz
INCLUDES = -I./includes -I./minilibx-linux
INCLUDES_BONUS = -I./bonus -I./minilibx-linux

# **************************************************************************** #
#                                Directories                                   #
# **************************************************************************** #

SRC_DIR = srcs
SHARED_DIR = minilibx-linux
OBJ_DIR = obj
LIBFT_DIR = Libft
BONUS_DIR = bonus

# **************************************************************************** #
#                                Source Files                                  #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/, main.c check_map.c init_map.c handle_errors.c \
								clear_args.c mlx_init.c utils.c utils2.c \
								utils3.c )
SHARED = $(addprefix $(SHARED_DIR)/, )
BONUS_SRC = $(addprefix $(BONUS_DIR)/,main_bonus.c check_map_bonus.c \
									init_map_bonus.c handle_errors_bonus.c \
								clear_args_bonus.c mlx_init_bonus.c \
								utils_bonus.c utils2_bonus.c utils3_bonus.c \
								utils4_bonus.c init_mx_struc_bonus.c )
# **************************************************************************** #
#                                Objects                                       #
# **************************************************************************** #

Objects = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
SHARED_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SHARED:.c=.o)))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

# **************************************************************************** #
#                                Printf                                        #
# **************************************************************************** #

PRINTF = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                Libft                                         #
# **************************************************************************** #

LIBFT = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                Rules                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(Objects) $(SHARED_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(SHARED_DIR)
	$(CC) $(FLAGS) $(INCLUDES) $(Objects) $(SHARED_OBJ) $(LIBFT) $(MLX_FLAG) -o $(NAME)

$(NAME_BONUS) : $(BONUS_OBJ) $(SHARED_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(SHARED_DIR)
	$(CC) $(FLAGS) $(INCLUDES_BONUS) $(BONUS_OBJ) $(SHARED_OBJ) $(LIBFT) $(MLX_FLAG) -o $(NAME_BONUS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ 
# si tu veux supprimer les flags c'est ici

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SHARED_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

# **************************************************************************** #
#                                CLEAN & RE                                    #
# **************************************************************************** #
clean: 
	rm -rf $(Objects) obj
	make clean -C Libft
	rm -rf $(LIBFT_DIR)/libft.a
	make clean -C minilibx-linux

fclean: clean
	rm -rf $(NAME) $(NAME)_bonus

re: fclean all
.PHONY: all clean fclean re