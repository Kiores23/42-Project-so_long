/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verif.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:44:12 by amery             #+#    #+#             */
/*   Updated: 2023/01/25 16:52:05 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_VERIF_H
# define SO_LONG_VERIF_H
# include <stdlib.h>
# include <fcntl.h>
# include "utils/so_long_utils.h"

void	check_path(char	**map, char c, int *r, size_t x);
int		check_close(char **map, int x);
int		check_count(char c);
int		check_content(char **map);
int		check_dimension(char **map);

#endif