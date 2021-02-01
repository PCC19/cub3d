/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 00:25:54 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 01:36:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_parse_f(t_vars *vars, char *str)
{
	char **palavras;
	char *s;
	int i;
	int aux;

	aux = vars->cfg.floor.r;
	str++;
	s = ft_strtrim(str, " ");
	palavras = ft_split(s,',');
	free(s);
	i = 0;
	if (u_check_palavras(palavras, &i) == 1 || i != 3 || aux != -1)
	{
		u_free_array_bi(palavras);
		sai(INVALID_FLOOR);
	}
	vars->cfg.floor.r = ft_atoi(palavras[0]);
	vars->cfg.floor.g = ft_atoi(palavras[1]);
	vars->cfg.floor.b = ft_atoi(palavras[2]);
	vars->cfg.all_set++;
	u_free_array_bi(palavras);
}
