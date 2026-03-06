#include "so_long.h"

void	ft_file_type(char *filename, t_game *game)
{
	char	*dot;
	int	ber;

	dot = strrch(filename, ".");
	if (!dot || dot == filename)
        {
                ft_error("Please enter a valid .ber file name as an argument.
                        For example: \"map.ber\"\n", game);
        }
	ber = strncmp(dot, ".ber", 5);
	if (ber != 0)
        {
                ft_error("Please enter a valid .ber file name as an argument.
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
		if (game->map[i][0] != '1' || game->map[i][game->map_w] != '1')
			ft_error("Map is not surrounded by walls\n", game);
		if (i == 0 || i == game->map_h)
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

static void	ft_features_right(t_game *game)
{
	int	i;
	int	j;
	int	exit;
	int	start;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == "E")
				exit++;
			else if (game->map[i][j] == "P")
				start++;
			 else if (game->map[i][j] == "C")
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

	ft_surrunded_by_walls(game);
	ft_features_right(game);
	ft_valid_path(game);
}
