/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:46:30 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:46:30 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = ((unsigned char*)s1);
	s22 = ((unsigned char*)s2);
	while (s11[i] == s22[i] && s11[i] != '\0' && s22[i] != '\0')
	{
		i++;
	}
	return (s11[i] - s22[i]);
}
