/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:39:41 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 00:36:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_first_last_col(t_vars *v)
{
	int		i;
	int		j;
	char	*linha;

	i = 0;
	while (i < v->map_num_rows)
	{
		linha = ft_strtrim(v->map[i], " ");
		j = 0;
		while (linha[j + 1] != 0)
			j++;
		if (linha[0] != '1' || linha[j] != '1')
		{
			free(linha);
			sai(WALL_ERROR);
		}
		free(linha);
		i++;
	}
}

void	check_first_last_line(t_vars *v)
{
	int i;

	i = 0;
	while (v->map[0][i])
	{
		if (!ft_is_in(v->map[0][i], " 1"))
			sai(WALL_ERROR);
		i++;
	}
	i = 0;
	while (v->map[v->map_num_rows - 1][i])
	{
		if (!ft_is_in(v->map[v->map_num_rows - 1][i], " 1"))
			sai(WALL_ERROR);
		i++;
	}
}

void	check_valid_chars_players(t_vars *v)
{
	int i;
	int j;
	int n_players;

	n_players = 0;
	i = 0;
	while (i < v->map_num_rows)
	{
		j = 0;
		while (j < v->map_num_cols)
		{
			if (!ft_is_in(v->map[i][j], " 012NSEW"))
			{
				sai(INVALID_MAP_CHAR);
			}
			if (ft_is_in(v->map[i][j], "NSEW"))
				n_players++;
			j++;
		}
		i++;
	}
	if (n_players != 1)
		sai(INVALID_PLAYER);
}
