/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:49:43 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:49:44 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	char	*ft_count_letters(const char *s, char c, int *i)
{
	int		j;
	int		len;
	char	*str;

	j = *i;
	len = 0;
	while (s[j] == c && s[j])
		j++;
	while (s[j] != c && s[j])
	{
		j++;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (0);
	*i = 0;
	while (s[j - len] != c && s[j - len])
	{
		str[*i] = s[j - len];
		len--;
		++(*i);
	}
	*i = j;
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL || c == 0)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		str[i] = ft_count_letters(s, c, &j);
		i++;
	}
	str[i] = 0;
	return (str);
}
