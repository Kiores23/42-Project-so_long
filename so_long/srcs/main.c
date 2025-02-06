/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:42:39 by amery             #+#    #+#             */
/*   Updated: 2023/01/12 18:13:06 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;
	char	**map_cpy;

	map = 0;
	if (argc == 1)
		return (rerror(" Map : no file") + free_map(NULL, NULL));
	map = create_map(argv[1]);
	if (map)
		map_cpy = create_map(argv[1]);
	if (!map || !map_cpy)
		return (free_map(NULL, NULL));
	if (!verif_map(map_cpy))
		return (free_map(map, map_cpy));
	free_map(NULL, map_cpy);
	so_long(map);
	return (0);
}
