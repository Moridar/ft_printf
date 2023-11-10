# Makefile for ft_printf
# Auother: Bobbie Syvasalmi
# Version 1.0
# Date: 7/11/2023

#Libary name
NAME = libftprintf.a
LIB = LIBFT

# List of source files
HEADER = libft.h ft_printf.h
BONUS_HEADER = libft.h ft_printf_bonus.h

SRCS = printf.c conversion.c
BONUS_SRC = printf_bonus.c conversion_bonus.c conversion1_bonus.c ft_itoa_hex.c

#The objects
OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRC:%.c=%.o)

# CC Flags
CFLAGS = -Wall -Wextra -Werror 

# Default rule - Both basic and bonus
.phony = all
all: manda

.phony = bonus
bonus: $(NAME) $(BONUS_OBJS)
	
.phony = manda
manda: $(NAME) $(OBJS)

$(NAME):
	@make -C $(LIB)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo "created, moved and renamed libftprintf.a"

%.o: %.c
	@cc $(CFLAGS) -c $< -I $(HEADER)
	ar rc $(NAME) $@
	@ranlib $(NAME)

.phony = clean
clean:
	@rm -rf *.o
	@make -C $(LIB) clean

.phony = fclean
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB) fclean

.phony = re
re: fclean all