/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:58 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 11:51:50 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char	**map, char c, int *r, size_t x)
{
	size_t	y;

	while (map[++x])
	{
		y = 0;
		while (map[x][y++])
		{
			if (map[x][y] == 'P' || map[x][y] == 'R')
			{
				if (map[x - 1][y] == c || map[x + 1][y] == c
					|| map[x][y + 1] == c || map[x][y - 1] == c)
					*r = 1;
				if (map[x - 1][y] == c)
					map[x - 1][y] = 'R';
				if (map[x + 1][y] == c)
					map[x + 1][y] = 'R';
				if (map[x][y - 1] == c)
					map[x][y - 1] = 'R';
				if (map[x][y + 1] == c)
					map[x][y + 1] = 'R';
			}
		}
	}
}

int	check_close(char **map, int x)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (x)
		j = ft_strlen(map[i + 1]) - 2;
	while (map[++i] && map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != '\n')
			return (0);
	}
	i = -1;
	if (x)
		j = ft_tablen(map) - 1;
	while (map[j] && map[j][++i])
	{
		if (map[j][i] != '1' && map[j][i] != '\n')
			return (0);
	}
	if (!x)
		return (check_close(map, 1));
	return (1);
}

int	check_count(char c)
{
	static size_t	p_count = 0;
	static size_t	e_count = 0;
	static size_t	c_count = 0;

	if (c == 'P')
		p_count++;
	else if (c == 'E')
		e_count++;
	else if (c == 'C')
		c_count++;
	if (p_count == 1 && e_count == 1 && c_count > 0)
		return (1);
	else
		return (0);
}

int	check_content(char **map)
{
	char	c;
	size_t	i;
	size_t	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			c = map[i][y];
			if (c != '\n' && c != '0' && c != '1'
				&& c != 'P' && c != 'C' && c != 'E')
				return (rerror(" Map : wrong character found"));
			if (!check_count(c) && !map[i + 1] && y == ft_strlen(map[i]) - 1)
				return (rerror(" Map : wrong character count"));
		}
	}
	return (1);
}

int	check_dimension(char **map)
{
	size_t	l_size;
	size_t	m_size;
	size_t	i;

	i = 0;
	l_size = ft_strlen(map[i]);
	m_size = ft_tablen(map);
	if (*map[m_size - 1] != '1'
		|| ft_strlen(map[m_size - 1]) == l_size)
		return (rerror(" Map : new line after map"));
	while (map[i])
	{
		if (!map[i + 1])
			l_size--;
		if (ft_strlen(map[i]) != l_size)
			return (rerror(" Map : wrong dimension"));
		i++;
	}
	return (1);
}
