/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:46:32 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/26 18:30:06 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_conta(long long int n)
{
	int				i;
	long long int	a;

	a = n;
	i = 1;
	while (a / 10 != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(long long int n)
{
	int						i;
	char					*c;
	int						s;
	long long unsigned int	nn;

	nn = (n < 0) ? (-1) * (long long unsigned int)n : (long long unsigned int)n;
	i = ft_conta(nn);
	s = 0;
	if (n < 0)
		s = 1;
	c = (char *)malloc(i + 1 + s);
	if (c == NULL)
		return (NULL);
	c[i + s] = 0;
	while (i > 0)
	{
		c[i + s - 1] = (nn % 10) + '0';
		nn = nn / 10;
		i--;
	}
	if (s == 1)
		c[0] = '-';
	return (c);
}
