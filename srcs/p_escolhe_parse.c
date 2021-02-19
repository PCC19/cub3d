/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_escolhe_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:38:44 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 22:03:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_escolhe_parse(t_vars *vars, char *str)
{
	if (str[0] == 'R')
		p_parse_r(vars, str);
	if (str[0] == 'C')
		p_parse_c(vars, str);
	if (str[0] == 'F')
		p_parse_f(vars, str);
	if (str[0] == 'S' && str[1] != 'O')
		p_parse_ss(vars, str);
	if (str[0] == 'S' && str[1] == 'O')
		p_parse_so(vars, str);
	if (str[0] == 'N' && str[1] == 'O')
		p_parse_no(vars, str);
	if (str[0] == 'W' && str[1] == 'E')
		p_parse_we(vars, str);
	if (str[0] == 'E' && str[1] == 'A')
		p_parse_ea(vars, str);
}
