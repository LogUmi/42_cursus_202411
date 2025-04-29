# Détection du système d'exploitation
#UNAME_S := $(shell uname -s)

# changement en fonction de l'os je supprime a la fin
#ifeq ($(UNAME_S),Darwin)  # Si c'est macOS
#	READLINE =	-I/opt/homebrew/opt/readline/include \
#				-L/opt/homebrew/opt/readline/lib \
#				-lncurses
#	READLINE_PART = $(word 1, $(READLINE))
#else ifeq ($(UNAME_S),Linux)  # Si c'est Linux
#	READLINE = -lreadline -lhistory
#	READLINE_PART =
#else
#	$(error Unsupported OS)
#endif

NAME = 	philo.a
EXEC =	philo
HDRS = 	philo.h
OBJDIR = obj/
SRCS = 	philo.c 

OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(NAME) $(EXEC)

$(NAME):	$(OBJS)	$(LIBR) $(HDRS)
			$(AR) $(NAME) $(OBJS)	

# Compilation des fichiers .o dans obj/
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) $(READLINE_PART) -I. -I$(LDIR) -c $< -o $@

# Création du dossier obj/ si nécessaire
$(OBJDIR):
	mkdir -p $(OBJDIR)
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)

$(EXEC):	$(SRCS) $(HDRS)
			$(CC) $(FLAGS) $(SRCS) $(NAME) -I. -o $(EXEC) -g

clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean

fclean:		clean
			$(MAKE) -C $(LDIR) fclean
			rm -rf $(NAME) $(EXEC)	

re:			fclean all

.PHONY:		all clean fclean re
