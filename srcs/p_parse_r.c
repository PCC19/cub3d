/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:28:35 by user42            #+#    #+#             */
/*   Updated: 2021/01/31 22:34:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_parse_r(t_vars *vars, char *str)
{
	char **palavras;
	char *s;
	int i;

	str++;
	s = ft_strtrim(str, " ");
	palavras = ft_split(s,",");
	i = 0;
	while(palavras[i][] != 0)
	{
		printf("palavra %d: %s\n",i,palavra[i][]);
		i++;
	}
}


	



}

