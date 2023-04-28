/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:52 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 18:46:53 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cherche la première occurrence du caractère c dans la chaîne s,
   renvoie un pointeur vers cette occurrence ou NULL si non trouvé */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	character = c;
	while (*s)
	{
		if (*s == character)
			return ((char *)s);
		++s;
	}
	if (character == '\0')
		return ((char *)s);
	return (NULL);
}
