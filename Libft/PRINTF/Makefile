NAME = libftprintf.a

HEADER = ft_printf.h

SOURCES =	ft_printf.c \
			ft_putchar_int.c \
			ft_putconverted.c \
			ft_putnbr_base_ulong.c \
			ft_putnbr_base_uint.c \
			ft_putnbr_base.c \
			ft_putnbr.c \
			ft_putstr_int.c \
			ft_putvp.c \
			ft_strlen.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_isdigit.c \

Objects = $(SOURCES:.c=.o)

ObjectsBonus = $(SourcesBonus:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SourcesBonus =

all: $(NAME)

$(NAME): $(Objects) 
	$(AR) $(NAME) $(Objects) 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(ObjectsBonus)
	$(AR) $(NAME) $(ObjectsBonus)

clean: 
	$(RM) $(Objects)	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
