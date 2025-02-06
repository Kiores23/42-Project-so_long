/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:14:29 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 12:02:50 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}
