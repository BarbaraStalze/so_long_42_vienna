/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:02:30 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/16 15:30:53 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	**ft_copy_map(t_game *game, char **test_map)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		test_map[i] = calloc(game->map_width + 1, sizeof(char));
		if (!test_map[i])
		{
			ft_free_array(test_map);
			ft_error("Malloc failed\n", game);
		}
		while (game->map[i][j])
		{
			test_map[i][j] = game->map[i][j];
			if (test_map[i][j] == 'P')
			{
				game->start_i = i;
				game->start_j = j;
			}
			j++;
		}
		test_map[i][j] = 0;
		i++;
	}
	test_map[i] = NULL;
	return (test_map);
}

static char	**ft_flood_fill(char **test_map, int i, int j, int *collectibles)
{
	if (test_map[i][j] == '1' || (test_map[i][j] == 'E' && *collectibles != 0))
		return (test_map);
	if (test_map[i][j] == 'C')
		(*collectibles)--;
	test_map[i][j] = '1';
	ft_flood_fill(test_map, i - 1, j, collectibles);
	ft_flood_fill(test_map, i, j + 1, collectibles);
	ft_flood_fill(test_map, i + 1, j, collectibles);
	ft_flood_fill(test_map, i, j - 1, collectibles);
	return (test_map);
}

static void	ft_all_flooded(char **test_map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (test_map[i])
	{
		j = 0;
		while (test_map[i][j])
		{
			if (test_map[i][j] == 'C' || test_map[i][j] == 'E')
			{
				ft_free_array(test_map);
				ft_error("Map has no valid path\n", game);
			}
			j++;
		}
		i++;
	}
}

void	ft_valid_path(t_game *game)
{
	char			**test_map;
	int				collectibles;

	test_map = malloc((game->map_height + 1) * sizeof(char *));
	if (!test_map)
		ft_error("Malloc failed\n", game);
	test_map = ft_copy_map(game, test_map);
	collectibles = game->collectibles;
	test_map = ft_flood_fill(test_map, game->start_i, game->start_j, &collectibles);
	ft_all_flooded(test_map, game);
	ft_free_array(test_map);
}
