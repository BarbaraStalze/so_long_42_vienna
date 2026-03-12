/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:09:58 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/12 12:19:06 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "so_long.h"
# include <mlx.h>

int	main()
{
	void	*mlx;
	void	*mlx_game;

	mlx = mlx_init();
	mlx_game = mlx_new_window(mlx, 1920, 1080, "so_long chicken life");
	mlx_loop(mlx);
}
