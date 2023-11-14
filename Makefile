# Makefile for ft_printf
# Auother: Bobbie Syvasalmi
# Version 1.0
# Date: 7/11/2023

#Libary name
NAME = libftprintf.a
LIB = libft/libft.a

#Library dir
LIBDIR = libft

# List of source files
HEADER = libft.h ft_printf.h ft_printf_bonus.h
BONUS_HEADER = libft.h ft_printf_bonus.h

SRCS = ft_printf.c ft_printf_format.c
BONUS_SRC = ft_printf_bonus.c ft_printf_cs_bonus.c ft_printf_dipux_bonus.c ft_itoa_type_bonus.c ft_printf_helpers_bonus.c
LIBFT_SRC = $(wildcard libft/*.c)
#The objects
OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRC:%.c=%.o)

# CC Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default rule - Both basic and bonus
.phony = all
all: manda

$(NAME): all

.phony = bonus
bonus: $(LIB) $(BONUS_OBJS)

.phony = manda
manda: $(LIB) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -I $(HEADER)
	ar rus $(NAME) $@

$(LIB): $(LIBFT_SRC)
	make -C $(LIBDIR)
	cp libft/libft.a .
	mv libft.a $(NAME)

.phony = clean
clean:
	@rm -rf *.o
	@make -C $(LIBDIR) clean

.phony = fclean
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

.phony = re
re: fclean all