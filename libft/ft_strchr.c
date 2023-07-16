/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:38:58 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/15 14:10:18 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == c % 256)
		{
			break ;
		}
		s++;
	}
	if (*s != 0)
	{
		return ((char *)s);
	}
	if (c % 256 == 0)
		return ((char *)s);
	return (0);
}