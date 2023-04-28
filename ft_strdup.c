/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:58 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 11:07:19 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Duplique la chaîne de caractères str en allouant un bloc de mémoire 
   suffisamment grand pour y stocker une copie de str, 
   copie le contenu de str dans le bloc de mémoire alloué, 
   renvoie un pointeur vers le début de ce bloc de mémoire ou NULL 
   si l'allocation a échoué */
char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s) + 1;
	new_str = malloc(len);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s, len);
	return (new_str);
}
