/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:28:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:13:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_r(t_vars *vars, char *str)
{
	char	**palavras;
	char	*s;
	int		i;

	str++;
	s = ft_strtrim(str, " ");
	palavras = ft_split(s, ' ');
	free(s);
	i = 0;
	while (palavras[i] != 0)
		i++;
	if (u_check_palavras(palavras, &i) == 1 || i != 2 || vars->cfg.res.x != -1)
	{
		u_free_array_bi(palavras);
		sai(INVALID_RES);
	}
	vars->cfg.res.x = ft_atoi(palavras[0]);
	vars->cfg.res.y = ft_atoi(palavras[1]);
	vars->cfg.all_set++;
	u_free_array_bi(palavras);
}
