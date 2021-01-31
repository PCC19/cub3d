/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_escolhe_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:38:44 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 00:19:55 by user42           ###   ########.fr       */
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
	p_print_cfg(vars);

}

