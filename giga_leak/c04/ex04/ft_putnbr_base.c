/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:40:19 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/04 14:55:04 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	repeated(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < check_base_len(base))
	{
		while (j < check_base_len(base))
		{
			if (base[i] == base[j++])
				return (1);
			if (base[i] == '-' || base[i] == '+')
				return (1);
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	print_num(int nbr, char *base, int len)
{
	if (nbr == -2147483648)
	{
		write (1, "-", 1);
		print_num((nbr / len) * -1, base, len);
		write(1, &base[nbr % len * -1], 1);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		write (1, "-", 1);
	}
	if (nbr < len)
	{
		write(1, &base[nbr % len], 1);
	}
	else
	{
		print_num(nbr / len, base, len);
		write(1, &base[nbr % len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_base_len(base) == 0 || check_base_len(base) == 1)
		return ;
	if (!repeated(base))
		print_num(nbr, base, check_base_len(base));
	return ;
}
