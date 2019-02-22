/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:49:23 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:49:24 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	if (!little[i])
		return (&((char*)big)[0]);
	while (big[i])
	{
		while (big[i] == little[k] && big[i] && i < len)
		{
			i++;
			k++;
		}
		if (little[k] == '\0')
			return (&((char*)big)[i - k]);
		if (k > 0)
			i = i - k;
		k = 0;
		i++;
	}
	return (0);
}
