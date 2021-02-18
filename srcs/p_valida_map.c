/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_valida_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:25:47 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:18:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_valida_map(t_vars *vars)
{
	if (vars->map_num_rows < 3 || vars->map_num_cols < 3)
		sai(INVALID_MAP_SIZE);
	check_first_last_col(vars);
	check_first_last_line(vars);
	check_valid_chars_players(vars);
	check_around_spaces_orto(vars);
	check_around_spaces_diag(vars);
}
