#include "rtv1.h"

void	ft_calculate_vector(t_3dpt *vector, t_3dpt *start, t_3dpt *end)
{
	double distance;

	distance = sqrt(SQR(end->x - start->x) +
		SQR(end->y - start->y) +
		SQR(end->z - start->z));
	if (distance == 0)
		distance = distance + 0.000000000000001;
	vector->x = (end->x - start->x) / distance;
	vector->y = (end->y - start->y) / distance;
	vector->z = (end->z - start->z) / distance;
}

void	ft_sum_vectors(t_3dpt *result, t_3dpt *vec1, t_3dpt *vec2)
{
	result->x = vec1->x + vec2->x;
	result->y = vec1->y + vec2->y;
	result->z = vec1->z + vec2->z;
}

double	ft_calculate_dist(t_3dpt *p1, t_3dpt *p2)
{
	double dist;

	dist = sqrt(SQR(p2->x - p1->x) + SQR(p2->y - p1->y) + SQR(p2->z - p1->z));
	return (dist);
}

void	ft_calculate_vec_end(t_3dpt *end, t_3dpt *start, t_3dpt *vec, double t)
{
	end->x = start->x + vec->x * t;
	end->y = start->y + vec->y * t;
	end->z = start->z + vec->z * t;
}

void	ft_normalize_vector(t_3dpt *source)
{
	double magnitude;

	magnitude = sqrt(SQR(source->x) + SQR(source->y) + SQR(source->z));
	if (magnitude == 0)
		ft_error(ERRDIV);
	source->x = source->x / magnitude;
	source->y = source->y / magnitude;
	source->z = source->z / magnitude;
}
