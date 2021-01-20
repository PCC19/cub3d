/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:15:11 by pcunha            #+#    #+#             */
/*   Updated: 2020/05/27 15:31:24 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len(char *s)
{
	int i;

	i = 0;
	while ((s) && (*s))
	{
		i++;
		s++;
	}
	return (i);
}

int		tem_barra_n(char *s)
{
	while ((s) && (*s))
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*concat(char *str_a, char *str_b)
{
	int		i;
	int		j;
	char	*aux;
	char	*a;
	char	*b;

	a = str_a;
	b = str_b;
	if (!(aux = malloc((ft_len(str_a) + ft_len(str_b) + 1) * sizeof(aux))))
		return (NULL);
	i = 0;
	j = 0;
	while (a && a[j])
	{
		aux[i++] = a[j++];
	}
	j = 0;
	while (b && b[j])
	{
		aux[i++] = b[j++];
	}
	aux[i] = '\0';
	return (aux);
}

int		extrai(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		str[i] = '\0';
		i++;
	}
	return (i);
}

void	zera_armazem(char *armazem)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		armazem[i] = '\0';
		i++;
	}
}
