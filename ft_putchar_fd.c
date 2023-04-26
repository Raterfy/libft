/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:59:18 by robhak            #+#    #+#             */
/*   Updated: 2023/04/26 20:59:39 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Cette fonction écrit le caractère 'c' sur le descripteur de fichier donné.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
