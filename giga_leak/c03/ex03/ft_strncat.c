/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:00:04 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/29 14:11:30 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*iterator;
	char			*iterator2;

	i = 0;
	iterator = dest;
	while (*iterator)
		iterator++;
	iterator2 = src;
	while (*iterator2 && i < nb)
	{
		*iterator = *iterator2;
		iterator++;
		iterator2++;
		i++;
	}
	*iterator = '\0';
	return (dest);
}
