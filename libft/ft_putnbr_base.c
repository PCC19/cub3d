/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:38:27 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/26 18:34:28 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		tamanho_da_base(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		checa_mais_menos(char *base)
{
	int i;
	int erro;

	erro = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			erro = 1;
		i++;
	}
	return (erro);
}

int		checa_repetidos(char *base)
{
	int i;
	int j;
	int erro;

	erro = 0;
	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && i != j)
				erro = 1;
			j++;
		}
		i++;
	}
	return (erro);
}

int		checa_erros(char *base)
{
	int erro;
	int n_base;

	erro = 0;
	n_base = tamanho_da_base(base);
	if (n_base <= 1)
		erro = 1;
	if (checa_mais_menos(base) == 1)
		erro = 1;
	if (checa_repetidos(base) == 1)
		erro = 1;
	return (erro);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n_base;
	char			d;
	unsigned int	n;

	n = nbr;
	if (checa_erros(base) == 0)
	{
		n_base = tamanho_da_base(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			n = -nbr;
		}
		if (n > n_base - 1)
		{
			ft_putnbr_base(n / n_base, base);
			ft_putnbr_base(n % n_base, base);
		}
		else
		{
			d = base[n];
			write(1, &d, 1);
		}
	}
}
