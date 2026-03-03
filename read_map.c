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
	t_size	j;

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

static void	ft_is_nextline(t_game game, char **new_map, char byte)
{
	if (byte == '\n')
	{
		if (game->map_width != 0 && game->map_width != j)
		{
			ft_free_array(new_map);
			ft_error("Map rows do not have equal length\n", game);
		}
		game->map_width = j;
		game->map_x++;
		game->map_y = 0;
	}
}

static char	**ft_malloc_map_width(char **new_map, t_game game, int i)
{
	int	width;

	if (game->map_width == 0)
		width = game->map_y;
	else
		width = game_map_width;
	new_map[i] = ft_calloc((width + 2) * sizeof(char));
	if (!new_map[i])
	{
		ft_free_array(new_map);
		ft_error("Malloc failed\n", game);
	}
}

static void	ft_array(char byte, t_game game)
{
	char	**new_map;
	int	i;
	int	j;

	new_map = ft_calloc((map_x + 1) * sizeof(char *));
	i = 0;
	while (i <= game->map_x)
	{
		new_map = ft_malloc_map_width(new_map, game, i);
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
	ft_is_nextline(game, new_map, byte);
	new_map[i - 1][j] = byte;
	new_map[i - 1][j + 1] = 0;
	ft_free_array(game->map);
	game->map = new_map;
}

void	ft_read_map(char *ber_file, t_game game)
{
	int		fd;
	char	byte;
	
	fd = open(ber_file, O_RDONLY);
	if (fd == -1)
		ft_error("Open failed\n");
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, byte, sizeof(char));
		if (byte < 0)
			ft_error("Read failed\n", game);
		if (byte == 0)
			break ;
		if (!(byte == '0' || byte == '1' || byte == 'C' || byte == 'E'
			|| byte == 'P' || byte == '\n'))
			ft_error("Wrong character on map\n", game);
		ft_array(byte, game);
	}
	close(fd);
}
