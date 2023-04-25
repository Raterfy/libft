/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:54 by robhak            #+#    #+#             */
/*   Updated: 2023/04/25 13:25:55 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Retourne 1 si le caractère c est un caractère 
   imprimable (affichable), 0 sinon */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
