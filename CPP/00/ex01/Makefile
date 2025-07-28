NAME = megaphone
OBJ = obj
OBJDIR = obj/
SRCDIR = src/
FILEC =	megaphone.cpp
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(FILEC))
SRCS = $(addprefix	$(SRCDIR),	$(FILEC))
FLAGS = -Wall -Werror -Wextra -g -std=c++98
CC = c++

all:		init_dirs	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "comgit pilation completed, exec $(NAME) ready."

# Compilation des fichiers .o dans obj/
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

# Création du dossier obj/ si nécessaire
init_dirs:
			@mkdir -p $(OBJDIR)

clean:		
			@rm -rf	$(OBJS)
			@echo "Make clean command executed."

fclean:		clean
			@rm -rf $(NAME)
			@echo "Make fclean command executed."

re:			fclean all

.PHONY:		all clean fclean re
