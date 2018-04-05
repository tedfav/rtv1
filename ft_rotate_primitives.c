#include "rtv1.h"

void	ft_rotate_plan(t_prim *prim)
{
	ft_quater_rot(&(prim->plane.normal), &(prim->plane.normal),
								&(prim->rot_axis), (prim->rot_angle));
	ft_normalize_vector(&(prim->plane.normal));
}

void	ft_rotate_cyl(t_prim *prim)
{
	ft_quater_rot(&(prim->cyl.vec), &(prim->cyl.vec),
								&(prim->rot_axis), (prim->rot_angle));
	ft_normalize_vector(&(prim->cyl.vec));
}

void	ft_rotate_cone(t_prim *prim)
{
	ft_quater_rot(&(prim->cone.vec), &(prim->cone.vec),
								&(prim->rot_axis), (prim->rot_angle));
	ft_normalize_vector(&(prim->cone.vec));
}
