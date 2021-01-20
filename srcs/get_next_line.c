/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:07:42 by pcunha            #+#    #+#             */
/*   Updated: 2020/05/28 13:03:35 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		erro(char **s)
{
	if (s && (*s))
		*s = NULL;
	return (ERRO);
}

void	salva(char *fonte, char *destino, int idx)
{
	int		i;
	int		j;
	char	*d;

	d = destino;
	i = 0;
	j = idx;
	while (fonte && fonte[j])
	{
		d[i] = fonte[j];
		i++;
		j++;
	}
}

int		get_next_line(int fd, char **line)
{
	static char	armazem[OPEN_MAX][BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	int			rd;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (erro(line));
	*line = concat(NULL, armazem[fd]);
	rd = 1;
	while (rd && !tem_barra_n(*line))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0 || !*line)
			return (erro(line));
		buffer[rd] = 0;
		temp = concat(*line, buffer);
		free(*line);
		*line = temp;
	}
	i = extrai(*line);
	zera_armazem(armazem[fd]);
	salva(*line, armazem[fd], i);
	return (rd ? 1 : 0);
}
