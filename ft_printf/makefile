NAME = 	libftprintf.a
HDRS = 	ft_printf.h
SRCS = 	ft_printf.c \
		ft_itoau.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(NAME)		

$(NAME):	$(OBJS)	$(LIBR)
			$(AR) $(NAME) $(OBJS) $(LIBR)	

%.o:		%.c $(HDRS) $(LIBR)	
			$(CC) $(FLAGS) -c $< -o $@ -I. -I$(LDIR)	

$(LIBR):		
			$(MAKE) -C $(LDIR) all	

clean:	
			rm -rf $(OBJS)	gdb
			$(MAKE) -C $(LDIR) clean	

fclean:		clean	
			rm -rf $(NAME)	
			$(MAKE) -C $(LDIR) fclean	

re:			fclean all	

.PHONY:		all clean fclean re