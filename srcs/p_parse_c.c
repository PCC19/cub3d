/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 23:55:53 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:08:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_c(t_vars *vars, char *str)
{
	char	**palavras;
	char	*s;
	int		i;
	int		aux;

	aux = vars->cfg.ceiling.r;
	str++;
	s = ft_strtrim(str, " ");
	palavras = ft_split(s, ',');
	free(s);
	i = 0;
	while (palavras[i] != 0)
		i++;
	if (u_check_palavras(palavras, &i) == 1 || i != 3 || aux != -1)
	{
		u_free_array_bi(palavras);
		sai(INVALID_CEILING);
	}
	vars->cfg.ceiling.r = ft_atoi(palavras[0]);
	vars->cfg.ceiling.g = ft_atoi(palavras[1]);
	vars->cfg.ceiling.b = ft_atoi(palavras[2]);
	vars->cfg.all_set++;
	u_free_array_bi(palavras);
}
