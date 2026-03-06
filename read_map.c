/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:04:27 by bastalze          #+#    #+#             */
/*   Updated: 2026/02/27 14:07:38 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free_array(char **a)
{
	int	j;

	j = 0;
	while (a[j])
		j++;
	j--;
	while (j >= 0)
	{
		free(a[j]);
		a[j] = 0;
		j--;
	}
	free(a);
	a = 0;
}

static void	ft_is_nextline(t_game *game, char **new_map, char buffer, int j)
{
	if (buffer == '\n')
	{
		if (game->map_width != 0 && game->map_width != j)
		{
			ft_free_array(new_map);
			ft_error("Map rows do not have equal length\n", game);
		}
		game->map_width = j;
		game->map_h++;
		game->map_w = 0;
	}
}

static char	*ft_malloc_map_width(char **new_map, t_game *game, int i)
{
	int	width;

	if (game->map_width == 0)
		width = game->map_w;
	else
		width = game->map_width;
	new_map[i] = calloc(1, (width + 2) * sizeof(char));
	if (!new_map[i])
	{
		ft_free_array(new_map);
		ft_error("Malloc failed\n", game);
	}
	return (new_map[i]);
}

static void	ft_array(char buffer, t_game *game)
{
	char	**new_map;
	int	i;
	int	j;

	new_map = calloc(1, (game->map_h + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i <= game->map_h)
	{
		new_map[i] = ft_malloc_map_width(new_map, game, i);
		new_map[i] = game->map[i];
		j = 0;
		while (game->map[i][j])
		{
			new_map[i][j] = game->map[i][j];
			j++;
		}
		new_map[i][j] = 0;
		i++;
	}
	new_map[i] = NULL;
	ft_is_nextline(game, new_map, buffer, j);
	new_map[i - 1][j] = buffer;
	new_map[i - 1][j + 1] = 0;
	ft_free_array(game->map);
	game->map = new_map;
}

void	ft_read_map(char *ber_file, t_game *game)
{
	int		fd;
	int		check;
	char	buffer[1];

	
	fd = open(ber_file, O_RDONLY);
	if (fd == -1)
		ft_error("Open failed. Make sure file exists.\n", game);
	check = 1;
	while (check > 0)
	{
		check = read(fd, buffer, sizeof(char));
		if (check < 0)
			ft_error("Read failed\n", game);
		if (check == 0)
			break ;
		if (!(*buffer == '0' || *buffer == '1' || *buffer == 'C' || *buffer == 'E'
			|| *buffer == 'P' || *buffer == '\n'))
			ft_error("Wrong character on map\n", game);
		ft_array(*buffer, game);
	}
	close(fd);
}
