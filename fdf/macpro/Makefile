NAME = 	fdf.a
EXEC =	fdf
HDRS = 	fdf.h
SRCS = 	fdf.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
MDIR = minilibx
MNAME = libmlx.dylib
MLIB = $(MDIR)/$(MNAME)
FLAGS = -Wall -Werror -Wextra
FLAGM = -L$(MDIR) -lmlx -framework OpenGL -framework AppKit
CC = cc
AR = ar -rcs

all:		$(NAME)		

$(NAME):	$(OBJS)	$(LIBR) $(MLIB)
			$(AR) $(NAME) $(OBJS)
			$(CC) $(FLAGS) $(word 1, $(SRCS)) $(NAME) $(FLAGM) -o $(EXEC)	

%.o:		%.c	
			$(CC) $(FLAGS) -c $< -o $@ -I. -I$(LDIR) -I$(MDIR)
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)

$(MLIB):		
			[ -d $(MDIR) ] && $(MAKE) -C $(MDIR) all -j1
			cp $(MLIB) .
clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean
			$(MAKE) -C $(MDIR) clean

fclean:		clean	
			rm -rf $(NAME)	
			rm -rf $(EXEC)
			rm -rf $(MNAME)
			$(MAKE) -C $(LDIR) fclean
			$(MAKE) -C $(MDIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
