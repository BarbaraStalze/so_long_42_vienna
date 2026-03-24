/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:54:17 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/23 17:22:28 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_move_player(t_game *game, int i, int j, char sp)
{
	if (game->map[i][j] == '0' || game->map[i][j] == 'C')
	{
		if (game->map[i][j] == 'C')
		{
			game->collectibles--;
			if (game->collectibles == 0)
				game->map[game->exit_i][game->exit_j] = 'e';
		}
		game->move = 1;
		if (sp == 'P')
			game->map[i][j] = 'P';
		else
			game->map[i][j] = 'p';
	}
	else if (game->map[i][j] == 'e')
	{
		write(1, "Moves:", 7);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		write(1, "\n", 1);
		mlx_loop_end(game->mlx);
	}
	if (game->move == 1)
		game->map[game->start_i][game->start_j] = '0';
}

static void	ft_reset_player_position(int keycode, t_game *game)
{
	if (game->move == 1)
	{
		if (keycode == 0xff52)
			game->start_i--;
		else if (keycode == 0xff53)
			game->start_j++;
		else if (keycode == 0xff54)
			game->start_i++;
		else if (keycode == 0xff51)
			game->start_j--;
		write(1, "Moves:", 7);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		write(1, "\n", 1);
	}
}

static int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 0xff1b)
		mlx_loop_end(game->mlx);
	else if (keycode == 0xff52)
	{
		ft_move_player(game, game->start_i - 1, game->start_j,
			game->map[game->start_i][game->start_j]);
	}
	else if (keycode == 0xff53)
		ft_move_player(game, game->start_i, game->start_j + 1, 'P');
	else if (keycode == 0xff54)
	{
		ft_move_player(game, game->start_i + 1, game->start_j,
			game->map[game->start_i][game->start_j]);
	}
	else if (keycode == 0xff51)
		ft_move_player(game, game->start_i, game->start_j - 1, 'p');
	ft_reset_player_position(keycode, game);
	game->move = 0;
	return (0);
}

void	ft_moves(t_game *game)
{
	mlx_hook(game->window, 17, 0, ft_close_game, game);
	mlx_hook(game->window, 2, 1L << 0, ft_key_hook, game);
	mlx_loop_hook(game->mlx, ft_put_image, game);
}
