#include "libgraph.h"

void	ft_create_window(t_winenv *mlxenv, int length, int height, char *title)
{
	mlxenv->length = length;
	mlxenv->height = height;
	mlxenv->win = mlx_new_window(mlxenv->mlxptr, mlxenv->length,
											mlxenv->height, title);
	if (mlxenv->win == NULL)
		ft_error(ERROR);
}
