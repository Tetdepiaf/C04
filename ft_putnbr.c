/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:48:27 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/14 16:48:29 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	long int	nbr2;
	int			i;
	int			res;

	i = 0;
	res = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr2 = nbr;
		nbr2 = -nbr2;
		i++;
	}
	else
		nbr2 = nbr;
	if (nbr2 >= 10)
		ft_putnbr(nbr2 / 10);
	res = nbr2 % 10 + 48;
	write(1, &res, 1);
}
