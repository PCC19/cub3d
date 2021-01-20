/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:07:28 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/11 15:54:43 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fim_ini(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = len - 1;
	while (i > 0)
	{
		dest[i] = source[i];
		i--;
	}
	dest[0] = source[0];
}

static void	ft_ini_fim(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src && src + len > dst)
	{
		ft_fim_ini(dst, src, len);
	}
	else
	{
		if (src > dst && dst + len > src)
		{
			ft_ini_fim(dst, src, len);
		}
		else
		{
			ft_memcpy(dst, src, len);
		}
	}
	return (dst);
}
