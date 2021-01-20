/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:48:23 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/07 17:49:46 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*out;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isin(s1[start], (char *)set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_isin(s1[end], (char *)set))
		end--;
	if (end - start == 0)
	{
		out = (char *)malloc(end + 1);
		if (out == NULL)
			return (NULL);
		out = (char *)s1;
		return (out);
	}
	out = (char *)malloc(end - start + 1);
	if (out == NULL)
		return (NULL);
	out = ft_substr(s1, start, end - start + 1);
	return (out);
}
