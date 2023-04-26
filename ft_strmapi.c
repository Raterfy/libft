/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:56:37 by robhak            #+#    #+#             */
/*   Updated: 2023/04/26 20:57:16 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Cette fonction applique la fonction 'f' à chaque caractère de la chaîne 's' 
  en passant l'index de chaque caractère en tant que premier 
  argument, et crée une nouvelle chaîne résultant des applications successives de 'f' 
  à l'aide de malloc(3).
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
