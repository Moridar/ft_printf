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

SRCS = printf.c format.c
BONUS_SRC = printf_bonus.c format_bonus.c format1_bonus.c itoa_hex_bonus.c

#The objects
OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRC:%.c=%.o)

# CC Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default rule - Both basic and bonus
.phony = all
all: manda

.phony = bonus
bonus: $(NAME) $(BONUS_OBJS)
	
.phony = manda
manda: $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -I $(HEADER)
	ar -r $(NAME) $@

$(NAME):
	@make -C $(LIB)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo "created, copied and renamed libftprintf.a"

.phony = clean
clean:
	@rm -rf *.o
	@make -C $(LIB) clean

.phony = fclean
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

.phony = re
re: fclean all