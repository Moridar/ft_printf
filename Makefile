# Makefile for ft_printf
# Auother: Bobbie Syvasalmi
# Version 1.0
# Date: 7/11/2023

#Libary name
NAME = libftprintf.a
LIB = LIBFT

# List of source files
HEADER = libft.h printf.h

SRCS = printf.c conversion.c

#The objects
OBJS = $(SRCS:%.c=%.o)



# CC Flags
CFLAGS = -Wall -Wextra -Werror 

# Default rule - Both basic and bonus
.phony = all
all: $(NAME)

$(NAME): $(OBJS) 
	@make -C $(LIB)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "printf compiled"

$(OBJS):
	@cc $(CFLAGS) -c $(SRCS) -I $(HEADER)

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