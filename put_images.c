/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:23:46 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/13 14:48:03 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_check_corners(t_game *game, int i, int j)
{
	if (i == 0 && j == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_t_l,
			i * game->img.size, j * game->img.size);
	}
	else if (i == game->map_height - 1 && j == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_b_l,
			i * game->img.size, j * game->img.size);
	}
	else if (i == 0 && j == game->map_width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_t_r,
			i * game->img.size, j * game->img.size);
	}
	else if (j == game->map_width - 1 && i != game->map_height - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_b_r,
			i * game->img.size, j * game->img.size);
	}
}

static void	ft_check_wall(t_game *game, int i, int j)
{
	if (i == 0 && j != 0 && j != game->map_width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_t,
			i * game->img.size, j * game->img.size);
	}
	else if (i == game->map_height - 1 && j != 0 && j != game->map_width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_b,
			i * game->img.size, j * game->img.size);
	}
	else if (j == 0 && i != 0 && i != game->map_height - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_l,
			i * game->img.size, j * game->img.size);
	}
	else if (j == game->map_width - 1 && i != 0 && i != game->map_height - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_r,
			i * game->img.size, j * game->img.size);
	}
}

static void	ft_check_letters(t_game *game, int i, int j)
{
		if (game->map[i][j] == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->img.nothing,
				i * game->img.size, j * game->img.size);
		}
		else if (game->map[i][j] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->img.chicken_r,
				i * game->img.size, j * game->img.size);
		}
		else if (game->map[i][j] == '1')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->img.bush,
				i * game->img.size, j * game->img.size);
		}
		else if (game->map[i][j] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->img.collectible,
				i * game->img.size, j * game->img.size);
		}
		else if (game->map[i][j] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->img.house_closed,
				i * game->img.size, j * game->img.size);
		}
}

void	ft_put_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_check_wall(game, i, j);
			ft_check_corners(game, i, j);
			if (i != 0 && j != 0)
				ft_check_letters(game, i, j);
			j++;
		}
		i++;
	}
}
