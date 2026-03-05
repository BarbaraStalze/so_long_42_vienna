#include "so_long.c"

static char	**ft_copy_map(t_game game, char **test_map, t_path *path_params)
{
	int	i;
	int	j;

	test_map = malloc((game->map_h + 1) * sizeof(char *));
	if (!test_map)
		ft_error("Malloc failed\n", game);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			test_map[i][j] = game->map[i][j];
			if (test_map[i][j] == 'P')
			{
				path_params->start_h = i;
				path_params->start_w = j;
			}
			j++;
		}
		test_map[i][j] = 0;
		i++;
	}
	test_map[i] = NULL;
	return (test_map);
}

static void	ft_flood_fill(char ***test_map, int i, int j, int *collectibles);
{
	if (*test_map[i][j] == '1' || (*test_map[i][j] == 'E' && *collectibles != 0))
		return ;
	if (*test_map[i][j] == 'C')
		*collectibles--;
	*test_map[i][j] = '1';
	ft_flood_fill(test_map, i - 1, j, collectibles);
	ft_flood_fill(test_map, i, j + 1, collectibles);
	ft_flood_fill(test_map, i + 1, j, collectibles);
	ft_flood_fill(test_map, i, j - 1, collectibles);
	return ;
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
				ft_error("Map has no valid path\n", game);
			j++;
		}
		i++;
	}
}

void	ft_valid_path(t_game *game)
{
	char		**test_map;
	static t_path	path_params;
	int		collectibles;

	test_map = ft_copy_map(game, test_map, &path_params);
	collectibles = game->collectibles;
	ft_flood_fill(&test_map, path_params.start_h, path_params.start_w, &collectibles);
	ft_all_flooded(test_map, game);
	ft_free_array(test_map);
}
