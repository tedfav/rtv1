#include "rtv1.h"

void	ft_parse_vector(char *str, t_3dpt *vec)
{
	char **tmp;

	tmp = ft_strsplit(str, ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "vec") == 0)
		ft_error_cyl();
	ft_set_3dpt(vec, (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_normalize_vector(vec);
	ft_free_tab(tmp);
}

void	ft_plane_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, PLANE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 6)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_plane();
	ft_set_3dpt(&(last->plane.point), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	tmp = ft_strsplit(tab[2], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "normal") == 0)
		ft_error_plane();
	ft_set_3dpt(&(last->plane.normal), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	ft_parse_color(tab[3], &(last->color2), &ft_error_plane);
	ft_parsing_mov(tab[4], tab[5], last, &ft_error_plane);
}

void	ft_cylinder_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, CYLINDER);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 7)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_cyl();
	ft_set_3dpt(&(last->cyl.origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	ft_parse_vector(tab[2], &(last->cyl.vec));
	tmp = ft_strsplit(tab[3], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "radius") == 0)
		ft_error_cyl();
	if ((last->cyl.radius = ft_atoi(tmp[1])) <= 0)
		ft_error("Radius can not be Null or negative");
	ft_free_tab(tmp);
	ft_parse_color(tab[4], &(last->color2), &ft_error_cyl);
	ft_parsing_mov(tab[5], tab[6], last, &ft_error_cyl);
}

void	ft_cone_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, CONE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 7)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_cone();
	ft_set_3dpt(&(last->cone.origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	ft_parse_vector(tab[2], &(last->cone.vec));
	tmp = ft_strsplit(tab[3], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "angle") == 0)
		ft_error_cone();
	last->cone.angle = ft_degree_to_rad(ft_atoi(tmp[1]));
	ft_free_tab(tmp);
	ft_parse_color(tab[4], &(last->color2), &ft_error_cone);
	ft_parsing_mov(tab[5], tab[6], last, &ft_error_cone);
}

void	ft_sphere_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, SPHERE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 6)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_sphere();
	ft_set_3dpt(&(last->sphere.origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	tmp = ft_strsplit(tab[2], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "radius") == 0)
		ft_error_sphere();
	last->sphere.radius = ft_atoi(tmp[1]);
	ft_free_tab(tmp);
	ft_parse_color(tab[3], &(last->color2), &ft_error_sphere);
	ft_parsing_mov(tab[4], tab[5], last, &ft_error_sphere);
}
