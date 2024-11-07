/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabal-m <mzabal-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:36:27 by mzabal-m          #+#    #+#             */
/*   Updated: 2024/10/27 18:04:54 by mzabal-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sin_duplicar(int matriz[4][4], int fila, int col, int num);
int	valido(int matriz[4][4], int vistas[4][4], int fila, int col);

int	resolver(int matriz[4][4], int vistas[4][4], int fila, int col)
{
	int	num;

	num = 1;
	if (fila == 4)
		return (1);
	if (col == 4)
		return (resolver(matriz, vistas, fila + 1, 0));
	while (num <= 4)
	{
		if (sin_duplicar(matriz, fila, col, num))
		{
			matriz[fila][col] = num;
			if (valido(matriz, vistas, fila, col))
			{
				if (resolver(matriz, vistas, fila, col + 1))
					return (1);
			}
			matriz[fila][col] = 0;
		}
		num++;
	}
	return (0);
}
