/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:02:30 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/20 21:44:57 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_add_start_and_exit(t_game *game, char letter, int i, int j)
{
	if (letter == 'P')
	{
		game->start_i = i;
		game->start_j = j;
	}
	else if (letter == 'E')
	{
		game->exit_i = i;
		game->exit_j = j;
	}
}

static char	**ft_copy_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		game->test_map[i] = ft_calloc(game->map_width + 1, sizeof(char));
		if (!game->test_map[i])
		{
			ft_free_array(game->test_map);
			ft_error("Malloc failed in copy map\n", game);
		}
		while (game->map[i][j])
		{
			game->test_map[i][j] = game->map[i][j];
			ft_add_start_and_exit(game, game->test_map[i][j], i, j);
			j++;
		}
		game->test_map[i][j] = 0;
		i++;
	}
	game->test_map[i] = NULL;
	return (game->test_map);
}

static void	ft_flood_fill(t_game *game, int i, int j)
{
	if (game->test_map[i][j] == '1' || (game->test_map[i][j] == 'E'))
	{
		if (game->test_map[i][j] == 'E')
			game->exit_found++;
		return ;
	}
	if (game->test_map[i][j] == 'C')
		game->collectibles_found++;
	game->test_map[i][j] = '1';
	ft_flood_fill(game, i - 1, j);
	ft_flood_fill(game, i, j + 1);
	ft_flood_fill(game, i + 1, j);
	ft_flood_fill(game, i, j - 1);
	return ;
}

void	ft_valid_path(t_game *game)
{
	game->test_map = malloc((game->map_height + 1) * sizeof(char *));
	if (!game->test_map)
		ft_error("Malloc failed in ft_valid_path\n", game);
	game->test_map = ft_copy_map(game);
	ft_flood_fill(game, game->start_i, game->start_j);
	if (game->exit_found == 0 || game->collectibles_found != game->collectibles)
	{
		ft_free_array(game->test_map);
		ft_error("Map has no valid path\n", game);
	}
	ft_free_array(game->test_map);
}
