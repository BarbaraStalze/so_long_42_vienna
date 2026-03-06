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

//# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_game
{
	char	**map;
	int		map_width;
	int		map_h;
	int		map_w;
	int		collectibles;
}	t_game;

typedef struct  s_path
{
	int	start_h;
	int	start_w;
}	t_path;

void	ft_file_type(char *filename, t_game *game);
void	ft_read_map(char *ber_file, t_game *game);
void	ft_free_array(char **a);
void	ft_is_map_valid(t_game *game);
void	ft_valid_path(t_game *game);
void	ft_error(char *message, t_game *game);

#endif
