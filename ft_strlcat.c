/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:05 by robhak            #+#    #+#             */
/*   Updated: 2023/04/25 13:27:06 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Concatène la chaîne src à la fin de la chaîne dest,
   en s'assurant que la chaîne résultante est toujours terminée 
   par un caractère nul */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	remaining;

	dstlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (size + srclen);
	remaining = size - dstlen - 1;
	if (srclen < remaining)
		ft_memcpy(dest + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + dstlen, src, remaining);
		dest[size - 1] = '\0';
	}
	return (dstlen + srclen);
}
