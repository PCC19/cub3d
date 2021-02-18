/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_argumentos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:34:33 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 16:04:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_argumentos(int argc, char *argv[])
{
	int		codigo;
	char	*str;
	char	*substr;

	codigo = 0;
	if (argc < 2 || argc > 3)
		codigo = WRONG_ARGS;
	if (argc == 2)
	{
		str = ft_strtrim(argv[1], " ./");
		substr = ft_strrchr(str, '.');
		if (ft_strncmp(".cub", substr, 6) != 0)
			codigo = INVALID_FILENAME;
		free(str);
	}
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 6) != 0)
			codigo = WRONG_ARGS;
	}
	if (codigo != 0)
	{
		sai(codigo);
	}
}
