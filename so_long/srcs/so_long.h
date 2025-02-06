/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:12 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 16:50:38 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include "so_long_define.h"
# include "utils/so_long_utils.h"

void	put_map(t_game g, char **map);
char	**create_map(char *fdname);
int		tabchr(char **map, char c);
int		verif_map(char **map);
int		player_coordinates(t_game *g);
int		key_mlx(int keycode, t_game *g);
int		free_map(char **map, char **map_cpy);
int		so_long(char **map);
int		close_mlx(t_game *g);

#endif