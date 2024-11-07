/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:17:26 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/19 14:59:38 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	print_comb(char *a, char *b, char *c, char *d);

void	print_comb(char *a, char *b, char *c, char *d)
{
	write(1, a, 1);
	write(1, b, 1);
	write(1, " ", 1);
	write(1, c, 1);
	write(1, d, 1);
	if (*a != '9' || *b != '8' || *c != '9' || *d != '9')
		write(1, ", ", 2);
	*d += 1;
}

void	init_comb(char *a, char *b, char *c, char *d)
{
	*a = '0';
	*b = '0';
	*c = '0';
	*d = '1';
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	init_comb(&a, &b, &c, &d);
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				while (d <= '9')
					print_comb(&a, &b, &c, &d);
				c++;
				d = '0';
			}
			c = a;
			d = ++b + 1;
		}
		b = '0';
		d = b + 1;
		c = ++a;
	}
}
