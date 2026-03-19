/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:35:06 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/19 12:17:06 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_build_array(t_game *game)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (1)
	{
		game->map[i] = ft_calloc(game->map_width + 1, sizeof(char));
		if (!game->map[i])
			ft_error("Malloc failed\n", game);
		line = get_next_line(game->fd);
		if (!line)
			break ;
		j = 0;
		while (line[j] != '\n')
		{
			game->map[i][j] = line[j];
			j++;
		}
		game->map[i++][j] = 0;
		free(line);
	}
	if (errno > 0)
		ft_error("Malloc failed\n", game);
	game->map[i] = NULL;
}

static void	ft_map_size(t_game *game)
{
	char	*line;

	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		if (game->map_height == 0)
			game->map_width = ft_strlen(line) - 1;
		else if ((int)(ft_strlen(line)) != game->map_width + 1)
			ft_error("Rows are not equally sized\n", game);
		free(line);
		game->map_height++;
	}
	if (errno > 0)
		ft_error("Malloc or read failed\n", game);
}

void	ft_parse_map(char *ber_file, t_game *game)
{
	game->fd = open(ber_file, O_RDONLY);
	if (game->fd == -1)
		ft_error("Open failed. Make sure file exists.\n", game);
	ft_map_size(game);
	close(game->fd);
	game->fd = open(ber_file, O_RDONLY);
	if (game->fd == -1)
		ft_error("Open failed. Make sure file exists.\n", game);
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		ft_error("Malloc failed\n", game);
	ft_build_array(game);
	close(game->fd);
}
