/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:56:33 by amery             #+#    #+#             */
/*   Updated: 2022/12/08 17:15:17 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include "../so_long_utils.h"
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_free_stackandbuff(char **stack, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dst, const char *src, int size);

#endif
