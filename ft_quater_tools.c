#include "rtv1.h"

void	ft_quater_mult(t_quater *first, t_quater *second, t_quater *result)
{
	result->w = (first->w * second->w - first->x * second->x -
								first->y * second->y - first->z * second->z);
	result->x = (first->w * second->x + first->x * second->w +
								first->y * second->z - first->z * second->y);
	result->y = (first->w * second->y - first->x * second->z +
								first->y * second->w + first->z * second->x);
	result->z = (first->w * second->z + first->x * second->y -
								first->y * second->x + first->z * second->w);
}

void	ft_normalize_quater(t_quater *source)
{
	double magnitude;

	magnitude = sqrt(SQR(source->w) + SQR(source->x) + SQR(source->y)
														+ SQR(source->z));
	if (magnitude == 0)
		ft_error(ERRDIV);
	source->w = source->w / magnitude;
	source->x = source->x / magnitude;
	source->y = source->y / magnitude;
	source->z = source->z / magnitude;
}

void	ft_quater_from_vec(t_quater *result, t_3dpt *source)
{
	result->w = 0;
	result->x = source->x;
	result->y = source->y;
	result->z = source->z;
}
