/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_argumentos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:34:33 by user42            #+#    #+#             */
/*   Updated: 2021/01/30 17:51:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_parse_argumentos(int argc, char *argv[])
{
	int codigo;
	char *str;
	char *substr;

	codigo = 0;
	// num errado de argumentos
	if (argc < 1 || argc > 3)
		codigo = WRONG_ARGS;
	// nome de arquivo invalido
	if (argc > 0)
	{
		str = ft_strtrim(argv[1]," ./");
		printf("str: %s\n",str);
		// pega substring a partir do ponto
		substr = ft_strrchr(str,'.');
		//free(str);
		printf("subtr: %s\n",substr);
		// compara com .cub
		if (ft_strncmp(".cub",substr,6) != 0)
			codigo = INVALID_FILENAME; 
		free(str);
	}
	// comando invalido 
	if (argc == 3)
	{
		//printf("argv[1] %s\n",argv[2]);
		//printf("ft_strncmp %d\n",ft_strncmp("--save",argv[2],6));
		if (ft_strncmp("--save",argv[2],6) != 0)
			codigo = WRONG_ARGS;
	}
	printf("MENSAGEM\n");
	if (codigo != 0)
	{
		ft_putstr_fd(error[codigo],1);
		exit(codigo);
	}
}

