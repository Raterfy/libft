/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:56 by robhak            #+#    #+#             */
/*   Updated: 2023/04/25 13:25:57 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cherche la première occurrence du caractère c 
   dans les n premiers octets de la zone mémoire s,
   renvoie un pointeur vers cette occurrence ou NULL si non trouvé */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n-- > 0)
	{
		if (*p == c)
			return ((void *) p);
		p++;
	}
	return (NULL);
}
