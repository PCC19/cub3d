/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:00:02 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/07 19:03:37 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*out;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	out = (char *)malloc(len + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
