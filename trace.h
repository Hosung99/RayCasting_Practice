#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray     ray(t_point3 orig, t_vec3 dir);
t_point3    ray_at(t_ray *ray, double t);
t_ray	ray_primary(t_camera *camera, double u, double v); //가장 처음 카메라에서 출발한ray
t_color3	ray_color(t_scene *scene);
int		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
int		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
int	in_shadow(t_object *obj, t_ray light_ray, double light_ren);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_color3	phong_lightning(t_scene *scene);
double	hit_sphere(t_object *sp, t_ray *ray, t_hit_record *rec);

#endif
