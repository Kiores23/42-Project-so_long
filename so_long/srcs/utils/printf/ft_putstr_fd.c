/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:01:50 by amery             #+#    #+#             */
/*   Updated: 2022/12/07 18:49:20 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	return (i);
}
