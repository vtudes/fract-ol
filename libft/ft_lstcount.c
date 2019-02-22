/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:42:48 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:42:49 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list **alst)
{
	int		i;
	t_list	*chain;

	i = 1;
	chain = *alst;
	if (!chain)
		return (0);
	while (chain->next)
	{
		i++;
		chain = chain->next;
	}
	return (i);
}
