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

# **************************************************************************** #
#                                Compiler + Flags                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -O0 
MLX_FLAG = -L$(SHARED_DIR)-lmlx -lXext -lX11 
INCLUDES = -I./includes
INCLUDES_bonus = -I./bonus

# **************************************************************************** #
#                                Directories                                   #
# **************************************************************************** #

SRC_DIR = srcs
SHARED_DIR = minilibx-linux
OBJ_DIR = obj
LIBFT_DIR = Libft
PRINTF_DIR = 
BONUS_DIR = bonus

# **************************************************************************** #
#                                Source Files                                  #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/, main.c )
SHARED = $(addprefix $(SHARED_DIR)/, )
BONUS_SRC = $(addprefix $(BONUS_DIR)/, )
# **************************************************************************** #
#                                Objects                                       #
# **************************************************************************** #

Objects = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
SHARED_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SHARED:.c=.o)))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))
ALL_BONUS_OBJ = $(BONUS_OBJ) $(SHARED_OBJ)

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
	$(CC) $(MLX_FLAG) $(INCLUDES) $(Objects) $(SHARED_OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SHARED_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(ALL_BONUS_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(SHARED_DIR)
	$(CC) $(FLAGS) $(INCLUDES_bonus) $(ALL_BONUS_OBJ) $(LIBFT) -o $(NAME)_bonus

# **************************************************************************** #
#                                CLEAN & RE                                    #
# **************************************************************************** #
clean: 
	rm -rf $(Objects) obj
	make clean -C Libft
	make clean -C minilibx-linux

fclean: clean
	rm -rf $(NAME) $(NAME)_bonus

re: fclean all
.PHONY: all clean fclean re