NAME = philosophers
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_inc = libft.a 
SRCS = 	src/philosophers.c ft_usleep.c
OBJ = $(SRCS:.c=.o)
$(NAME): $(OBJ)
	@make $(SRCS_inc)
	@$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a  -o $(NAME)
	@echo Philosophers compilation done !
all :
	@make philosophers
	@echo Compilation done !
libft.a :
	@make all -C ./libft
	@echo Libft compilation done !
fclean : clean
	@rm -f $(NAME)
clean :
	@rm -f $(OBJ) /libft/obj
re : fclean all

.PHONY: clean fclean all re

