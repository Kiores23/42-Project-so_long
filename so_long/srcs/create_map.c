/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:49:23 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 17:13:36 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_chr(char *fdname)
{
	size_t	s;

	s = ft_strlen(fdname);
	if (s >= 4 && fdname[s - 4] == '.' && fdname[s - 3] == 'b'
		&& fdname[s - 2] == 'e' && fdname[s -1] == 'r')
		return (1);
	return (0);
}

int	free_map(char **map, char **map_cpy)
{
	size_t	i;

	i = -1;
	while (map && map[++i])
		free(map[i]);
	if (map)
		free(map);
	i = -1;
	while (map_cpy && map_cpy[++i])
		free(map_cpy[i]);
	if (map_cpy)
		free(map_cpy);
	return (0);
}

size_t	map_size(char *fdname)
{
	size_t	size;
	int		fd;
	char	*t;

	if (!ber_chr(fdname))
		return (rerror(" Map : wrong file extension"));
	fd = open(fdname, O_RDONLY);
	if (fd < 0)
		return (rerror(" Map : file not found or unable to open"));
	size = 0;
	t = get_next_line(fd);
	while (t && ++size)
	{
		free(t);
		t = get_next_line(fd);
	}
	if (size == 0)
		return (rerror(" Map : empty file") + close(fd));
	return (size + close(fd));
}

char	**create_map(char *fdname)
{
	char	**map;
	int		fd;
	size_t	size;
	size_t	i;

	i = 0;
	size = map_size(fdname);
	if (!size)
		return (NULL);
	fd = open(fdname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	while (i < size && (!i || map[i - 1]))
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
