NAME = 	push_swap.a
HDRS = 	push_swap.h
SRCS = 	push_swap.c \
		conformity.c \
		setstack.c \
		ft_swap_push.c \
		ft_rotate.c \
		ft_reverse.c \
		algo.c \
		execute.c \
		algo_radix.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(NAME)		

$(NAME):	$(OBJS)	$(LIBR)
			$(AR) $(NAME) $(OBJS)
			$(CC) $(FLAGS) push_swap.c $(NAME) -o push_swap	

%.o:		%.c	
			$(CC) $(FLAGS) -c $< -o $@ -I. -I$(LDIR)
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all		
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)
clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean	

fclean:		clean	
			rm -rf $(NAME)	
			rm -rf push_swap
			$(MAKE) -C $(LDIR) fclean	

re:			fclean all

.PHONY:		all clean fclean re
