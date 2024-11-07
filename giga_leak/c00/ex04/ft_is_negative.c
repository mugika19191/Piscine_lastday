/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:20:12 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/19 12:22:00 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	resp;

	resp = 'z';
	if (n < 0)
	{
		resp = 'N';
	}
	else
	{
		resp = 'P';
	}
	write(1, &resp, 1);
}
