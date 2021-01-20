/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:10:07 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/07 18:31:40 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_conta_palavras(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*malloc_palavra(char const *s, char c)
{
	char	*palavra;
	int		i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	palavra = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && !(s[i] == c))
	{
		palavra[i] = s[i];
		i++;
	}
	palavra[i] = '\0';
	return (palavra);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;

	if (s == NULL)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (ft_conta_palavras(s, c) + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && !(*s == c))
		{
			out[i] = malloc_palavra(s, c);
			i++;
			while (*s && !(*s == c))
				s++;
		}
	}
	out[i] = NULL;
	return (out);
}
