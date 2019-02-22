/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:49:51 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:49:52 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	short i;
	short j;

	i = 0;
	j = 0;
	if (!little[i])
		return (&((char*)big)[0]);
	while (big[i])
	{
		while (big[i] == little[j] && big[i])
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return (&((char*)big)[i - j]);
		if (j > 0)
			i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
