/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:59:18 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:29:05 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_putchar_fd
** Paramètre(s): char c, int fd
** Valeur de retour: void
** Description: Cette fonction écrit un caractère sur un descripteur de fichier.
** Elle prend en paramètre le caractère à écrire et le descripteur de fichier 
	sur lequel écrire.
** Elle utilise la fonction write pour écrire le caractère.
** Exemple(s):
** ft_putchar_fd('a', 1); // écrit 'a' sur la sortie standard
** ft_putchar_fd('b', 2); // écrit 'b' sur la sortie d'erreur
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
