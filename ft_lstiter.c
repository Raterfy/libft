/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:13:03 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 11:41:44 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Le but de la fonction ft_lstiter est d'appliquer la fonction f sur 
 chaque élément de la liste chaînée lst. La fonction f est une fonction 
 qui prend en paramètre un pointeur générique void * qui pointe vers le contenu 
 de chaque élément de la liste. Ainsi, la fonction ft_lstiter 
 permet d'appliquer une opération spécifique sur chaque élément de la liste.*/
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
