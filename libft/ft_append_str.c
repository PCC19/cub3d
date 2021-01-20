/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:22:57 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/26 18:27:35 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_b(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void		ft_append_str(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	len1 = ft_strlen_b(s1);
	len2 = ft_strlen_b(s2);
	str = (char *)malloc(len1 + len2 + 1);
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
	s1 = str;
	free(str);
}
