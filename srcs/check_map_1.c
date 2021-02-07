/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:39:41 by user42            #+#    #+#             */
/*   Updated: 2021/02/07 19:42:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_first_last_col(t_vars *vars)
{
	int		i;
	int		j;
	char	*linha;

	i = 0;
	while (i < vars->map_num_rows)
	{
		linha = ft_strtrim(vars->map[i], " ");
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

void	check_first_last_line(t_vars *vars)
{
	int i;

	i = 0;
	while (vars->map[0][i])
	{
		if (!ft_is_in(vars->map[0][i], " 1"))
			sai(WALL_ERROR);
		i++;
	}
	i = 0;
	while (vars->map[vars->map_num_rows - 1][i])
	{
		if (!ft_is_in(vars->map[vars->map_num_rows - 1][i], " 1"))
			sai(WALL_ERROR);
		i++;
	}
}

void	check_valid_chars_players(t_vars *vars)
{
	int i;
	int j;
	int n_players;

	n_players = 0;
	i = 0;
	while (i < vars->map_num_rows)
	{
		j = 0;
		while (j < vars->map_num_cols)
		{
			if (!ft_is_in(vars->map[i][j], " 012NSEW"))
			{
				sai(INVALID_MAP_CHAR);
			}
			if (ft_is_in(vars->map[i][j], "NSEW"))
				n_players++;
			j++;
		}
		i++;
	}
	printf("\n   n_players: %d   \n", n_players);
	if (n_players != 1)
		sai(INVALID_PLAYER);
}
