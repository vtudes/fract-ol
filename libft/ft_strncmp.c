/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:48:53 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:48:54 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = ((unsigned char*)s1);
	s22 = ((unsigned char*)s2);
	i = 0;
	while (s11[i] == s22[i] && s11[i] != '\0' && s22[i] != '\0' && n > 0)
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return (s11[i] - s22[i]);
}
