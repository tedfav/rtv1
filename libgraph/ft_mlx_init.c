#include "libgraph.h"

void	ft_mlx_init(t_winenv *mlxenv)
{
	mlxenv->mlxptr = mlx_init();
	if (mlxenv->mlxptr == NULL)
		ft_error(ERROR);
}
