/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:23:46 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/17 22:42:59 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_check_corners(t_game *game, int i, int j)
{
	if (i == 0 && j == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_t_l,
			j * game->img.size, i * game->img.size);
	}
	else if (i == game->map_height - 1 && j == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_b_l,
			j * game->img.size, i * game->img.size);
	}
	else if (i == 0 && j == game->map_width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_t_r,
			j * game->img.size, i * game->img.size);
	}
	else if (j == game->map_width - 1 && i == game->map_height - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_b_r,
			j * game->img.size, i * game->img.size);
	}
}

static void	ft_check_wall(t_game *game, int i, int j)
{
	if (i == 0 && j != 0 && j != game->map_width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_t,
			j * game->img.size, i * game->img.size);
	}
	else if (i == game->map_height - 1 && j != 0 && j != game->map_width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_b,
			j * game->img.size, i * game->img.size);
	}
	else if (j == 0 && i != 0 && i != game->map_height - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_l,
			j * game->img.size, i * game->img.size);
	}
	else if (j == game->map_width - 1 && i != 0 && i != game->map_height - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.fence_r,
			j * game->img.size, i * game->img.size);
	}
}

static void	ft_check_letters(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.nothing,
			j * game->img.size, i * game->img.size);
	}
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.chicken_r,
			j * game->img.size, i * game->img.size);
	}
	else if (game->map[i][j] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.bush,
			j * game->img.size, i * game->img.size);
	}
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.collectible,
			j * game->img.size, i * game->img.size);
	}
	else if (game->map[i][j] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.house_closed,
			j * game->img.size, i * game->img.size);
	}
}

void	ft_check_more_letters(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'e')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.house_open,
			j * game->img.size, i * game->img.size);
	}
	else if (game->map[i][j] == 'p')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.chicken_l,
			j * game->img.size, i * game->img.size);
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
			if (i == 0 || j == 0 || i == game->map_height - 1
				|| j == game->map_width - 1)
			{
				ft_check_corners(game, i, j);
				ft_check_wall(game, i, j);
			}
			else
			{
				ft_check_letters(game, i, j);
				ft_check_more_letters(game, i, j);
			}
			j++;
		}
		i++;
	}
}
