/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:27 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 18:46:30 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cherche la dernière occurrence du caractère c dans la chaîne s,
   renvoie un pointeur vers cette occurrence ou NULL si non trouvé */
char	*ft_strrchr(const char *s, int c)
{
	const char		*p;
	unsigned char	character;

	character = c;
	if (character == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	p = NULL;
	while (*s)
	{
		if (*s == character)
			p = s;
		s++;
	}
	return ((char *)p);
}
