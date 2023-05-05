/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:19 by robhak            #+#    #+#             */
/*   Updated: 2023/05/05 12:56:55 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cherche la première occurrence de la sous-chaîne little 
   de longueur len dans la chaîne big, renvoie un pointeur 
   vers le début de cette occurrence ou NULL si non trouvé */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(little);
	if (needle_len == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (*big && len-- >= needle_len)
	{
		if (*big == *little
			&& ft_memcmp(big, little, needle_len) == 0)
			return ((char *) big);
		big++;
	}
	return (NULL);
}
