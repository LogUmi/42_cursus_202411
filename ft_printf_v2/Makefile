NAME = 	libftprintf.a
HDRS = 	ft_printf.h
SRCS = 	ft_printf.c ft_printf_string.c ft_printf_number.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(NAME)		

$(NAME):	$(OBJS)	
			$(AR) $(NAME) $(OBJS)	

%.o:		%.c	
			$(CC) $(FLAGS) -c $< -o $@ -I.	

clean:	
			rm -rf $(OBJS)	

fclean:		clean	
			rm -rf $(NAME)	

re:			fclean all

.PHONY:		all clean fclean re