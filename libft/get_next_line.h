/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:50:39 by vtudes            #+#    #+#             */
/*   Updated: 2018/01/16 15:50:40 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 7000
# include "libft.h"

t_list	*ft_manage_fd(int fd, t_list **chain);
int		get_next_line(const int fd, char **line);
void	join(t_list **alst, char *buff, int end);

#endif
