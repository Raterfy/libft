/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:35 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 17:39:19 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue un bloc de mémoire de taille nmemb * size, 
   initialise chaque octet à zéro, renvoie un pointeur vers le début du bloc 
   de mémoire alloué ou NULL si l'allocation a échoué */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_max;

	size_max = (size_t)-1;
	if (size_max / count < size)
		return (NULL);
	if (size == 0 || count == 0)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
