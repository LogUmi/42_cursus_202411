NAME = 	minishell.a
EXEC =	minishell
HDRS = 	minishell.h
SRCS = 	minishell.c \
		signals.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(NAME) $(EXEC)

$(NAME):	$(OBJS)	$(LIBR) $(HDRS)
			$(AR) $(NAME) $(OBJS)	

%.o:		%.c	
			$(CC) $(FLAGS) -I. -I$(LDIR) -c $< -o $@ 
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)

$(EXEC):	$(SRCS) $(HDRS)
			$(CC) $(FLAGS) $(SRCS) $(NAME) -I. -o $(EXEC) -g -lreadline

clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean

fclean:		clean
			$(MAKE) -C $(LDIR) fclean
			rm -rf $(NAME) $(EXEC)	

re:			fclean all

.PHONY:		all clean fclean re
