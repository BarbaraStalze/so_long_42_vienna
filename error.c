/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:14:07 by bastalze          #+#    #+#             */
/*   Updated: 2026/02/27 12:29:25 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <so_long.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len ++;
	return (len);
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

	if (game->map_pointer)
		ft_free_array(game->map_pointer);
	error_message = ft_truc("Error\n", message);
	if (!error_message)
		error_message = "Error\n";
	perror (error_message);
	free (error_message);
	free (game);
	exit (EXIT_FAILURE);
}
