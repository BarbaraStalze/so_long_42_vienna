#include "so_long.h"

void	ft_file_type(char *filename, t_game game)
{
	char	*dot;
	int	ber;

	dot = strrch(filename, ".");
	if (!dot || dot == filename)
        {
                ft_error("Please enter a valid .ber file name as an argument.
                        For example: \"map.ber\"", game);
        }
	ber = strncmp(dot, ".ber", 5);
	if (ber != 0)
        {
                ft_error("Please enter a valid .ber file name as an argument.
                        For example: \"map.ber\"", game);
        }
}
