#include "rtv1.h"

double	ft_resolve_plane(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	double a;
	double b;
	double c;
	double t;

	t = -1;
	a = prim->plane.normal.x;
	b = prim->plane.normal.y;
	c = prim->plane.normal.z;
	prim->plane.d = 0;
	t = -1 * (((a * (origin->x - prim->plane.point.x) +
						b * (origin->y - prim->plane.point.y) +
						c * (origin->z - prim->plane.point.z) + prim->plane.d))
						/ ((a * dir->x + b * dir->y + c * dir->z)
													+ 0.000000000000001));
	return (t);
}
