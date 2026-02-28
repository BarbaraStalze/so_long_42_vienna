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

char	**ft_free_array(char **a)
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
	return (0);
}

void	ft_array(char byte, t_game game)
{
	char	**new_map;

	
}

int	read_map(char *ber_file, t_game game)
{
	int		fd;
	char	byte;
	
	fd = open(ber_file, O_RDONLY);
	if (fd == -1)
		ft_error("Open failed\n");
	byte = 1;
	game->map_pointer = 
	while (byte > 0)
	{
		byte = read(fd, byte, sizeof(char));
		if (byte < 0)
			ft_error("Read failed\n", game);
		if (!(byte == '0' || byte == '1' || byte == 'C' || byte == 'E'
			|| byte == 'P' || byte == '\n'))
			ft_error("Wrong character on map\n", game);
		ft_array(byte, game);
	}
	if ()
}
