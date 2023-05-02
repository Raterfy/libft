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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size == 0)
		return (NULL);
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, total_size);
	return (mem);
}
