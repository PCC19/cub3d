/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lixo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:16:03 by user42            #+#    #+#             */
/*   Updated: 2021/02/04 02:47:58 by user42           ###   ########.fr       */
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

void	copia_linha_array(char *destino, int linha, char *origem)
{
	int i;

	i = 0;
	while (origem[i])
	{
		destino[i] = origem[i];
	i++;
	}
}

void preenche_com_espacos(t_vars *vars)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < vars->map_num_rows - 1)
	{
		while (j  < vars->map_num_cols -1 )
		{
			vars->map[i][j] = ' ';
			j++;
		}
	i++;
	}
}

void p_normaliza_map(t_vars *vars)
{
	int i;
	int j;

	conta_linhas_cols(vars);
	vars->map = (char**)malloc(sizeof(char *) * (vars->map_num_rows + 1));
	preenche_com_espacos(vars);

	i = 0;
	while(i < vars->map_num_rows + 1)
	{
		vars->map[i] = ft_calloc(vars->map_num_cols + 1, sizeof(char));
		printf("a: |%s|\n",vars->map[i]);
//		vars->map[i] = (char *)malloc(sizeof(char) * (max_col + 1));
		//vars->map[i] = ft_strdup(vars->map_temp[i]);
		copia_linha_array(vars->map[i], i, vars->map_temp[i]);
		printf("d: |%s|\n",vars->map[i]);
		free(vars->map_temp[i]);
		i++;
	}
	free(vars->map_temp);
}
