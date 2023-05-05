/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:09 by robhak            #+#    #+#             */
/*   Updated: 2023/05/05 10:28:57 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copie au plus size-1 octets de la chaîne src dans la chaîne dest,
   en s'assurant de terminer la chaîne avec le caractère nul */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if (size > 0)
	{
		dstlen = size - 1;
		if (srclen < dstlen)
			ft_memcpy(dst, src, srclen + 1);
		else
		{
			ft_memcpy(dst, src, dstlen);
			dst[dstlen] = '\0';
		}
	}
	return (srclen);
}
