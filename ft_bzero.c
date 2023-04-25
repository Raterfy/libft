/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:31 by robhak            #+#    #+#             */
/*   Updated: 2023/04/25 13:25:32 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Initialise les n premiers octets de la zone pointée par s à zéro */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
