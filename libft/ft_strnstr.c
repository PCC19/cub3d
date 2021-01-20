/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:43:15 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/06 18:47:25 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	res = (char*)haystack;
	if (needle[i] == '\0')
		return (res);
	while (res[i] != '\0' && i < len)
	{
		j = 0;
		while (res[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return (&res[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
