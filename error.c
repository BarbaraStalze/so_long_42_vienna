/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:14:07 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/13 18:23:52 by bastalze         ###   ########.fr       */
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
	size_t	i;

	len_m = ft_strlen(message);
	result = malloc(6 + len_m + 1);
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
	error_message = ft_trunc("Error\n", message);
	if (!error_message)
	{
		error_message = "Error\nMalloc failed";
		perror (error_message);
	}
	else
	{
		perror (error_message);
		free (error_message);
	}
	exit (EXIT_FAILURE);
}
