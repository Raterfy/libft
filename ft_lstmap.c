/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:13:33 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:00:46 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La fonction ft_lstmap prend en entrée une liste chaînée 
lst et une fonction f qui prend en entrée un élément de la liste 
et retourne un nouvel élément de liste. La fonction ft_lstmap 
applique la fonction f à chaque élément de la liste lst pour 
créer une nouvelle liste chaînée qui contient les éléments retournés par f. 
La fonction ft_lstmap retourne un pointeur sur le début de 
la nouvelle liste chaînée. Si l'allocation de mémoire échoue à un moment donné, 
la fonction ft_lstmap doit supprimer la liste chaînée 
en cours de création et retourner NULL.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
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
