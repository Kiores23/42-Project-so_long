/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:16:43 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 13:43:19 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_verif.h"

int	tabchr(char **map, char c)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], c))
			return (1);
		i++;
	}
	return (0);
}

int	verif_map(char **map)
{
	int	i;

	if (!check_dimension(map))
		return (0);
	if (!check_content(map))
		return (0);
	if (!check_close(map, 0))
		return (rerror(" Map : not closed"));
	i = 1;
	while (i)
	{
		i = 0;
		check_path(map, '0', &i, -1);
		check_path(map, 'C', &i, -1);
	}
	check_path(map, 'E', &i, -1);
	if (tabchr(map, 'C') || tabchr(map, 'E'))
		return (rerror("Map : no path"));
	return (1);
}
