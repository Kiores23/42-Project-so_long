/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:04:23 by amery             #+#    #+#             */
/*   Updated: 2022/12/09 18:40:05 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H
# include "../so_long.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"

size_t	ft_strlen(char *str);
size_t	ft_nbrlen(int n);
size_t	ft_tablen(char **tab);
int		rerror(const char *derror);
char	*ft_strchr(char *str, char c);

#endif