/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:19 by robhak            #+#    #+#             */
/*   Updated: 2023/04/25 13:27:20 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cherche la première occurrence de la sous-chaîne needle 
   de longueur n dans la chaîne haystack, renvoie un pointeur 
   vers le début de cette occurrence ou NULL si non trouvé */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (n-- >= needle_len)
	{
		if (*haystack == *needle
			&& ft_memcmp(haystack, needle, needle_len) == 0)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
