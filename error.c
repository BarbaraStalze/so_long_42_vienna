/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:14:07 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/23 17:38:39 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free_array(char **a)
{
	int	j;

	j = 0;
	while (a[j])
	{
		free(a[j]);
		j++;
	}
	free(a);
}

void	ft_error(char *message, t_game *game)
{
	char	*error_message;

	error_message = ft_strjoin("Error\n", message);
	if (!error_message)
	{
		perror ("Error\nMalloc failed");
		ft_close_game(game);
	}
	else
	{
		perror (error_message);
		free (error_message);
	}
	ft_close_game(game);
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	if (game->map)
		ft_free_array(game->map);
	ft_close_imgs(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->fd > -1)
		close(game->fd);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_key_hook_esc(int keycode, t_game *game)
{
	if (keycode == 0xff1b)
		mlx_loop_end(game->mlx);
	return (0);
}
