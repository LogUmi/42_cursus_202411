NAME = 	push_swap.a
HDRS = 	push_swap.h
SRCS = 	push_swap.c \
		conformity.c \
		setstack.c \
		ft_swap_push.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(NAME)		

$(NAME):	$(OBJS)	$(LIBR)
			$(AR) $(NAME) $(OBJS)	

%.o:		%.c	
			$(CC) $(FLAGS) -c $< -o $@ -I. -I$(LDIR) 
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all		
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)
clean:	
			rm -rf $(OBJS)
			$(MAKE) -C $(LDIR) clean	

fclean:		clean	
			rm -rf $(NAME)	
			$(MAKE) -C $(LDIR) fclean	

re:			fclean all

.PHONY:		all clean fclean re
