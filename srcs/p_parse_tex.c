/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:27:29 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 21:56:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_ss(t_vars *vars, char *str)
{
	char *p;

	if (vars->cfg.tex_file[4] == NULL)
	{
		p = ft_strtrim(&str[1], " ");
		vars->cfg.tex_file[4] = ft_strdup(p);
		vars->cfg.all_set++;
		free(p);
	}
	else
		sai(DUP_TEX);
}

void	p_parse_so(t_vars *vars, char *str)
{
	char *p;

	if (vars->cfg.tex_file[0] == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		vars->cfg.tex_file[0] = ft_strdup(p);
		vars->cfg.all_set++;
		free(p);
	}
	else
		sai(DUP_TEX);
}

void	p_parse_no(t_vars *vars, char *str)
{
	char *p;

	if (vars->cfg.tex_file[1] == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		vars->cfg.tex_file[1] = ft_strdup(p);
		vars->cfg.all_set++;
		free(p);
	}
	else
		sai(DUP_TEX);
}

void	p_parse_ea(t_vars *vars, char *str)
{
	char *p;

	if (vars->cfg.tex_file[2] == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		vars->cfg.tex_file[2] = ft_strdup(p);
		vars->cfg.all_set++;
		free(p);
	}
	else
		sai(DUP_TEX);
}

void	p_parse_we(t_vars *vars, char *str)
{
	char *p;

	if (vars->cfg.tex_file[3] == NULL)
	{
		p = ft_strtrim(&str[2], " ");
		vars->cfg.tex_file[3] = ft_strdup(p);
		vars->cfg.all_set++;
		free(p);
	}
	else
		sai(DUP_TEX);
}
