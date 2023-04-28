/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:22 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 08:21:38 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction compte le nombre de chaînes de caractères séparées par le délimiteur `c` dans la chaîne `s`
static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

// Cette fonction copie la sous-chaîne de `s` commençant à l'indice `start` d'une longueur `len` dans `dest`
static void	ft_copy_word(char *dest, char const *s, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
}

// Cette fonction prend en entrée une chaîne de caractères `s` et un caractère délimiteur `c`, et retourne un tableau de
// chaînes de caractères obtenu en divisant `s` à chaque occurrence de `c`
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;
	int		len;
	int		nb_words;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < nb_words)
	{
		// On cherche le prochain délimiteur
		while (s[i] == c)
			i++;
		// On met en mémoire l'index du début de la chaîne dans s
		j = i;
		// On cherche la fin de la chaîne en cherchant le prochain délimiteur ou la fin de la chaîne
		while (s[i] != c && s[i] != '\0')
			i++;
		// On calcule la longueur de la chaîne
		len = i - j;
		// On alloue de la mémoire pour la chaîne
		result[k] = (char *)malloc(sizeof(char) * (len + 1));
		if (result[k] == NULL)
			return (NULL);
		// On copie la chaîne dans le tableau de résultat
		ft_copy_word(result[k], s, j, len);
		// On passe à la chaîne suivante
		k++;
	}
	result[nb_words] = NULL;
	return (result);
}
