NAME = 	libftprintf.a
HDRS = 	ft_printf.h
SRCS = 	ft_printf.c ft_itoabase.c
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
			$(CC) $(FLAGS) -MMD -c $< -o $@ -I. -I$(LDIR) 
			
-include $(OBJS:.o=.d)	

$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all	
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)	

clean:	
			rm -rf $(OBJS) $(OBJS:.o=.d)
			$(MAKE) -C $(LDIR) clean	

fclean:		clean	
			rm -rf $(NAME)	
			$(MAKE) -C $(LDIR) fclean	

re:			fclean all

.PHONY:		all clean fclean re