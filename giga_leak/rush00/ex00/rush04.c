/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorcuer <hcorcuer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:11:21 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/20 13:09:43 by hcorcuer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	rush04(int c, int f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i <= f)
	{
		while (++j <= c)
		{
			if (((i == 1 && j == 1) || (i == f && j == c && f > 1 && c > 1)))
			{
				ft_putchar('A');
			}
			else if ((i == f && j == 1) || (i == 1 && j == c))
			{
				ft_putchar('C');
			}
			else if (i == 1 || i == f || j == 1 || j == c)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		j = 0;
		ft_putchar('\n');
	}
}
