/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:44:08 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:44:10 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	v;
	unsigned char	*str;
	size_t			i;

	v = (unsigned char)c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n && str[i] != v)
		i++;
	if (i < n && str[i] == v)
		return (&str[i]);
	return (NULL);
}
