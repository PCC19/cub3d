/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:58:45 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/11 16:04:22 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	int a;

	a = (c >= 97 && c <= 122) ? 1 : 0;
	return (a);
}

static int	ft_isupper(int c)
{
	int a;

	a = (c >= 65 && c <= 90) ? 1 : 0;
	return (a);
}

int			ft_isalpha(int c)
{
	int a;

	a = (ft_islower(c) || ft_isupper(c)) ? 1 : 0;
	return (a);
}
