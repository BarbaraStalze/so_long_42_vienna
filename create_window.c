/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:09:58 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/13 17:54:09 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <mlx.h>

void	ft_start_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map_width * 32, game->map_height * 32,
		"so_long: THE SECRET LIFE OF A CHICKEN");
	game->img.size = 32;
	ft_open_images(game);
	ft_put_image(game);
	mlx_loop(game->mlx);
}
