/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:14:16 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/20 12:56:17 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_open_fence_corner_imgs(t_game *game)
{
	game->img.fence_b_l = mlx_xpm_file_to_image(game->mlx,
			"textures/fence_b_l.xpm", &game->img.size, &game->img.size);
	if (!game->img.fence_b_l)
		ft_no_img_error(game);
	game->img.fence_b_r = mlx_xpm_file_to_image(game->mlx,
			"textures/fence_b_r.xpm", &game->img.size, &game->img.size);
	if (!game->img.fence_b_r)
		ft_no_img_error(game);
	game->img.fence_t_l = mlx_xpm_file_to_image(game->mlx,
			"textures/fence_t_l.xpm", &game->img.size, &game->img.size);
	if (!game->img.fence_t_l)
		ft_no_img_error(game);
	game->img.fence_t_r = mlx_xpm_file_to_image(game->mlx,
			"textures/fence_t_r.xpm", &game->img.size, &game->img.size);
	if (!game->img.fence_t_r)
		ft_no_img_error(game);
}

static void	ft_open_fence_imgs(t_game *game)
{
	game->img.fence_l = mlx_xpm_file_to_image(game->mlx, "textures/fence_l.xpm",
			&game->img.size, &game->img.size);
	if (!game->img.fence_l)
		ft_no_img_error(game);
	game->img.fence_r = mlx_xpm_file_to_image(game->mlx, "textures/fence_r.xpm",
			&game->img.size, &game->img.size);
	if (!game->img.fence_r)
		ft_no_img_error(game);
	game->img.fence_t = mlx_xpm_file_to_image(game->mlx, "textures/fence_t.xpm",
			&game->img.size, &game->img.size);
	if (!game->img.fence_t)
		ft_no_img_error(game);
	game->img.fence_b = mlx_xpm_file_to_image(game->mlx, "textures/fence_b.xpm",
			&game->img.size, &game->img.size);
	if (!game->img.fence_b)
		ft_no_img_error(game);
}

static void	ft_open_ceo_imgs(t_game *game)
{
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->img.size, &game->img.size);
	if (!game->img.collectible)
		ft_no_img_error(game);
	game->img.house_open = mlx_xpm_file_to_image(game->mlx,
			"textures/house_open.xpm", &game->img.size, &game->img.size);
	if (!game->img.house_open)
		ft_no_img_error(game);
	game->img.house_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/house_closed.xpm", &game->img.size, &game->img.size);
	if (!game->img.house_closed)
		ft_no_img_error(game);
	game->img.nothing = mlx_xpm_file_to_image(game->mlx,
			"textures/nothing.xpm", &game->img.size, &game->img.size);
	if (!game->img.nothing)
		ft_no_img_error(game);
}

static void	ft_open_chicken_bush_imgs(t_game *game)
{
	game->img.chicken_l = mlx_xpm_file_to_image(game->mlx,
			"textures/chicken_l.xpm", &game->img.size, &game->img.size);
	if (!game->img.chicken_l)
		ft_no_img_error(game);
	game->img.chicken_r = mlx_xpm_file_to_image(game->mlx,
			"textures/chicken_r.xpm", &game->img.size, &game->img.size);
	if (!game->img.chicken_r)
		ft_no_img_error(game);
	game->img.bush = mlx_xpm_file_to_image(game->mlx, "textures/bush.xpm",
			&game->img.size, &game->img.size);
	if (!game->img.bush)
		ft_no_img_error(game);
}

void	ft_open_images(t_game *game)
{
	ft_open_fence_corner_imgs(game);
	ft_open_fence_imgs(game);
	ft_open_ceo_imgs(game);
	ft_open_chicken_bush_imgs(game);
}
