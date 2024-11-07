/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabal-m <mzabal-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:36:38 by mzabal-m          #+#    #+#             */
/*   Updated: 2024/10/27 18:00:36 by mzabal-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sin_duplicar(int matriz[4][4], int fila, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matriz[fila][i] == num || matriz[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	visibles(int linea[4])
{
	int	i;
	int	max_height;
	int	visibles;

	i = 0;
	max_height = 0;
	visibles = 0;
	while (i < 4)
	{
		if (linea[i] > max_height)
		{
			visibles++;
			max_height = linea[i];
		}
		i++;
	}
	return (visibles);
}

int	check_row(int matriz[4][4], int vistas[4][4], int fila)
{
	int	temp[4];
	int	rev[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		temp[i] = matriz[fila][i];
		rev[3 - i] = matriz[fila][i];
		i++;
	}
	if (visibles(temp) != vistas[2][fila])
		return (0);
	if (visibles(rev) != vistas[3][fila])
		return (0);
	return (1);
}

int	check_col(int matriz[4][4], int vistas[4][4], int col)
{
	int	temp[4];
	int	rev[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		temp[i] = matriz[i][col];
		rev[3 - i] = matriz[i][col];
		i++;
	}
	if (visibles(temp) != vistas[0][col])
		return (0);
	if (visibles(rev) != vistas[1][col])
		return (0);
	return (1);
}

int	valido(int matriz[4][4], int vistas[4][4], int fila, int col)
{
	if (col == 3 && !check_row(matriz, vistas, fila))
		return (0);
	if (fila == 3 && !check_col(matriz, vistas, col))
		return (0);
	return (1);
}
