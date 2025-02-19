# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:34:47 by tle-saut          #+#    #+#              #
#    Updated: 2025/01/20 14:43:50 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC = so_long.c utils.c move.c init.c draw.c colision.c check.c enemy.c utils2.c

OBJ = $(SRC:%.c=$(OBJDIR)%.o)
OBJDIR = object/
SRCDIR = source/

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): libft/libft.a $(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft/libft.a 

libft/libft.a:
	@make -C libft

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
