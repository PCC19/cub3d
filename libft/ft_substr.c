/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:00:55 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/12 13:04:47 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	if (!(substr = malloc((len + 1) * sizeof(char))))
		return (0);
	while ((i < len) && ((size_t)start + i) < ft_strlen(s))
	{
		substr[i] = s[(size_t)start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
