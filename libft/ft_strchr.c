/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:33:37 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/06 18:11:59 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*str;

	str = (char*)s;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			return (&str[i]);
		i++;
	}
	if (c != 0)
		return (NULL);
	else
		return (&str[i]);
}
