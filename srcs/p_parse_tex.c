/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:27:29 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 01:50:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_parse_S(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.sprite_tex == NULL)
	{
		p = ft_strtrim(&str[1], " ");
		printf("p: %s\n",p);
		vars->cfg.sprite_tex = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_SO(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.so_tex == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.so_tex = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_NO(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.no_tex == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.no_tex = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_WE(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.we_tex == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.we_tex = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_EA(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.ea_tex == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.ea_tex = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}
/*

	p = ft_strtim(str[2], " ");
	if (str[0] == 'N' && str[1] == 'O' && vars->cfg.no_tex != NULL)
		vars->cfg.no_tex = p;
	if (str[0] == 'S' && str[1] == 'O' && vars->cfg.so_tex != NULL)
		vars->cfg.so_tex = p;
	if (str[0] == 'E' && str[1] == 'A' && vars->cfg.ea_tex != NULL)
		vars->cfg.ea_tex = p;
	if (str[0] == 'W' && str[1] == 'E' && vars->cfg.we_tex != NULL)
		vars->cfg.we_tex = p;



}
*/

