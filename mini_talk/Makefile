NAME = 	minitalk.a
EXE1 =	server
EXE2 =	client
HDRS = 	minitalk.h
SRCS = 	server.c \
		client.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(NAME)		

$(NAME):	$(OBJS)	$(LIBR)
			$(AR) $(NAME) $(OBJS)
			$(CC) $(FLAGS) $(word 1, $(SRCS)) $(NAME) -o $(EXE1)	
			$(CC) $(FLAGS) $(word 2, $(SRCS)) $(NAME) -o $(EXE2)
			
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
			rm -rf $(EXE1)
			$(MAKE) -C $(LDIR) fclean	

re:			fclean all

.PHONY:		all clean fclean re