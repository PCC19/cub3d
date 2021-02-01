/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_escolhe_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:38:44 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 01:46:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_escolhe_parse(t_vars *vars, char *str)
{
	printf("p_escolhe_parse %d", vars->cfg.res.x);
	printf("str[0] %c\n", str[0]);
	if (str[0] == 'R')
	{
		printf("R\n");
		p_parse_r(vars,str);
	}
	if (str[0] == 'C')
	{
		printf("C\n");
		p_parse_c(vars,str);
	}
	if (str[0] == 'F')
	{
		printf("F\n");
		p_parse_f(vars,str);
	}
	if (str[0] == 'S' && str[1] != 'O')
	{
		printf("S\n");
		p_parse_S(vars,str);
	}
	if (str[0] == 'S' && str[1] == 'O')
	{
		printf("SO\n");
		p_parse_SO(vars,str);
	}
	if (str[0] == 'N' && str[1] == 'O')
	{
		printf("NO\n");
		p_parse_NO(vars,str);
	}
	if (str[0] == 'W' && str[1] == 'E')
	{
		printf("WE\n");
		p_parse_WE(vars,str);
	}
	if (str[0] == 'E' && str[1] == 'A')
	{
		printf("EA\n");
		p_parse_EA(vars,str);
	}
	p_print_cfg(vars);

}

