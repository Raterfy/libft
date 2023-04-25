/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:22 by robhak            #+#    #+#             */
/*   Updated: 2023/04/25 13:26:23 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Cette fonction prend une chaîne de caractères s et un caractère 
  c comme arguments et renvoie un tableau de nouvelles chaînes obtenues 
  en divisant s en utilisant c comme délimiteur. Le tableau se termine 
  par un pointeur NULL. */
/*static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		wc;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	wc = ft_wordcount(s, c);
	strs = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!strs)
		return (NULL);
	i = -1;
	while (++i < wc)
	{
		while (*s == c && *s)
			s++;
		strs[i] = (char *)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
		if (!strs[i])
			return (NULL);
		j = 0;
		while (*s && *s != c)
			strs[i][j++] = *s++;
		strs[i][j] = '\0';
	}
	strs[i] = NULL;
	return (strs);
}*/

#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
			count += (in_word = 1);
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return count;
}

static char *ft_next_word(char const *s, char c)
{
    while (*s && *s == c)
        s++;
    return (char *)s;
}

static size_t ft_word_len(char const *s, char c)
{
    size_t len = 0;
    while (*s && *s != c)
        len++, s++;
    return len;
}

static char *ft_strndup(char const *s, size_t n)
{
    char *new_str = malloc(n + 1);
    size_t i = 0;
    if (new_str == NULL)
        return NULL;
    while (i < n && s[i])
        new_str[i] = s[i], i++;
    new_str[i] = '\0';
    return new_str;
}

char **ft_split(char const *s, char c)
{
    int num_words = ft_count_words(s, c);
    char **words = malloc((num_words + 1) * sizeof(*words));
    int i = 0;
    if (words == NULL || s == NULL)
        return NULL;
    while (i < num_words)
    {
        s = ft_next_word(s, c);
        words[i] = ft_strndup(s, ft_word_len(s, c));
        if (words[i++] == NULL)
            while (i > 0)
                free(words[--i]), free(words), words = NULL;
        s += ft_word_len(s, c);
    }
    if (words != NULL)
        words[num_words] = NULL;
    return words;
}