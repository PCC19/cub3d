/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_valida_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:25:47 by user42            #+#    #+#             */
/*   Updated: 2021/02/06 18:02:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	p_valida_map(t_vars *vars)
{
	int i;
	int j;
	char *linha;

	// Check colunas
	// Percorre todas linhas fazendo trim e checando se 1o e ultimo eh 1 ou sp
	i = 0;
	j = 0;
	printf("map_linhas %d\n", vars->map_linhas);
	while (i < vars->map_linhas)
	{
		linha = ft_strtrim(vars->map[i], " ");
		printf("trimmed  linha: %s\n",linha);
		while (linha[j + 1] != 0)
			j++;
		if (linha[0] != 1 || linha[j] != 1)
		{
			printf("i: %d\t0:%c\tu: %c\tj: %d\n",i,linha[0], linha[j],j);
			free(linha);
			exit(WALL_ERROR);
		}
		free(linha);
		i++;
	}
}
