/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:44:35 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:44:36 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst > src)
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	else
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	return ((char*)dst);
}
