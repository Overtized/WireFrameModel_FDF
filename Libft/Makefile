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
#                                variables                                     #
# **************************************************************************** #

AR = ar rcs
DIRS = GNL LIBFT PRINTF
LIB_NAMES = GNL/GNL.a LIBFT/libft.a PRINTF/libftprintf.a

# **************************************************************************** #
#                                Rules                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIB_NAMES)
	@cp $(word 1, $^) $(NAME)
	@for lib in $(wordlist 2, $(words $^), $^); do \
		ar -x $$lib; \
	done
	@ar rcs $(NAME) *.o
	@rm -f *.o

$(LIB_NAMES):
	@$(MAKE) -C $(dir $@)

# **************************************************************************** #
#                                CLEAN & RE                                    #
# **************************************************************************** #
clean:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	@rm -f $(NAME)
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all
.PHONY: all clean fclean re
#                  ┌─────────────────────────┐
#                 │     Root Makefile        │
#                 │      (My_Libft)          │
#                 └───────────┬─────────────┘
#                             │
#                             ▼
#          ┌────────────────────────────────────────┐
#          │  all: $(NAME) → libft.a                │
#          └─────────────────┬──────────────────────┘
#                             │
#       ┌─────────────────────┴───────────────────────┐
#       ▼                                             ▼
# Build sub-libs                                Wait for sub-libs
# (automatic if missing)                        (if already built)
#  ┌──────────────┐    ┌──────────────┐    ┌───────────────────┐
#  │ GNL/Makefile │    │ LIBFT/Makefile │    │ PRINTF/Makefile │
#  │    → GNL.a   │    │ → libft.a     │    │ → libftprintf.a │
#  └───────┬──────┘    └──────┬───────┘    └─────────┬────────┘
#          │                  │                      │
#          ▼                  ▼                      ▼
#    GNL/GNL.a         LIBFT/libft.a          PRINTF/libftprintf.a
#          └──────────────────┬──────────────────────┘
#                             ▼
#          ┌────────────────────────────────────────┐
#          │  Merge into root libft.a               │
#          │----------------------------------------│
#          │  1. Copy first lib   → cp GNL/GNL.a libft.a
#          │  2. Extract others   → ar -x LIBFT/libft.a
#          │                       ar -x PRINTF/libftprintf.a
#          │  3. Repack all objs  → ar rcs libft.a *.o
#          │  4. Remove *.o       → rm -f *.o
#          └────────────────────────────────────────┘