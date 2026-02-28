/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:38:28 by bastalze          #+#    #+#             */
/*   Updated: 2026/02/27 12:57:01 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_game
{
	char	***map_pointer;
	int		map_width;
	int		map_x;
	int		map_y;
}	t_game

#endif
