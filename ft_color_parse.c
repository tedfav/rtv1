#include "rtv1.h"

void	ft_set_color(t_color *color, int r, int g, int b)
{
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		ft_error(ERR_COLOR_RANGE);
	color->red = (unsigned char)r;
	color->green = (unsigned char)g;
	color->blue = (unsigned char)b;
	color->alpha = 0;
}
