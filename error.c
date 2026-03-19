/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:14:07 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/19 15:19:08 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free_array(char **a)
{
	int	j;

	if (a)
	{
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
}

static char	*ft_trunc(char *error, char *message)
{
	char	*result;
	size_t	len_m;
	size_t	len_e;
	size_t	i;

	len_m = ft_strlen(message);
	len_e = ft_strlen(error);
	result = malloc(len_e + len_m + 1);
	if (!result)
		return (0);
	i = 0;
	while (error[i])
	{
		result[i] = error[i];
		i++;
	}
	i = 0;
	while (message[i])
	{
		result[i + 6] = message[i];
		i++;
	}
	result[i + 6] = 0;
	return (result);
}

void	ft_error(char *message, t_game *game)
{
	char	*error_message;

	if (game->map)
		ft_free_array(game->map);
	if (game->fd > 0)
		close(game->fd);
	ft_close_imgs(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->window_end)
		mlx_destroy_window(game->mlx, game->window_end);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	error_message = ft_trunc("Error\n", message);
	if (!error_message)
		perror ("Error\nMalloc failed\nFunction");
	error_message = ft_trunc(error_message, "Function");
	if (!error_message)
		perror ("Error\nMalloc failed\nFunction");
	else
	{
		perror (error_message);
		free (error_message);
	}
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	if (game->map)
		ft_free_array(game->map);
	if (game->fd > 0)
		close(game->fd);
	ft_close_imgs(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->won == 0)
		exit(EXIT_SUCCESS);
	return (0);
}

int	ft_key_hook_esc(int keycode, t_game *game)
{
	if (keycode == 0xff1b)
		ft_close_game(game);
	return (0);
}
