/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_normaliza_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:16:03 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 21:34:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_normaliza_map(t_vars *vars)
{
	int n_linhas;
	int i;
	size_t max_col;
	//char *lixo;

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
	
	// Aloca memoria no tamanho certo com valores zero
	vars->map = (char**)malloc(sizeof(char *) * (n_linhas + 1));
	i = 0;
		printf("n_linhas; %d\n",n_linhas);
	while(i < n_linhas + 1)
	{
		vars->map[i] = ft_calloc(max_col + 1, sizeof(char));
//		vars->map[i] = (char *)malloc(sizeof(char) * (max_col + 1));
		printf("map_temp: %s\n",vars->map_temp[i]);
		//printf("map_    : %s\n",vars->map[i]);
		vars->map[i] = ft_strdup(vars->map_temp[i]);
		//lixo = ft_strdup(vars->map_temp[i]);
		//printf("lixo: %s\n",lixo);
		printf("map_    : %s\n",vars->map_temp[i]);
		free(vars->map_temp[i]);
		i++;
	}
	free(vars->map_temp);
	vars->map_linhas = n_linhas;
	vars->map_cols = max_col;

	u_print_map(vars->map);
}

/*	
	
	n_linhas = calcula_linhas_mapa(vars, fd, &linha);

	printf("line_count: %d\n",vars->line_count);
	printf("line_cfg: %d\n",vars->line_cfg);
	printf("tamanho: %d\n", n_linhas);
	printf("linha %s\n",linha);
	vars->map_temp = (char **)malloc(sizeof(char*) * (n_linhas + 1));
	i = 0;
	vars->map_temp[i] = salva_linha(linha);
	i++;
	while (get_next_line(fd, &linha))
	{
		tamanho = ft_strlen(linha);
		if (tamanho > 0)
		{
			vars->map_temp[i] = salva_linha(linha);
			printf("|%s\n",vars->map_temp[i]);
			i++;
		}
	}
	free(linha);
	vars->map_temp[i] = 0;
	print_map(vars->map_temp);
}

*/
