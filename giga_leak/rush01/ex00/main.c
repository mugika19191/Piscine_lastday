/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabal-m <mzabal-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:35:43 by mzabal-m          #+#    #+#             */
/*   Updated: 2024/10/27 18:46:09 by mzabal-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	resolver(int matriz[4][4], int vistas[4][4], int fila, int col);

int	mirar_longitud(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	if (i != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	rellenar_inputs(char *str, int input[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str && i < 4)
	{
		if (*str >= '1' && *str <= '4')
		{
			input[i][j] = *str - '0';
			j++;
			if (j == 4)
			{
				i++;
				j = 0;
			}
		}
		else if (*str != ' ')
			return (0);
		str++;
	}
	if (i == 4 && !(*str))
		return (1);
	return (0);
}

void	rellenar_matriz(int matriz[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matriz[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	dibujar_matriz(int matriz[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = matriz[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **args)
{
	int	matriz[4][4];
	int	inputs[4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!mirar_longitud(args[1]))
	{
		return (1);
	}
	if (!rellenar_inputs(args[1], inputs))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	rellenar_matriz(matriz);
	if (!resolver(matriz, inputs, 0, 0))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	dibujar_matriz(matriz);
	return (0);
}
