/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:01:58 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/23 18:09:29 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'P')
			{
				errno = EINVAL;
				ft_error("Wrong character on map", game);
			}
			j++;
		}
		i++;
	}
}

static void	ft_check_horizontal_wall(t_game *game, int i)
{
	int	j;

	j = 1;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
		{
			errno = EINVAL;
			ft_error("Map is not surrounded by walls", game);
		}
		j++;
	}
}

static void	ft_surrounded_by_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
		{
			errno = EINVAL;
			ft_error("Map is not surrounded by walls", game);
		}
		if (i == 0 || i == game->map_height - 1)
			ft_check_horizontal_wall(game, i);
		i++;
	}
}

static void	ft_features_right(t_game *game, int start, int exit)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				exit++;
			else if (game->map[i][j] == 'P')
				start++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
	if (exit != 1 || start != 1 || game->collectibles == 0)
	{
		errno = EINVAL;
		ft_error("Map has to contain exactly one P, one E and at \
least one C", game);
	}
}

void	ft_is_map_valid(t_game *game)
{
	int	start;
	int	exit;

	start = 0;
	exit = 0;
	ft_valid_char(game);
	ft_surrounded_by_walls(game);
	ft_features_right(game, start, exit);
	ft_valid_path(game);
}
