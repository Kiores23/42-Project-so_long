/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:57:07 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 16:55:36 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINE_H
# define SO_LONG_DEFINE_H

# define MLX_NW mlx_new_window
# define WIN_SIZE (ft_strlen(map[0]) - 1) * 64, ft_tablen(map) * 64
# define MLX_XPM mlx_xpm_file_to_image
# define POSUP "./sprite/posup.xpm"
# define POSDOWN "./sprite/posdown.xpm"
# define POSLEFT "./sprite/posleft.xpm"
# define POSRIGHT "./sprite/posright.xpm"
# define WALL "./sprite/wall.xpm"
# define STAR "./sprite/star.xpm"
# define EXIT "./sprite/exit.xpm"
# define VOID "./sprite/void.xpm"
# define MLX_PITW mlx_put_image_to_window

typedef struct s_img {
	void	*img;
	int		img_w;
	int		img_h;
}			t_img;

typedef struct s_game {
	char	**map;
	void	*mlx;
	void	*mlx_win;
	int		count;
	int		x;
	int		y;
	int		xp;
	int		yp;
	t_img	pos;
	t_img	pos1;
	t_img	pos2;
	t_img	pos3;
	t_img	pos4;
	t_img	wall;
	t_img	co;
	t_img	ex;
	t_img	vd;
}			t_game;

enum {
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
	K_ESC = 65307,  // ESC sous Linux
	K_W = 119,      // 'w'
	K_A = 97,       // 'a'
	K_S = 115,      // 's'
	K_D = 100       // 'd'
};


#endif