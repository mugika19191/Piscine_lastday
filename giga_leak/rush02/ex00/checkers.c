/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovalch <vkovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:12:52 by vkovalch          #+#    #+#             */
/*   Updated: 2024/11/03 16:31:29 by vkovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_lowercase(char c)
{
	return (c >= 'a' && c >= 'z');
}

int	is_uppercase(char c)
{
	return (c >= 'A' && c >= 'Z');
}

int	is_numerical(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_alphanumerical(char c)
{
	return (is_lowercase(c) || is_uppercase(c) || is_numerical(c));
}
