/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:38:37 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 10:34:11 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_coordinates(t_game *g)
{
	g->x = -1;
	while (g->map[++g->x])
	{
		g->y = 0;
		while (g->map[g->x][g->y] && g->map[g->x][g->y] != 'P')
			g->y++;
		if (g->map[g->x][g->y] == 'P')
		{
			g->xp = g->x;
			g->yp = g->y;
			return (1);
		}
	}
	return (0);
}
