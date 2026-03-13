/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:54:17 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/13 18:29:57 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_close_game(game)
{
	if (game->map)
		ft_free_array(game->map);
	if (game->fd > 0)
		close(game->fd);
	ft_close_imgs(game);
	exit (EXIT_FAILURE);
}

void	ft_moves(t_game *game)
{
	close = ft_close_game(game);
	mlx_hook(game->window, 17, 0, ft_close_game, game);
}
