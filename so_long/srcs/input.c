/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:01:00 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 17:17:32 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static int	get_direction(int keycode, int *dx, int *dy)
{
	if (keycode == K_W)
	{
		*dx = -1;
		*dy = 0;
	}
	else if (keycode == K_S)
	{
		*dx = 1;
		*dy = 0;
	}
	else if (keycode == K_A)
	{
		*dx = 0;
		*dy = -1;
	}
	else if (keycode == K_D)
	{
		*dx = 0;
		*dy = 1;
	}
	else
		return (0);
	return (1);
}

static void	*get_img_player(int keycode, t_game *g)
{
	if (keycode == K_W)
		return (g->pos1.img);
	else if (keycode == K_S)
		return (g->pos2.img);
	else if (keycode == K_A)
		return (g->pos3.img);
	else if (keycode == K_D)
		return (g->pos4.img);
	return (NULL);
}

void	player_movement(int keycode, t_game *g)
{
	int		dx;
	int		dy;
	int		new_x;
	int		new_y;
	void	*img;

	if (!get_direction(keycode, &dx, &dy))
		return ;
	new_x = g->xp + dx;
	new_y = g->yp + dy;
	if (g->map[new_x][new_y] != '1'
		&& (g->map[new_x][new_y] != 'E' || !tabchr(g->map, 'C')))
	{
		img = get_img_player(keycode, g);
		g->map[new_x][new_y] = 'P';
		g->pos.img = img;
		ft_printf("%i\n", ++(g->count));
		g->map[g->xp][g->yp] = '0';
		g->xp = new_x;
		g->yp = new_y;
	}
}

int	close_mlx(t_game *g)
{
	free_map(g->map, NULL);
	exit(mlx_destroy_window(g->mlx, g->mlx_win));
}

int	key_mlx(int keycode, t_game *g)
{
	if (keycode == K_ESC)
		close_mlx(g);
	player_coordinates(g);
	if (keycode == K_W || keycode == K_S || keycode == K_A || keycode == K_D)
	{
		player_movement(keycode, g);
	}
	if (player_coordinates(g))
	{
		put_map(*g, g->map);
	}
	if (!tabchr(g->map, 'E'))
		close_mlx(g);
	return (0);
}
