/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:34:53 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/23 17:38:07 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_close_other_imgs(t_game *game)
{
	if (game->img.chicken_l)
		mlx_destroy_image(game->mlx, game->img.chicken_l);
	if (game->img.chicken_r)
		mlx_destroy_image(game->mlx, game->img.chicken_r);
	if (game->img.bush)
		mlx_destroy_image(game->mlx, game->img.bush);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.house_open)
		mlx_destroy_image(game->mlx, game->img.house_open);
	if (game->img.house_closed)
		mlx_destroy_image(game->mlx, game->img.house_closed);
	if (game->img.nothing)
		mlx_destroy_image(game->mlx, game->img.nothing);
	if (game->img.end)
		mlx_destroy_image(game->mlx, game->img.end);
}

static void	ft_close_fence_imgs(t_game *game)
{
	if (game->img.fence_l)
		mlx_destroy_image(game->mlx, game->img.fence_l);
	if (game->img.fence_r)
		mlx_destroy_image(game->mlx, game->img.fence_r);
	if (game->img.fence_t)
		mlx_destroy_image(game->mlx, game->img.fence_t);
	if (game->img.fence_b)
		mlx_destroy_image(game->mlx, game->img.fence_b);
	if (game->img.fence_b_r)
		mlx_destroy_image(game->mlx, game->img.fence_b_r);
	if (game->img.fence_b_l)
		mlx_destroy_image(game->mlx, game->img.fence_b_l);
	if (game->img.fence_t_r)
		mlx_destroy_image(game->mlx, game->img.fence_t_r);
	if (game->img.fence_t_l)
		mlx_destroy_image(game->mlx, game->img.fence_t_l);
}

void	ft_close_imgs(t_game *game)
{
	ft_close_fence_imgs(game);
	ft_close_other_imgs(game);
}

void	ft_no_img_error(t_game *game)
{
	errno = EINVAL;
	ft_error("Sprite not existent", game);
}
