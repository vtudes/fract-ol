/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:50:03 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:50:04 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_endsp(const char *s)
{
	size_t i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (ft_strlen(s) - 1 - i);
}

static size_t	ft_begsp(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int		ft_letter(const char *s)
{
	int i;

	if (ft_begsp(s) == ft_strlen(s))
		return (0);
	i = ft_strlen(s) - ft_begsp(s) - ft_endsp(s);
	return (i);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;
	size_t	let;

	if (!s)
		return (NULL);
	i = ft_begsp(s);
	let = ft_strlen(s) - 1 - ft_begsp(s) - ft_endsp(s);
	if (!(str = (char*)malloc(sizeof(char) * ft_letter(s) + 1)))
		return (0);
	if (ft_letter(s) > 0)
	{
		while (i < ft_strlen(s) - ft_endsp(s))
		{
			str[i - ft_begsp(s)] = s[i];
			i++;
		}
	}
	str[ft_letter(s)] = '\0';
	return (str);
}
