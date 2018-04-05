#include "rtv1.h"

double	ft_calculate_dot(t_3dpt *vec1, t_3dpt *vec2)
{
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
}

void	ft_cross_product(t_3dpt *result, t_3dpt *vec1, t_3dpt *vec2)
{
	ft_set_3dpt(result, vec1->y * vec2->z - vec1->z * vec2->y,
									vec1->z * vec2->x - vec1->x * vec2->z,
									vec1->x * vec2->y - vec1->y * vec2->x);
}

double	ft_degree_to_rad(double degree)
{
	return (degree / (180 / M_PI));
}
