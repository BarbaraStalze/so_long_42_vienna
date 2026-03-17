/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:38:28 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/17 22:44:20 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 50
# endif

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h> //only for strrchr
# include "libft/get_next_line.h"
# include "libft/libft.h"

typedef struct s_image
{
	int		size;
	void	*chicken_l;
	void	*chicken_r;
	void	*bush;
	void	*collectible;
	void	*house_open;
	void	*house_closed;
	void	*fence_l;
	void	*fence_r;
	void	*fence_t;
	void	*fence_b;
	void	*fence_b_l;
	void	*fence_b_r;
	void	*fence_t_l;
	void	*fence_t_r;
	void	*nothing;
	void	*end;
}	t_image;

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;
	int		collectibles;
	int		fd;
	void	*mlx;
	void	*window;
	t_image	img;
	int		start_i;
	int		start_j;
	int		exit_i;
	int		exit_j;
	int		move;
	int		moves;
}	t_game;

void	ft_file_type(char *filename, t_game *game);
void	ft_parse_map(char *ber_file, t_game *game);
void	ft_free_array(char **a);
void	ft_is_map_valid(t_game *game);
void	ft_valid_path(t_game *game);
void	ft_error(char *message, t_game *game);
void	ft_open_images(t_game *game);
void	ft_put_image(t_game *game);
void	ft_start_window(t_game *game);
void	ft_close_imgs(t_game *game);
void	ft_no_img_error(t_game *game);
void	ft_moves(t_game *game);
int		ft_close_game(t_game *game);

#endif
