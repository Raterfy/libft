/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:13 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 16:16:09 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copie n octets de la zone mémoire src dans la zone mémoire dest,
   les deux zones peuvent se chevaucher */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest_copy;
	const unsigned char	*src_copy;

	if (!dest && !src)
		return (NULL);
	dest_copy = dest;
	src_copy = src;
	if (dest_copy < src_copy)
	{
		while (n-- > 0)
			*dest_copy++ = *src_copy++;
	}
	else
	{
		dest_copy += n;
		src_copy += n;
		while (n-- > 0)
			*--dest_copy = *--src_copy;
	}
	return (dest);
}
