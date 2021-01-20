/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:16:16 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/07 16:55:55 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_a(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen_a(s1);
	len2 = ft_strlen_a(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			str[i] = s1[i];
		if (i < len2)
			str[i + len1] = s2[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
