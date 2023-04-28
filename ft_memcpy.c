/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:06 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 16:16:00 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copie les n premiers octets de la zone mémoire 
   src dans la zone mémoire dest */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	dest_cpy = dest;
	src_cpy = src;
	while (n-- > 0)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
