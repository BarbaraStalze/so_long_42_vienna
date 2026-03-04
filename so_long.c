/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:14:43 by bastalze          #+#    #+#             */
/*   Updated: 2026/02/26 19:41:59 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	int		check;
	static t_game	game;

	if (argc != 2)
	{
		ft_error("Please enter a valid .ber file name as an argument. 
			For example: \"map.ber\"", game);
	}
	ft_file_type(arg[1], &game);
	ft_read_map(arg[1], &game);
	ft_is_map_vaild(&game);
}
