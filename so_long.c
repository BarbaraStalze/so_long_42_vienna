/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:14:43 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/23 17:41:32 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_start_window(t_game *game)
{
	int	sizex;
	int	sizey;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		errno = EINVAL;
		ft_error("Initiation of display failed", game);
	}
	mlx_get_screen_size(game->mlx, &sizex, &sizey);
	game->window = mlx_new_window(game->mlx, game->map_width * 32,
			game->map_height * 32, "THE SECRET LIFE OF A CHICKEN");
	if (!game->window)
	{
		errno = EINVAL;
		ft_error("Creation of window failed", game);
	}
	game->img.size = 32;
	ft_open_images(game);
	ft_put_image(game);
}

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
	{
		errno = EINVAL;
		ft_error("Please enter a valid .ber file name as an argument. \
			For example: \"map.ber\"", &game);
	}
	ft_file_type(argv[1], &game);
	ft_parse_map(argv[1], &game);
	ft_is_map_valid(&game);
	ft_start_window(&game);
	ft_moves(&game);
	mlx_loop(game.mlx);
	ft_close_game(&game);
}
