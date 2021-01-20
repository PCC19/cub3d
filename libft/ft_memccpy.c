/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:00:37 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/06 17:06:15 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	cc;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	cc = (unsigned char)c;
	if (dest == NULL && source == NULL && n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == cc)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
