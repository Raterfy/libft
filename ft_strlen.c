/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:12 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 11:08:26 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Retourne la longueur de la chaîne de caractères s 
   (sans compter le caractère nul) */
size_t	ft_strlen(const char *s)
{
	const char	*len;

	len = s;
	while (*len != '\0')
		len++;
	return (len - s);
}
