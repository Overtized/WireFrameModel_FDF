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

NAME = libft.a

# **************************************************************************** #
#                                Compiler + Flags                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror 
INCLUDES = -I./

# **************************************************************************** #
#                                Directories                                   #
# **************************************************************************** #

SRC_DIR = ./
SHARED_DIR = ./
OBJ_DIR = obj
LIBFT_DIR = LIBFT
PRINTF_DIR = PRINTF
GNL_DIR = GNL
BONUS_DIR = ./

# **************************************************************************** #
#                                Source Files                                  #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/, ft_atoi.c \
								ft_bzero.c \
								ft_calloc.c \
								ft_isalnum.c \
								ft_isspace.c \
								ft_isdigit_space.c \
								ft_ishex.c \
								ft_isalpha.c \
								ft_isascii.c \
								ft_isdigit.c \
								ft_isprint.c \
								ft_itoa.c \
								ft_safe_close.c \
								ft_lstadd_back.c \
								ft_lstadd_front.c \
								ft_lstclear.c \
								ft_lstdelone.c \
								ft_lstiter.c \
								ft_lstlast.c \
								ft_lstmap.c \
								ft_lstnew.c \
								ft_lstsize.c \
								ft_memchr.c \
								ft_memcmp.c \
								ft_memcpy.c \
								ft_memmove.c \
								ft_memset.c \
								ft_free_double_char.c \
								ft_putchar_fd.c \
								ft_putendl_fd.c \
								ft_putnbr_fd.c \
								ft_putstr_fd.c \
								ft_split.c \
								ft_strchr.c \
								ft_strdup.c \
								ft_striteri.c \
								ft_strjoin.c \
								ft_strlcat.c \
								ft_strlcpy.c \
								ft_strcpy.c \
								ft_strlen.c \
								ft_strmapi.c \
								ft_strncmp.c \
								ft_strcmp.c \
								ft_strnstr.c \
								ft_strrchr.c \
								ft_strtrim.c \
								ft_substr.c \
								ft_tolower.c \
								ft_toupper.c )
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
#                                Gnl                                         #
# **************************************************************************** #

LIBFT = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                Rules                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(Objects) $(SHARED_OBJ)
	$(AR) $(NAME) $(Objects) $(SHARED_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SHARED_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

# **************************************************************************** #
#                                CLEAN & RE                                    #
# **************************************************************************** #
clean: 
	rm -rf $(Objects) obj

fclean: clean
	rm -rf $(NAME) $(NAME)_bonus

re: fclean all
.PHONY: all clean fclean re