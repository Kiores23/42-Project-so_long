/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:11:27 by amery             #+#    #+#             */
/*   Updated: 2022/12/12 16:18:40 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

size_t	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

size_t	ft_nbrlen(int n)
{
	if (n <= -10 || 10 <= n)
		return (1 + ft_nbrlen(n / 10));
	return (1);
}
