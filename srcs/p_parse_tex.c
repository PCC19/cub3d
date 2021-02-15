/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:27:29 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 16:06:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_parse_S(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.tex_file[4] == NULL)
	{
		p = ft_strtrim(&str[1], " ");
		printf("p: %s\n",p);
		vars->cfg.tex_file[4] = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_SO(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.tex_file[4]== NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.tex_file[0] = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_NO(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.tex_file[1] == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.tex_file[1] = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_EA(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.tex_file[2] == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.tex_file[2] = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}

void p_parse_WE(t_vars *vars, char *str)
{
	char *p;
		
	if (vars->cfg.tex_file[3] == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		printf("p: %s\n",p);
		vars->cfg.tex_file[3] = ft_strdup(p);
		vars->cfg.all_set++;
		free (p);
	}
	else
		sai(DUP_TEX);
}
