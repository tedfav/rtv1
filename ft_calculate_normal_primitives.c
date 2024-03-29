#include "rtv1.h"

void	ft_cylinder_normal(t_prim *prim)
{
	double	dist;
	t_3dpt	local_p;
	t_3dpt	global_o;

	dist = SQR(ft_calculate_dist(&(prim->cyl.origin), &(prim->p))) -
														SQR(prim->cyl.radius);
	if (dist >= 0)
		dist = sqrt(dist);
	prim->cyl.o.x = prim->cyl.origin_local.x + dist * prim->cyl.vec_local.x;
	prim->cyl.o.y = prim->cyl.origin_local.y + dist * prim->cyl.vec_local.y;
	prim->cyl.o.z = prim->cyl.origin_local.z + dist * prim->cyl.vec_local.z;
	ft_swap_g_to_l(&local_p, &(prim->p),
									&(prim->g_to_l_move), &(prim->g_to_l_rot));
	if (local_p.y < prim->cyl.origin_local.y)
		prim->cyl.o.y = prim->cyl.origin_local.y +
											dist * -1 * prim->cyl.vec_local.y;
	else if (local_p.y == prim->cyl.origin_local.y)
		ft_set_3dpt(&(prim->cyl.o), prim->cyl.origin_local.x,
							prim->cyl.origin_local.y, prim->cyl.origin_local.z);
	ft_swap_l_to_g(&global_o, &(prim->cyl.o),
									&(prim->l_to_g_move), &(prim->l_to_g_rot));
	ft_set_3dpt(&(prim->cyl.o), global_o.x, global_o.y, global_o.z);
	ft_calculate_vector(&(prim->normal), &(prim->cyl.o), &(prim->p));
}

void	ft_cone_normal(t_prim *prim)
{
	double	dist;
	t_3dpt	local_p;
	t_3dpt	global_o;

	ft_swap_g_to_l(&local_p, &(prim->p), &(prim->g_to_l_move),
														&(prim->g_to_l_rot));
	if (cos(prim->cone.angle) == 0)
		ft_error(ERRDIV);
	dist = ft_calculate_dist(&(prim->cone.origin_local), &local_p)
													/ cos(prim->cone.angle);
	prim->cone.o.x = prim->cone.origin_local.x + dist * prim->cone.vec_local.x;
	prim->cone.o.y = prim->cone.origin_local.y + dist * prim->cone.vec_local.y;
	prim->cone.o.z = prim->cone.origin_local.z + dist * prim->cone.vec_local.z;
	if (local_p.y < prim->cone.origin_local.y)
		prim->cone.o.y = prim->cone.origin_local.y +
											dist * -1 * prim->cone.vec_local.y;
	else if (local_p.y == prim->cone.origin_local.y)
		ft_set_3dpt(&(prim->cone.o), prim->cone.origin_local.x,
						prim->cone.origin_local.y, prim->cone.origin_local.z);
	ft_swap_l_to_g(&global_o, &(prim->cone.o),
									&(prim->l_to_g_move), &(prim->l_to_g_rot));
	ft_set_3dpt(&(prim->cone.o), global_o.x, global_o.y, global_o.z);
	ft_calculate_vector(&(prim->normal), &(prim->cone.o), &(prim->p));
}

void	ft_calculate_normal(t_prim *prim)
{
	if (prim->type == SPHERE)
		ft_calculate_vector(&(prim->normal), &(prim->sphere.origin),
																&(prim->p));
	else if (prim->type == PLANE)
		ft_set_3dpt(&(prim->normal), prim->plane.normal.x,
					prim->plane.normal.y, prim->plane.normal.z);
	else if (prim->type == CYLINDER)
		ft_cylinder_normal(prim);
	else if (prim->type == CONE)
		ft_cone_normal(prim);
}
