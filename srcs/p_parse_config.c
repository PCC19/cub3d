/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:44:25 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:09:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_config(t_vars *vars, int fd)
{
	char	*linha;
	char	*str;
	int		flag;
	int		len;

	flag = 0;
	while (vars->cfg.all_set < 8 && get_next_line(fd, &linha))
	{
		vars->line_cfg++;
		str = ft_strtrim(linha, " ");
		len = ft_strlen(str);
		free(linha);
		if (len > 0 && !ft_is_in(str[0], "RCFSEWN"))
			flag = 1;
		if (flag)
		{
			free(str);
			sai(INVALID_CMD);
		}
		else
		{
			p_escolhe_parse(vars, str);
			free(str);
		}
	}
}
