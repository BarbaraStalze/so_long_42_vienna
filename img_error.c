/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:34:53 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/13 17:24:30 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_close_other_imgs(t_game *game)
{
	if (game->img.chicken_l)
		mlx_destroy_image(game->mlx, game->img.chicken_l);
	else if (game->img.chicken_r)
		mlx_destroy_image(game->mlx, game->img.chicken_r);
	else if (game->img.bush)
		mlx_destroy_image(game->mlx, game->img.bush);
	else if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	else if (game->img.house_open)
		mlx_destroy_image(game->mlx, game->img.house_open);
	else if (game->img.house_closed)
		mlx_destroy_image(game->mlx, game->img.house_closed);
	else if (game->img.nothing)
		mlx_destroy_image(game->mlx, game->img.nothing);
}

static void	ft_close_fence_imgs(t_game *game)
{
	if (game->img.fence_l)
		mlx_destroy_image(game->mlx, game->img.fence_l);
	else if (game->img.fence_r)
		mlx_destroy_image(game->mlx, game->img.fence_r);
	else if (game->img.fence_t)
		mlx_destroy_image(game->mlx, game->img.fence_t);
	else if (game->img.fence_b)
		mlx_destroy_image(game->mlx, game->img.fence_b);
	else if (game->img.fence_b_r)
		mlx_destroy_image(game->mlx, game->img.fence_b_r);
	else if (game->img.fence_b_l)
		mlx_destroy_image(game->mlx, game->img.fence_b_l);
	else if (game->img.fence_t_r)
		mlx_destroy_image(game->mlx, game->img.fence_t_r);
	else if (game->img.fence_t_l)
		mlx_destroy_image(game->mlx, game->img.fence_t_l);
}

void	ft_close_imgs(t_game *game)
{
	ft_close_fence_imgs(game);
	ft_close_other_imgs(game);
}

void	ft_no_img_error(t_game *game)
{
	ft_close_imgs(game);
	ft_error("Sprite not existent\n", game);
}
