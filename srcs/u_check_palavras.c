/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_check_palavras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 00:17:00 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:20:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	u_check_palavras(char **palavras, int *ii)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (palavras[i] != 0)
	{
		if (!ft_isnum(palavras[i]))
			flag = 1;
		i++;
	}
	*ii = i;
	return (flag);
}
