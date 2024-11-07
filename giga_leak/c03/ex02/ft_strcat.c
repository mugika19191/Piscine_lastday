/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:32:25 by imugica-          #+#    #+#             */
/*   Updated: 2024/10/29 13:51:51 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*iterator;
	char	*iterator2;

	iterator = dest;
	while (*iterator)
		iterator++;
	iterator2 = src;
	while (*iterator2)
	{
		*iterator = *iterator2;
		iterator++;
		iterator2++;
	}
	*iterator = '\0';
	return (dest);
}
