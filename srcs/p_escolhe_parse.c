/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_escolhe_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:38:44 by user42            #+#    #+#             */
/*   Updated: 2021/01/31 20:01:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_escolhe_parse(t_vars *vars, char *str)
{
	printf("p_escolhe_parse %d", vars->cfg.res.x);
	printf("str[0] %c\n", str[0]);
	if (str[0] == 'R')
		printf("R\n");
		//p_parse_r(vars,str);
}

