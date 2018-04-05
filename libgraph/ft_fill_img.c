#include "libgraph.h"

void	ft_fill_img(t_mlximg img, int x, int y, int color)
{
	int		opp;
	int		i;

	if ((x >= 0) && (y >= 0) && (x < img.length)
								&& (y < img.height))
	{
		opp = img.bpp / 8;
		i = (x * opp) + (y * img.s_l);
		img.str[i] = color;
		img.str[i + 1] = color >> 8;
		img.str[i + 2] = color >> 16;
		img.str[i + 3] = 0;
	}
}
