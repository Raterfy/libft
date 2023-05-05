NAME					= libft.a

SRCS					= ft_atoi.c \
					  ft_bzero.c \
					  ft_calloc.c \
					  ft_isalnum.c \
					  ft_isalpha.c \
					  ft_isascii.c \
					  ft_isdigit.c \
					  ft_isprint.c \
					  ft_itoa.c \
					  ft_memchr.c \
					  ft_memcmp.c \
					  ft_memcpy.c \
					  ft_memmove.c \
					  ft_memset.c \
					  ft_putchar_fd.c \
					  ft_putendl_fd.c \
					  ft_putnbr_fd.c \
					  ft_putstr_fd.c \
					  ft_split.c \
					  ft_strchr.c \
					  ft_strdup.c \
					  ft_striteri.c \
					  ft_strjoin.c \
					  ft_strlcat.c \
					  ft_strlcpy.c \
					  ft_strlen.c \
					  ft_strmapi.c \
					  ft_strncmp.c \
					  ft_strnstr.c \
					  ft_strrchr.c \
					  ft_strtrim.c \
					  ft_substr.c \
					  ft_tolower.c \
					  ft_toupper.c

BNS_SRCS				= ft_lstsize.c \
					  ft_lstadd_back.c \
					  ft_lstadd_front.c \
					  ft_lstclear.c \
					  ft_lstdelone.c \
					  ft_lstiter.c \
					  ft_lstlast.c \
					  ft_lstmap.c \
					  ft_lstnew.c

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

FLAGS					= -Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
			cc $(FLAGS) -c $(SRCS) -I./
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

bonus	:	$(NAME)
		cc $(FLAGS) -c $(BNS_SRCS) -I./
		ar rc $(NAME) $(BNS_OBJS)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re

#so:
#	cc -Wall -Wextra -Werror -fPIC $(SRCS) $(BNS_SRCS) -shared -o libft.so -nostartfiles

#NAME = libft.a
#Définit le nom de la bibliothèque statique qui sera générée.


#SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ... \
	   ft_toupper.c
#Définit la liste des fichiers source qui seront utilisés pour générer les fichiers objets.


#BNS_SRCS = ft_lstsize.c \
		   ft_lstadd_back.c \
		   ... \
		   ft_lstnew.c
#Définit la liste des fichiers source pour les fonctions bonus qui seront utilisés pour générer les fichiers objet

#OBJS = $(SRCS:%.c=%.o)
#Définit la liste des fichiers objets qui seront générés à partir des fichiers source. La syntaxe $(SRCS:%.c=%.o) remplace l'extension ".c" de chaque fichier source dans la liste SRCS par l'extension ".o" pour obtenir la liste des fichiers objets correspondant

#BNS_OBJS = $(BNS_SRCS:%.c=%.o)
#Définit la liste des fichiers objets pour les fonctions bonus qui seront générés à partir des fichiers source pour les fonctions bonus. La syntaxe $(BNS_SRCS:%.c=%.o) remplace l'extension ".c" de chaque fichier source dans la liste BNS_SRCS par l'extension ".o" pour obtenir la liste des fichiers objets correspondants.

#FLAGS = -Wall -Wextra -Werror
#Définit les options du compilateur gcc pour générer les fichiers objets et la bibliothèque.

#$(NAME): $(OBJS)
#	gcc $(FLAGS) -c $(SRCS) -I./
#	ar rc $(NAME) $(OBJS)
#Cible pour générer la bibliothèque. Compile les fichiers source en fichiers objets avec les options de compilation et d'erreur détaillées définies dans FLAGS. Ensuite, utilise la commande ar pour regrouper les fichiers objets dans la bibliothèque statique avec le nom défini dans NAME.

#all: $(NAME)
#Cible par défaut pour générer la bibliothèque. Cette cible dépend de la cible $(NAME) qui génère la bibliothèque.

#bonus: $(NAME)
#	gcc $(FLAGS) -c $(BNS_SRCS) -I./
#	ar rc $(NAME) $(BNS_OBJS)
#Cible pour générer la bibliothèque avec les fonctions bonus. Compile les fichiers source pour les fonctions bonus en fichiers objets avec les options de compilation et d'erreur détaillées définies dans FLAGS. Ensuite, utilise la commande ar pour regrouper les fichiers objets dans la bibliothèque statique avec le nom défini dans NAME.

#clean:
#	rm -f $(OBJS) $(BNS_OBJS)
#Cible pour supprimer les fichiers objets générés à partir des fichiers source.

#fclean: clean
#	rm -f $(NAME)
#Cible pour supprimer les fichiers objets générés et la bibliothèque.

#re: fclean all
#Cible pour supprimer tous les fichiers objets générés et regénérer la bibliothèque*/

#.PHONY	:	all clean fclean re
#La commande .PHONY est une commande spéciale dans un Makefile qui permet de déclarer les cibles qui 
#ne correspondent pas à des fichiers réels. Cela signifie que même si un fichier ou une règle porte le nom 
#d'une cible déclarée dans .PHONY, Make ne cherchera pas de fichier correspondant et exécutera toujours la règle associée à cette cible.

#Dans ce Makefile, les cibles déclarées comme phony sont : all, clean, fclean et re. Cela signifie que si vous tapez l'une de 
#ces commandes dans votre terminal (par exemple, make clean), Make exécutera la règle correspondante même s'il n'y a pas de fichier 
#correspondant à cette cible.

#L'utilisation de .PHONY est utile pour éviter les erreurs et les conflits avec les noms de fichiers réels. 
#Par exemple, si vous avez un fichier nommé "clean" dans votre répertoire de travail, sans la commande .PHONY, 
#Make tentera de construire le fichier "clean" plutôt que d'exécuter la règle de nettoyage correspondante.
