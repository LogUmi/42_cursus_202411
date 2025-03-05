NAME = 	fdf.a
EXEC =	fdf
HDRS = 	fdf.h
SRCS = 	fdf.c \
		map_load.c \
		init_tools.c \
		preparation.c \
		drawing.c \
		drawing_tools.c\
		map_get.c \
		altitude.c \
		featuring.c \
		key_management.c
OBJS = $(SRCS:.c=.o)
LDIR = libft
LIBR = $(LDIR)/libft.a
MDIR = mlx_linux
MNAME = libmlx_Linux.a
MLIB = $(MDIR)/$(MNAME)
FLAGS = -Wall -Werror -Wextra
FLAGM = -L$(MDIR) -l:$(MNAME) -I$(MDIR) -lXext -lX11 -lm -lz
CC = cc
AR = ar -rcs

all:		$(NAME) $(EXEC)

$(NAME):	$(OBJS)	$(LIBR) $(MLIB) $(HDRS)
			$(AR) $(NAME) $(OBJS)	

%.o:		%.c	
			$(CC) $(FLAGS) -I. -I$(LDIR) -I$(MDIR) -O3 -c $< -o $@ 
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)

$(MLIB):
			[ -d $(MDIR) ] && $(MAKE) -C $(MDIR) all

$(EXEC):	$(SRCS) $(HDRS)
			$(CC) $(FLAG) $(SRCS) $(MLIB) $(NAME) -L. $(FLAGM) -o $(EXEC) -g -lm

clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean

fclean:		clean
			$(MAKE) -C $(LDIR) fclean
			rm -rf $(NAME) $(EXEC)	

re:			fclean all

.PHONY:		all clean fclean re
