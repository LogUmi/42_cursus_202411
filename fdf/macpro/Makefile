NAME = 	fdf.a
EXEC =	fdf
HDRS = 	fdf.h
SRCS = 	fdf.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
MDIR = mlx
MNAME = libmlx.a
MLIB = $(MDIR)/$(MNAME)
FLAGS = -Wall -Werror -Wextra
FLAGM = -L$(MDIR) -l$(MDIR) -framework OpenGL -framework AppKit
CC = cc
AR = ar -rcs

all:		$(NAME) $(EXEC)

$(NAME):	$(OBJS)	$(LIBR) $(MLIB)
			$(AR) $(NAME) $(OBJS)	

%.o:		%.c	
			$(CC) $(FLAGS) -c $< -o $@ -I. -I$(LDIR) -I$(MDIR)
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)

$(MLIB):
			[ -d $(MDIR) ] && $(MAKE) -C $(MDIR) all

$(EXEC):	$(EXEC:=.c) $(HDRS)
			$(CC) $(FLAGS) $(FLAGM) $(word 1, $(SRCS)) $(NAME) -o $(EXEC)

clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean
			$(MAKE) -C $(MDIR) clean

fclean:		clean
			$(MAKE) -C $(LDIR) fclean
			rm -rf $(NAME) $(EXEC)	

re:			fclean all

.PHONY:		all clean fclean re
