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

int	puissance10(int n)
{
	int	i;
	int	d;

	i = 0;
	d = 1;
	while (i < n)
	{
		d *= 10;
		i++;
	}
	return (d);
}

int	size(int nb, int n)
{
	if (nb < 0)
		nb = -nb;
	while (nb / 10 >= 1)
	{
		n++;
		nb = nb / 10;
	}
	return (n);
}

void	print(int nb, int n)
{
	int	a;
	int	i;

	i = 0;
	while (i <= n)
	{
		a = (nb / puissance10(n - i)) + 48;
		write(1, &a, 1);
		nb = nb % puissance10(n - i);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int	n;

	n = 0;
	n = size(nb, n);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		print(nb, n);
	}
	else
		print(nb, n);
}
