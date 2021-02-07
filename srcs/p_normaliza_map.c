/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_normaliza_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:16:03 by user42            #+#    #+#             */
/*   Updated: 2021/02/07 23:29:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void conta_linhas_cols(t_vars *vars)
{
	int i;
	size_t max_col;
	int n_linhas;

	max_col = 0;
	n_linhas = 0;
	i = 0;
	while(vars->map_temp[i])
	{
		if (ft_strlen(vars->map_temp[i]) > max_col)
			max_col = ft_strlen(vars->map_temp[i]);
		n_linhas ++;
		i++;
	}
	vars->map_num_rows = n_linhas;
	vars->map_num_cols = max_col;

}

void	copia_linha_array(char *destino, char *origem)
{
	int i;

	i = 0;
	if (origem[i] == 0)
		destino[i] = 0;
	else
	{
		while (origem[i])
		{
			destino[i] = origem[i];
			i++;
		}
	}
}

void preenche_com_espacos(t_vars *vars, char *str)
{
	int i;
	
	i = 0;
	while (i < vars->map_num_cols)
	{
		str[i] = ' ';
		i++;
	}
}

void p_normaliza_map(t_vars *vars)
{
	int i;

	conta_linhas_cols(vars);
	vars->map = (char**)malloc(sizeof(char *) * (vars->map_num_rows + 1));

	i = 0;
	while(i < vars->map_num_rows)
	{
		vars->map[i] = ft_calloc(vars->map_num_cols + 1, sizeof(char));
		preenche_com_espacos(vars, vars->map[i]);
		copia_linha_array(vars->map[i], vars->map_temp[i]);
		printf("%d: |%s|\n",i, vars->map[i]);
		free(vars->map_temp[i]);
		i++;
	}
	free(vars->map_temp);
}
