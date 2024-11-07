/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorcuer <hcorcuer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:41:06 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 17:35:06 by hcorcuer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_threes(char *nb)
{
	int	counter;

	counter = ft_strlen(nb) / 3;
	if (ft_strlen(nb) % 3 != 0)
		counter++;
	return (counter);
}

char	**create_threes_array(char *nb, int size)
{
	char	**threes_count;
	int		i;
	int		k;
	int		len;

	threes_count = malloc(sizeof(char *) * (size + 1));
	if (!threes_count)
		return (0);
	*threes_count = 0;
	len = ft_strlen(nb) % 3;
	i = 0;
	k = 0;
	if (len == 0)
		len = 3;
	while (nb[i])
	{
		threes_count[k++] = add_word(nb + i, len);
		i += len;
		if (len != 3)
			len = 3;
	}
	threes_count[size] = 0;
	return (threes_count);
}
