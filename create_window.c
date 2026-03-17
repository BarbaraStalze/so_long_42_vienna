/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:09:58 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/17 21:51:31 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_start_window(t_game *game)
{
	int	sizex;
	int	sizey;

	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &sizex, &sizey);
	if (game->map_width * 32 > sizex || game->map_height * 32 > sizey)
		ft_error("Map is too big\n", game);
	game->window = mlx_new_window(game->mlx, game->map_width * 32,
			game->map_height * 32, "THE SECRET LIFE OF A CHICKEN");
	game->img.size = 32;
	ft_open_images(game);
	ft_put_image(game);
}
