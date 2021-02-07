/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:32:14 by user42            #+#    #+#             */
/*   Updated: 2021/02/07 19:38:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c(t_vars *vars, int i, int j)
{
	int flag;

	flag = 0;
	if (i >= 0 && i < vars->map_num_rows && j >= 0 && j < vars->map_num_cols)
		flag = 1;
	return (flag);
}

void	check_around_spaces_orto(t_vars *v)
{
	int i;
	int j;

	i = 0;
	while (i < v->map_num_rows)
	{
		j = 0;
		while (j < v->map_num_cols)
		{
			if (v->map[i][j] == ' ')
			{
				if (c(v, i - 1, j) && !ft_is_in(v->map[i - 1][j], " 1"))
					sai(SPACE_ERROR);
				if (c(v, i + 1, j) && !ft_is_in(v->map[i + 1][j], " 1"))
					sai(SPACE_ERROR);
				if (c(v, i, j - 1) && !ft_is_in(v->map[i][j - 1], " 1"))
					sai(SPACE_ERROR);
				if (c(v, i, j + 1) && !ft_is_in(v->map[i][j + 1], " 1"))
					sai(SPACE_ERROR);
			}
			j++;
		}
		i++;
	}
	printf("Spaces orto ok\n");
}

void	check_around_spaces_diag(t_vars *v)
{
	int i;
	int j;

	i = 0;
	while (i < v->map_num_rows)
	{
		j = 0;
		while (j < v->map_num_cols)
		{
			if (v->map[i][j] == ' ')
			{
				if (c(v, i - 1, j - 1) && !ft_is_in(v->map[i - 1][j - 1], " 1"))
					sai(SPACE_ERROR);
				if (c(v, i + 1, j + 1) && !ft_is_in(v->map[i + 1][j + 1], " 1"))
					sai(SPACE_ERROR);
				if (c(v, i + 1, j - 1) && !ft_is_in(v->map[i + 1][j - 1], " 1"))
					sai(SPACE_ERROR);
				if (c(v, i - 1, j + 1) && !ft_is_in(v->map[i - 1][j + 1], " 1"))
					sai(SPACE_ERROR);
			}
			j++;
		}
		i++;
	}
	printf("Spaces diag ok\n");
}
