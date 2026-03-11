/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:01:58 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/11 18:17:55 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_valid_char(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E'&& game->map[i][j] != 'P')
				ft_error("Wrong character on map\n", game);
			j++;
		}
		i++;
	}
}

void	ft_file_type(char *filename, t_game *game)
{
	char	*dot;
	int		ber;

	dot = strrchr(filename, '.');
	if (!dot || dot == filename)
        {
                ft_error("Please enter a valid .ber file name as an argument.\
                        For example: \"map.ber\"\n", game);
        }
	ber = strncmp(dot, ".ber", 5);
	if (ber != 0)
        {
                ft_error("Please enter a valid .ber file name as an argument.\
                        For example: \"map.ber\"\n", game);
        }
}

static void	ft_surrounded_by_walls(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' && game->map[i][game->map_width] != '1')
			ft_error("Map is not surrounded by walls\n", game);
		if (i == 0 || i == game->map_height)
		{
			j = 1;
			while (game->map[i][j])
			{
				if (game->map[i][j] != '1')
					ft_error("Map is not surrounded by walls\n", game);
				j++;
			}
		}
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
		ft_error("Map has to contain exactly one P, one E and at least one C\n", game);
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
