#include "libft.h"

/*
Cette fonction prend un entier n comme argument et renvoie une chaîne de caractères représentant l'entier. 
Les nombres négatifs doivent être gérés.
*/
static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

/*Cette fonction applique la fonction 'f' à chaque caractère de la chaîne 's' en passant l'index de chaque caractère en tant que premier 
argument, et crée une nouvelle chaîne résultant des applications successives de 'f' à l'aide de malloc(3).
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*Cette fonction applique la fonction 'f' à chaque caractère de la chaîne 's' en passant 
l'index de chaque caractère en tant que premier argument. Chaque caractère est transmis par adresse à 'f' pour être modifié si nécessaire.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*Cette fonction écrit le caractère 'c' sur le descripteur de fichier donné.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*Cette fonction écrit la chaîne de caractères 's' sur le descripteur de fichier donné.*/
void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

/*Cette fonction écrit la chaîne de caractères 's' suivie d'un saut de ligne sur le descripteur de fichier donné.*/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
Affiche l'entier "n" dans le descripteur de fichier donné.
*/
void	ft_putnbr_fd(int n, int fd)
{
    long int    nbr;

    nbr = n;
    if (nbr < 0)
    {
        write(fd, "-", 1);
        nbr = -nbr;
    }
    if(nbr != 0 && nbr > 9)
        ft_putnbr_fd(nbr / 10, fd);
    ft_putchar_fd(nbr = nbr % 10 + '0', fd);
}

/*Cette fonction crée un nouveau maillon de liste et l'initialise avec le contenu passé en paramètre.*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*Cette fonction ajoute un nouveau maillon de liste au début de la liste passée en paramètre.*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*Cette fonction calcule le nombre de maillons dans la liste passée en paramètre.*/
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/*Cette fonction retourne le dernier maillon de la liste passée en paramètre.*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*Cette fonction ajoute un nouveau maillon de liste à la fin de la liste passée en paramètre.*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

/*Cette fonction supprime le maillon de liste passé en paramètre, en utilisant la fonction de suppression passée en paramètre 
pour supprimer son contenu.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*Cette fonction supprime tous les maillons de liste à partir du maillon passé en paramètre, en utilisant 
la fonction de suppression passée en paramètre pour supprimer leur contenu.*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

/*Le but de la fonction ft_lstiter est d'appliquer la fonction f sur chaque élément de la liste chaînée lst. La fonction f est 
une fonction qui prend en paramètre un pointeur générique void * qui pointe vers le contenu de chaque élément de la liste. 
Ainsi, la fonction ft_lstiter permet d'appliquer une opération spécifique sur chaque élément de la liste.*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*La fonction ft_lstmap prend en entrée une liste chaînée lst et une fonction f qui prend en entrée un élément de la liste 
et retourne un nouvel élément de liste. La fonction ft_lstmap applique la fonction f à chaque élément de la liste lst pour créer une nouvelle liste 
chaînée qui contient les éléments retournés par f. La fonction ft_lstmap retourne un pointeur sur le début de la nouvelle liste chaînée. 
Si l'allocation de mémoire échoue à un moment donné, la fonction ft_lstmap doit supprimer la liste chaînée en cours de création et retourner NULL.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
