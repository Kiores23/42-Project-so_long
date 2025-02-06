/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:43:49 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 16:29:15 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_game	init_my_mlx(char **map)
{
	t_game	g;

	g.mlx = mlx_init();
	g.pos.img = MLX_XPM(g.mlx, POSUP, &g.pos.img_w, &g.pos.img_h);
	g.pos1.img = MLX_XPM(g.mlx, POSUP, &g.pos1.img_w, &g.pos1.img_h);
	g.pos2.img = MLX_XPM(g.mlx, POSDOWN, &g.pos2.img_w, &g.pos2.img_h);
	g.pos3.img = MLX_XPM(g.mlx, POSLEFT, &g.pos3.img_w, &g.pos3.img_h);
	g.pos4.img = MLX_XPM(g.mlx, POSRIGHT, &g.pos4.img_w, &g.pos4.img_h);
	g.wall.img = MLX_XPM(g.mlx, WALL, &g.wall.img_w, &g.wall.img_h);
	g.co.img = MLX_XPM(g.mlx, STAR, &g.co.img_w, &g.co.img_h);
	g.ex.img = MLX_XPM(g.mlx, EXIT, &g.ex.img_w, &g.ex.img_h);
	g.vd.img = MLX_XPM(g.mlx, VOID, &g.vd.img_w, &g.vd.img_h);
	g.map = map;
	return (g);
}

void	put_map(t_game g, char **map)
{
	g.x = -1;
	while (map[++g.x])
	{
		g.y = -1;
		while (map[g.x][++g.y])
		{
			MLX_PITW(g.mlx, g.mlx_win, g.vd.img, g.y * 64, g.x * 64);
			if (map[g.x][g.y] == 'P')
				MLX_PITW(g.mlx, g.mlx_win, g.pos.img, g.y * 64, g.x * 64);
			else if (map[g.x][g.y] == '1')
				MLX_PITW(g.mlx, g.mlx_win, g.wall.img, g.y * 64, g.x * 64);
			else if (map[g.x][g.y] == 'C')
				MLX_PITW(g.mlx, g.mlx_win, g.co.img, g.y * 64, g.x * 64);
			else if (map[g.x][g.y] == 'E')
				MLX_PITW(g.mlx, g.mlx_win, g.ex.img, g.y * 64, g.x * 64);
			else if (map[g.x][g.y] == '0')
				MLX_PITW(g.mlx, g.mlx_win, g.vd.img, g.y * 64, g.x * 64);
		}
	}
}

int	so_long(char **map)
{
	t_game	game;

	game = init_my_mlx(map);
	game.count = 0;
	game.mlx_win = MLX_NW(game.mlx, WIN_SIZE, "so_long");
	mlx_hook(game.mlx_win, 2, 1L << 0, key_mlx, &game);
	mlx_hook(game.mlx_win, ON_DESTROY, 1L << 0, close_mlx, &game);
	put_map(game, map);
	mlx_loop(game.mlx);
	return (1);
}
