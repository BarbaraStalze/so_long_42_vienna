/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_imgages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:14:16 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/13 12:13:05 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	open_fence_imgs(t_game *game)
{
	game->img.fence_l = mlx_xpm_file_to_image(game->mlx, "sprites/fence_l.xpm",
		&game->img.width, &game->img.height);
	game->img.fence_r = mlx_xpm_file_to_image(game->mlx, "sprites/fence_r.xpm",
		&game->img.width, &game->img.height);
	game->img.fence_t = mlx_xpm_file_to_image(game->mlx, "sprites/fence_t.xpm",
		&game->img.width, &game->img.height);
	game->img.fence_b = mlx_xpm_file_to_image(game->mlx, "sprites/fence_b.xpm",
		&game->img.width, &game->img.height);
	game->img.fence_b_l = mlx_xpm_file_to_image(game->mlx, "sprites/fence_b_l.xpm",
		&game->img.width, &game->img.height);
	game->img.fence_b_r = mlx_xpm_file_to_image(game->mlx, "sprites/fence_b_r.xpm",
		&game->img.width, &game->img.height);
	game->img.fence_t_l = mlx_xpm_file_to_image(game->mlx, "sprites/fence_t_l.xpm",
		&game->img.width, &game->img.height);
	game->img.fence_t_r = mlx_xpm_file_to_image(game->mlx, "sprites/fence_t_r.xpm",
		&game->img.width, &game->img.height);
}

void	open_nonfence_imgs(t_game *game)
{
	game->img.chicken_l = mlx_xpm_file_to_image(game->mlx, "sprites/chicken_l.xpm",
		&game->img.width, &game->img.height);
	game->img.chicken_r = mlx_xpm_file_to_image(game->mlx, "sprites/chicken_r.xpm",
		&game->img.width, &game->img.height);
	game->img.bush = mlx_xpm_file_to_image(game->mlx, "sprites/bush.xpm",
		&game->img.width, &game->img.height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, "sprites/collectible.xpm",
		&game->img.width, &game->img.height);
	game->img.house_open = mlx_xpm_file_to_image(game->mlx, "sprites/house_open.xpm",
		&game->img.width, &game->img.height);
	game->img.house_closed = mlx_xpm_file_to_image(game->mlx, "sprites/house_closed.xpm",
		&game->img.width, &game->img.height);
	game->img.nothing = mlx_xpm_file_to_image(game->mlx, "sprites/nothing.xpm",
		&game->img.width, &game->img.height);
}
