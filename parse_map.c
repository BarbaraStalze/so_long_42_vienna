/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:35:06 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/23 18:01:55 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_file_type(char *filename, t_game *game)
{
	char	*dot;
	int		ber;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
	{
		errno = EINVAL;
		ft_error("Please enter a valid .ber file name as an argument. \
For example: \"map.ber\"", game);
	}
	ber = ft_strncmp(dot, ".ber", 5);
	if (ber != 0)
	{
		errno = EINVAL;
		ft_error("Please enter a valid .ber file name as an argument. \
For example: \"map.ber\"", game);
	}
}

static void	ft_build_array(t_game *game)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		game->map[i] = ft_calloc(game->map_width + 1, sizeof(char));
		if (!game->map[i])
			ft_error("Malloc failed", game);
		j = 0;
		while (line[j] != '\n')
		{
			game->map[i][j] = line[j];
			j++;
		}
		game->map[i++][j] = 0;
		free(line);
	}
	if (errno)
		ft_error("Get_next_line failed", game);
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
		{
			free(line);
			errno = EINVAL;
			ft_error("Rows are not equally sized", game);
		}
		free(line);
		game->map_height++;
	}
	if (errno)
		ft_error("Malloc or read failed", game);
}

void	ft_parse_map(char *ber_file, t_game *game)
{
	game->fd = open(ber_file, O_RDONLY);
	if (game->fd == -1)
		ft_error("Open failed. Make sure file exists", game);
	ft_map_size(game);
	close(game->fd);
	game->fd = open(ber_file, O_RDONLY);
	if (game->fd == -1)
		ft_error("Open failed. Make sure file exists", game);
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		ft_error("Malloc failed", game);
	ft_build_array(game);
	close(game->fd);
}
