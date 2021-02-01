/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:44:25 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 01:37:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_parse_config(t_vars *vars, int fd)
{
	char *linha;
	char *str;
	int flag;
	int len;

	printf("p_parse_config %d\n", vars->cfg.res.x);
		printf("fd: %d\n",fd);
		//get_next_line(fd, &linha);
		//printf("linha: %s\n",linha);
	flag = 0;
	while (get_next_line(fd, &linha) && vars->cfg.all_set < 9)
	{
		str = ft_strtrim(linha," ");
		len = ft_strlen(str);
		free(linha);
		printf("str:|%s|",str); printf("  len: %zu\n",ft_strlen(str));
		if (len > 0 && !ft_is_in(str[0],"RCFSEWN"))
			flag = 1;
		//free(str);
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
