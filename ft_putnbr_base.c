/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:40:23 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/15 13:40:25 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_size(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-'
				|| base[i] < 32 || base[i] == 127)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (i);
}

void	*ft_putnbr_base(int nbr, char *base)
{
	long int	size;
	long	nbr2;
	int			i;

	i = 0;
	size = base_size(base);
	if (size < 2)
		return 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr2 = nbr;
		nbr2 = -nbr2;
		i++;
	}
	else
		nbr2 = nbr;
	if (nbr2 >= size)
		ft_putnbr_base(nbr2 / size, base);
	ft_putchar(base[nbr2%size]);
}
