/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:27 by robhak            #+#    #+#             */
/*   Updated: 2023/04/25 13:27:28 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cherche la dernière occurrence du caractère c dans la chaîne s,
   renvoie un pointeur vers cette occurrence ou NULL si non trouvé */
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last = (char *) s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	else
		return (last);
}
